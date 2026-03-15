# MXTune — Changes from Upstream

This document describes the changes made to the original MXTune codebase in this fork.

---

## Build System

### `CMakeLists.txt`

- **SYSTEM includes for JUCE headers**: Changed `include_directories(JUCE/JuceLibraryCode ...)` to `include_directories(SYSTEM ...)` so Clang suppresses warnings from JUCE headers when they are transitively included by project source files.
- **Separated JUCE library sources**: Introduced `JUCE_PLUGIN_CLIENT_SRCS` as a separate source list for JUCE plugin client wrappers. Both `JUCE_LIB_SRCS` and `JUCE_PLUGIN_CLIENT_SRCS` are compiled with `-w` (all warnings suppressed) via `set_source_files_properties`, keeping warnings clean for project sources only.
- **Fixed Apple linker options**: Changed the macOS framework and library flags from a single space-separated string to individual `list(APPEND LINK_OPTIONS ...)` elements. The previous approach caused the linker driver to misparse arguments (e.g. treating `Accelerate` as a filename instead of a framework name).

### `build_macos.sh`

- **macOS 15.0+ patch**: Added a Python script that runs after `Projucer --resave` to patch `juce_mac_Windowing.mm`, guarding the removed `CGWindowListCreateImage` API with `#if MAC_OS_X_VERSION_MAX_ALLOWED >= 150000`. This is necessary because Projucer regenerates the entire `JuceLibraryCode/modules/` directory on every run, overwriting any direct edits.
- **VST3 bundle installation**: Replaced the flat `.dylib` install (which DAW hosts cannot load) with a proper macOS VST3 bundle at `/Library/Audio/Plug-Ins/VST3/mx_tune.vst3/`, including:
  - `Contents/MacOS/mx_tune` — the plugin binary
  - `Contents/Info.plist` — bundle metadata
  - `Contents/PkgInfo` — required by macOS bundle discovery
- **Correct install permissions and signing**: Added `chown`, `codesign`, and `chmod` steps (in that order) after bundle creation to ensure the `_CodeSignature/CodeResources` file is world-readable after signing.

---

## Source Files

### `JUCE/Source/PluginProcessor.cpp`

- **JUCE 7 API fix**: `AudioPlayHead::PositionInfo::getTimeSigDenominator()` was removed in JUCE 7. Replaced with `getTimeSignature()->denominator`.
- **Unused parameter warnings**: Suppressed via `/*param*/` naming convention on `setCurrentProgram`, `getProgramName`, `changeProgramName`, `prepareToPlay`, and `parameterGestureChanged`.
- **Sign compare fix**: Added explicit cast to `std::int32_t` when comparing `_misc_param.length()`.

### `JUCE/Source/PluginGui.cpp`

- Replaced `sprintf` with `snprintf` (with correct buffer size) to fix buffer overflow warnings.
- Removed unused variable from modal dialog return value.
- Suppressed unused parameter on `mouseWheelMove`.

### `JUCE/Source/KeyDetectGui.cpp`

- Replaced `sprintf` with `snprintf` to fix buffer overflow warning.

### `JUCE/Source/kvbuf.c`

- Added a forward declaration with `__attribute__((unused))` for `get_float16` to suppress `-Wunused-function`.

### `pitch_detector.h`, `pitch_shifter.h`

- Added `/*key*/`, `/*value*/` parameter name suppression on `set_misc_param`.

### `pitch_detector_aubio.h`, `pitch_detector_talent.h`

- Added `override` keyword to virtual method overrides (`set_gate`, `set_freq_range`).

### `pitch_shifter_rb.h`, `pitch_shifter_smb.h`, `pitch_shifter_st.h`

- Added `override` to `set_mix` and `set_misc_param` virtual overrides.

### `pitch_shifter_st.cpp`

- Removed unused `uint r =` assignment from `_st.receiveSamples(...)` call.

### `manual_tune.cpp`

- Suppressed unused parameter `time_max_interval` via `/*time_max_interval*/`.

### `mx_tune.cpp`

- Suppressed unused parameter `n` in `record_midi_to_note` via `/*n*/`.

### `smbPitchShift.cpp`

- Wrapped `#define M_PI` with `#ifndef M_PI` / `#endif` guard to prevent redefinition warnings.
