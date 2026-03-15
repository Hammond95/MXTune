#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

GREEN='\033[0;32m'
NC='\033[0m'
echo_step() { echo -e "${GREEN}==> $1${NC}"; }

# ---------------------------------------------------------------------------
# 1. Homebrew dependencies (includes aubio, soundtouch, rubberband)
# ---------------------------------------------------------------------------
echo_step "Checking Homebrew dependencies..."
if ! command -v brew &>/dev/null; then
    echo "Homebrew not found. Install it from https://brew.sh and re-run this script."
    exit 1
fi

for pkg in pkg-config cmake fftw aubio sound-touch rubberband; do
    if ! brew list "$pkg" &>/dev/null; then
        echo_step "Installing $pkg via Homebrew..."
        brew install "$pkg"
    fi
done

# ---------------------------------------------------------------------------
# 2. JUCE — download, extract, run Projucer CLI to regenerate JuceLibraryCode
# ---------------------------------------------------------------------------
mkdir -p "$SCRIPT_DIR/third_party"
pushd "$SCRIPT_DIR/third_party"
mkdir -p downloads

if [ ! -f "downloads/juce-7.0.5-osx.zip" ]; then
    echo_step "Downloading JUCE 7.0.5..."
    curl -fL "https://github.com/juce-framework/JUCE/releases/download/7.0.5/juce-7.0.5-osx.zip" \
         -o "downloads/juce-7.0.5-osx.zip"
fi

if [ ! -d "JUCE" ]; then
    echo_step "Extracting JUCE..."
    unzip -q downloads/juce-7.0.5-osx.zip
fi

PROJUCER="$(pwd)/JUCE/Projucer.app/Contents/MacOS/Projucer"
echo_step "Configuring JUCE module paths..."
"$PROJUCER" --set-global-search-path osx defaultJuceModulePath "$(pwd)/JUCE/modules"
echo_step "Regenerating JuceLibraryCode..."
"$PROJUCER" --resave "$SCRIPT_DIR/JUCE/mx_tune.jucer"

popd  # back to SCRIPT_DIR

# ---------------------------------------------------------------------------
# Patch JUCE for macOS 15.0+ compatibility: CGWindowListCreateImage removed
# ---------------------------------------------------------------------------
echo_step "Patching JUCE for macOS 15.0+ compatibility..."
WINDOWING_MM="$SCRIPT_DIR/JUCE/JuceLibraryCode/modules/juce_gui_basics/native/juce_mac_Windowing.mm"
python3 << PYEOF
import pathlib
p = pathlib.Path('${WINDOWING_MM}')
if not p.exists():
    print('WARNING: juce_mac_Windowing.mm not found, skipping patch')
    exit(0)
t = p.read_text()
OLD = '    JUCE_AUTORELEASEPOOL\n    {\n        CGImageRef screenShot = CGWindowListCreateImage'
if OLD not in t:
    print('INFO: juce_mac_Windowing.mm already patched or pattern not found')
    exit(0)
NEW = '    JUCE_AUTORELEASEPOOL\n    {\n       #if MAC_OS_X_VERSION_MAX_ALLOWED >= 150000\n        juce::ignoreUnused (nsWindow);\n        return Image();\n       #else\n        CGImageRef screenShot = CGWindowListCreateImage'
END_OLD = '        CGImageRelease (screenShot);\n\n        return result;\n    }\n}'
END_NEW = '        CGImageRelease (screenShot);\n\n        return result;\n       #endif\n    }\n}'
t = t.replace(OLD, NEW, 1)
t = t.replace(END_OLD, END_NEW, 1)
p.write_text(t)
print('Patched: CGWindowListCreateImage guarded for macOS 15.0+')
PYEOF

# ---------------------------------------------------------------------------
# 3. VST3 SDK
# ---------------------------------------------------------------------------
if [ ! -d "$SCRIPT_DIR/VST3_SDK" ]; then
    echo_step "Cloning VST3 SDK..."
    git clone --recursive https://github.com/steinbergmedia/vst3sdk.git "$SCRIPT_DIR/VST3_SDK"
fi

echo_step "Checking out VST3 SDK v3.7.1_build_50..."
pushd "$SCRIPT_DIR/VST3_SDK"
git checkout v3.7.1_build_50
git submodule update --recursive
popd

# ---------------------------------------------------------------------------
# 4. Build MXTune
# ---------------------------------------------------------------------------
echo_step "Building MXTune..."
HOMEBREW_PREFIX="$(brew --prefix)"
export PKG_CONFIG_PATH="${HOMEBREW_PREFIX}/lib/pkgconfig:${PKG_CONFIG_PATH:-}"

mkdir -p "$SCRIPT_DIR/build-cmake"
pushd "$SCRIPT_DIR/build-cmake"
cmake .. -DCMAKE_PREFIX_PATH="$HOMEBREW_PREFIX"
make -j"$(sysctl -n hw.logicalcpu)"
popd

# ---------------------------------------------------------------------------
# 5. Install VST3 plugin bundle
# VST3 plugins on macOS must be bundles (directories), not flat .dylib files.
# The plugin only exports GetPluginFactory (VST3); VST2 is not supported by
# JUCE 7's open-source build.
# ---------------------------------------------------------------------------
VST3_BUNDLE="/Library/Audio/Plug-Ins/VST3/mx_tune.vst3"
echo_step "Installing VST3 bundle to $VST3_BUNDLE ..."

sudo rm -rf "$VST3_BUNDLE"
sudo mkdir -p "$VST3_BUNDLE/Contents/MacOS"

# Copy the dylib as the bundle executable (no extension, named after the plugin)
sudo cp "$SCRIPT_DIR/build-cmake/libmx_tune.dylib" "$VST3_BUNDLE/Contents/MacOS/mx_tune"

# Write the required Info.plist so macOS and hosts recognise it as a valid bundle
sudo tee "$VST3_BUNDLE/Contents/Info.plist" > /dev/null << 'PLIST'
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>CFBundleDevelopmentRegion</key>
    <string>English</string>
    <key>CFBundleExecutable</key>
    <string>mx_tune</string>
    <key>CFBundleIdentifier</key>
    <string>com.hammond95.mxtune</string>
    <key>CFBundleInfoDictionaryVersion</key>
    <string>6.0</string>
    <key>CFBundleName</key>
    <string>mx_tune</string>
    <key>CFBundlePackageType</key>
    <string>BNDL</string>
    <key>CFBundleShortVersionString</key>
    <string>1.0</string>
    <key>CFBundleVersion</key>
    <string>1.0</string>
    <key>CFBundleSignature</key>
    <string>hmmr</string>
    <key>CSResourcesFileMapped</key>
    <string>yes</string>
</dict>
</plist>
PLIST

printf "BNDLhmmr" | sudo tee "$VST3_BUNDLE/Contents/PkgInfo" > /dev/null
sudo chown -R root:wheel "$VST3_BUNDLE"
sudo codesign --force --sign - "$VST3_BUNDLE"
sudo chmod -R 755 "$VST3_BUNDLE"

echo_step "Done! Plugin installed to $VST3_BUNDLE"
echo_step "In Ableton: Preferences > Plug-Ins > enable VST3, rescan, look for 'mx_tune'"
