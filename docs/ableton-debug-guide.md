# Debugging MXTune Installation in Ableton Live (macOS)

This guide explains how to diagnose why a locally built VST3 plugin does not appear in Ableton Live after installation.

---

## Expected Install Location

The plugin must be installed as a proper macOS bundle:

```
/Library/Audio/Plug-Ins/VST3/mx_tune.vst3/
  Contents/
    MacOS/
      mx_tune          ← binary (no extension)
    Info.plist
    PkgInfo
    _CodeSignature/
      CodeResources    ← must be world-readable
```

Run `./build_macos.sh` to build and install automatically.

---

## Step 1: Verify the Bundle Structure

```bash
ls -laR /Library/Audio/Plug-Ins/VST3/mx_tune.vst3/
```

Check that:
- `Contents/MacOS/mx_tune` exists and is executable
- `Contents/Info.plist` exists
- `Contents/PkgInfo` exists
- `Contents/_CodeSignature/CodeResources` exists and is readable by all users (`-rw-r--r--` or `-rwxr-xr-x`)

If `_CodeSignature/CodeResources` is missing or has permissions like `-rw-r-----`, re-sign and fix permissions:

```bash
sudo codesign --force --sign - /Library/Audio/Plug-Ins/VST3/mx_tune.vst3
sudo chmod -R 755 /Library/Audio/Plug-Ins/VST3/mx_tune.vst3
```

---

## Step 2: Verify the Binary

Check the binary loads correctly and exports the required VST3 entry point:

```bash
# Check architecture
file /Library/Audio/Plug-Ins/VST3/mx_tune.vst3/Contents/MacOS/mx_tune

# Check VST3 entry points are exported
nm -gU /Library/Audio/Plug-Ins/VST3/mx_tune.vst3/Contents/MacOS/mx_tune | grep -E "GetPluginFactory|bundleEntry|bundleExit"
```

Expected output:
```
_GetPluginFactory
_bundleEntry
_bundleExit
```

Test that the binary actually loads without crashing:

```bash
python3 -c "
import ctypes
lib = ctypes.CDLL('/Library/Audio/Plug-Ins/VST3/mx_tune.vst3/Contents/MacOS/mx_tune')
print('Loaded OK')
result = lib.GetPluginFactory()
print('GetPluginFactory returned:', result)
"
```

---

## Step 3: Verify the Code Signature

```bash
codesign -dv /Library/Audio/Plug-Ins/VST3/mx_tune.vst3
```

Key fields to check:
- `Identifier` should be `com.hammond95.mxtune` (not `libmx_tune.dylib`)
- `Info.plist entries` should be a non-zero number
- `Sealed Resources` should not say `none`

If `Identifier` shows the dylib name, the bundle was signed before `Info.plist` was in place. Reinstall from scratch with `./build_macos.sh`.

---

## Step 4: Watch the Ableton Plugin Scanner in Real Time

With Ableton closed, run this in a terminal:

```bash
log stream --predicate 'process == "Ableton Plugin Scanner"' --level debug 2>/dev/null
```

Then open Ableton and trigger a rescan (**Preferences > Plug-Ins > Rescan**). Watch for lines mentioning `mx_tune`. Common errors and their causes:

| Log message | Cause | Fix |
|---|---|---|
| `failed to fetch .../CodeResources error=-10` | `_CodeSignature/CodeResources` missing or not readable | Run `codesign` then `chmod -R 755` on the bundle |
| `invalid resource directory` / `MacOS error: -67023` | CodeResources exists but is invalid or was modified after signing | Re-sign the bundle, then chmod |
| `Identifier=libmx_tune.dylib` in codesign output | Binary was signed before Info.plist was written | Re-run full install: `./build_macos.sh` |
| No `mx_tune` lines appear at all | VST3 folder not enabled in Ableton preferences | See Step 5 |

---

## Step 5: Check Ableton Preferences

In Ableton: **Preferences > Plug-Ins**

- Ensure **Use VST3 Plug-In System Folders** is enabled
- The system VST3 folder on macOS is `/Library/Audio/Plug-Ins/VST3`
- After any change, click **Rescan**

Ableton also caches scan results. If the plugin was previously rejected, force a full rescan by holding **Alt** while clicking Rescan (behaviour may vary by Ableton version).

---

## Step 6: Check Ableton Logs

Ableton writes detailed logs to:

```
~/Library/Preferences/Ableton/Live <version>/Log.txt
```

Search for plugin-related output:

```bash
grep -i "plugin\|scan\|vst3" ~/Library/Preferences/Ableton/Live\ 11.*/Log.txt | grep -v "audio time\|Midi\|Parameter\|EventBuff\|AudioBuffer"
```

---

## Common Mistakes

- **Installing as a flat `.dylib`**: DAW hosts require a bundle directory. A plain `.dylib` file will never be recognised as a VST3 plugin.
- **Running `chmod` before `codesign`**: `codesign` creates new files (`_CodeSignature/CodeResources`) that inherit default root permissions and will not be world-readable. Always run `chmod -R 755` _after_ `codesign`.
- **Editing JUCE source files directly**: `build_macos.sh` runs `Projucer --resave` which regenerates the entire `JuceLibraryCode/modules/` directory, overwriting any manual edits. Patches must be applied after the Projucer step (as done in `build_macos.sh`).
- **VST2 vs VST3**: JUCE 7 open-source builds do not support VST2. The plugin only exports `_GetPluginFactory` (VST3). Do not attempt to install it as a `.vst` file.
