/*
  Auto-generated skeleton preserved; custom code only in UserVariables/UserMethods sections.
*/
#pragma once

//[Headers]
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AppearanceGui.h"
//[/Headers]

class SettingGui : public Component,
                   public ComboBox::Listener,
                   public Slider::Listener,
                   public Button::Listener
{
public:
    SettingGui(AutotalentAudioProcessor& p);
    ~SettingGui() override;

    //[UserMethods]
    //[/UserMethods]

    void paint(Graphics& g) override;
    void resized() override;
    void comboBoxChanged(ComboBox* c) override;
    void sliderValueChanged(Slider* s) override;
    void buttonClicked(Button* b) override;

private:
    //[UserVariables]
    AutotalentAudioProcessor& _proc;
    void _updateSoundTouchVisibility();
    //[/UserVariables]

    // Detection & Shifting group
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<Label>    label9, label10, label2, label3, label4, label5, label6;
    std::unique_ptr<ComboBox> comboBoxDetAlg, comboBoxSftAlg;
    std::unique_ptr<Slider>   sliderMinFreq, sliderMaxFreq, sliderAfreq, sliderGate, sliderVThresh;
    std::unique_ptr<ToggleButton> toggleButtonFormant;

    // MIDI group
    std::unique_ptr<GroupComponent>  groupMidi;
    std::unique_ptr<ToggleButton>    toggleButtonMidiRecord;
    std::unique_ptr<ToggleButton>    toggleButtonMidiExport;
    std::unique_ptr<ToggleButton>    toggleButtonMidiLive;

    // SoundTouch group
    std::unique_ptr<GroupComponent> groupSoundTouch;
    std::unique_ptr<Label>   labelSeqMs, labelSeekwinMs, labelOverlapMs;
    std::unique_ptr<Slider>  sliderSeqMs, sliderSeekwinMs, sliderOverlapMs;

    // Extra params (advanced)
    std::unique_ptr<Label>      labelExtra;
    std::unique_ptr<TextEditor> textEditorExtra;

    // Bottom buttons
    std::unique_ptr<TextButton> textButtonApply;
    std::unique_ptr<TextButton> textButtonAppearance;

    // Tooltip support
    std::unique_ptr<TooltipWindow> _tooltipWindow;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SettingGui)
};
