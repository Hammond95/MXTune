#include "appearance.h"

juce::PropertiesFile::Options ColorTheme::storageOptions()
{
    juce::PropertiesFile::Options opts;
    opts.applicationName        = "MXTune";
    opts.filenameSuffix         = ".settings";
    opts.folderName             = "MXTune";
    opts.osxLibrarySubFolder    = "Application Support";
    return opts;
}

static juce::Colour loadColour(juce::PropertiesFile& f, const char* key, juce::Colour def)
{
    return juce::Colour((juce::uint32)(unsigned int)f.getIntValue(key, (int)(unsigned int)def.getARGB()));
}

void ColorTheme::load()
{
    juce::PropertiesFile f(storageOptions());
    background     = loadColour(f, "color_background",     background);
    noteNatural    = loadColour(f, "color_noteNatural",    noteNatural);
    noteAccidental = loadColour(f, "color_noteAccidental", noteAccidental);
    separatorLine  = loadColour(f, "color_separatorLine",  separatorLine);
    pitchRefLine   = loadColour(f, "color_pitchRefLine",   pitchRefLine);
    inPitch        = loadColour(f, "color_inPitch",        inPitch);
    outPitch       = loadColour(f, "color_outPitch",       outPitch);
    tuneNodes      = loadColour(f, "color_tuneNodes",      tuneNodes);
    playhead       = loadColour(f, "color_playhead",       playhead);
    measureLine    = loadColour(f, "color_measureLine",    measureLine);
}

void ColorTheme::save() const
{
    juce::PropertiesFile f(storageOptions());
    f.setValue("color_background",     (int)(unsigned int)background.getARGB());
    f.setValue("color_noteNatural",    (int)(unsigned int)noteNatural.getARGB());
    f.setValue("color_noteAccidental", (int)(unsigned int)noteAccidental.getARGB());
    f.setValue("color_separatorLine",  (int)(unsigned int)separatorLine.getARGB());
    f.setValue("color_pitchRefLine",   (int)(unsigned int)pitchRefLine.getARGB());
    f.setValue("color_inPitch",        (int)(unsigned int)inPitch.getARGB());
    f.setValue("color_outPitch",       (int)(unsigned int)outPitch.getARGB());
    f.setValue("color_tuneNodes",      (int)(unsigned int)tuneNodes.getARGB());
    f.setValue("color_playhead",       (int)(unsigned int)playhead.getARGB());
    f.setValue("color_measureLine",    (int)(unsigned int)measureLine.getARGB());
    f.saveIfNeeded();
}
