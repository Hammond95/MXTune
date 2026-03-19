#pragma once
#include <JuceHeader.h>

struct ColorTheme
{
    // Notes grid
    juce::Colour background     { 0xff323e44 };
    juce::Colour noteNatural    { 0xff3a4a56 };
    juce::Colour noteAccidental { 0xff232c34 };
    juce::Colour separatorLine  { 0xb3000000 };
    juce::Colour pitchRefLine   { 0x73ffffff };

    // Pitch tracks
    juce::Colour inPitch        { 0xff1eb8ff };  // detected (input) pitch
    juce::Colour outPitch       { 0xff4dff7c };  // tuned (output) pitch
    juce::Colour tuneNodes      { 0xffffa040 };  // manual tune note segments

    // Navigation
    juce::Colour playhead       { 0xffff2222 };
    juce::Colour measureLine    { 0xffffffff };

    // Persistence
    static juce::PropertiesFile::Options storageOptions();
    void load();
    void save() const;
    void reset() { *this = ColorTheme{}; }
};
