#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class AppearanceGui : public juce::Component,
                      public juce::Button::Listener,
                      public juce::ChangeListener
{
public:
    explicit AppearanceGui(AutotalentAudioProcessor& p);
    ~AppearanceGui() override;

    void paint(juce::Graphics& g) override;
    void resized() override;
    void buttonClicked(juce::Button* b) override;
    void changeListenerCallback(juce::ChangeBroadcaster* source) override;

private:
    void addRow(const juce::String& label, juce::Colour& colorRef);
    void updateSwatches();
    void openPicker(juce::Colour& colorRef, juce::TextButton* swatch);

    AutotalentAudioProcessor& _proc;

    struct Row
    {
        std::unique_ptr<juce::Label>      label;
        std::unique_ptr<juce::TextButton> swatch;
        juce::Colour*                     colorPtr = nullptr;
    };
    std::vector<Row> _rows;

    std::unique_ptr<juce::TextButton> _btnReset;
    std::unique_ptr<juce::TextButton> _btnApply;

    juce::Colour* _editing = nullptr;   // color currently open in picker

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AppearanceGui)
};
