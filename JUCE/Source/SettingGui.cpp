/*
  Auto-generated skeleton preserved; custom code only in UserVariables/UserMethods sections.
*/

//[Headers]
#include "AppearanceGui.h"
#include <sstream>
//[/Headers]

#include "SettingGui.h"

//==============================================================================
SettingGui::SettingGui(AutotalentAudioProcessor& p)
    : _proc(p)
{
    // --- Detection & Shifting group ---
    groupComponent.reset(new GroupComponent("new group", TRANS("Detection & Shifting")));
    addAndMakeVisible(groupComponent.get());
    groupComponent->setBounds(8, 8, 584, 128);

    label9.reset(new Label("Det alg", TRANS("Det alg:")));
    addAndMakeVisible(label9.get());
    label9->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    label9->setJustificationType(Justification::centredLeft);
    label9->setEditable(false, false, false);
    label9->setColour(TextEditor::textColourId, Colours::black);
    label9->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
    label9->setBounds(16, 32, 56, 24);

    comboBoxDetAlg.reset(new ComboBox("new combo box"));
    addAndMakeVisible(comboBoxDetAlg.get());
    comboBoxDetAlg->setEditableText(false);
    comboBoxDetAlg->setJustificationType(Justification::centredLeft);
    comboBoxDetAlg->setTextWhenNothingSelected(TRANS("talent"));
    comboBoxDetAlg->setTextWhenNoChoicesAvailable(TRANS("(no choices)"));
    comboBoxDetAlg->addItem(TRANS("autotalent"), 1);
    comboBoxDetAlg->addItem(TRANS("aubio(yinfast)"), 2);
    comboBoxDetAlg->addListener(this);
    comboBoxDetAlg->setBounds(80, 32, 120, 24);
    comboBoxDetAlg->setTooltip("Pitch detection algorithm.\nautotalent: classic, fast.\naubio(yinfast): more accurate (recommended).");

    label10.reset(new Label("Sft Alg", TRANS("Sft Alg:")));
    addAndMakeVisible(label10.get());
    label10->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    label10->setJustificationType(Justification::centredLeft);
    label10->setEditable(false, false, false);
    label10->setColour(TextEditor::textColourId, Colours::black);
    label10->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
    label10->setBounds(16, 64, 56, 24);

    comboBoxSftAlg.reset(new ComboBox("new combo box"));
    addAndMakeVisible(comboBoxSftAlg.get());
    comboBoxSftAlg->setEditableText(false);
    comboBoxSftAlg->setJustificationType(Justification::centredLeft);
    comboBoxSftAlg->setTextWhenNothingSelected(TRANS("talent"));
    comboBoxSftAlg->setTextWhenNoChoicesAvailable(TRANS("(no choices)"));
    comboBoxSftAlg->addItem(TRANS("autotalent"), 1);
    comboBoxSftAlg->addItem(TRANS("SoundTouch"), 2);
    comboBoxSftAlg->addItem(TRANS("rubberband"), 3);
    comboBoxSftAlg->addItem(TRANS("smbPitchShift"), 4);
    comboBoxSftAlg->addListener(this);
    comboBoxSftAlg->setBounds(80, 64, 120, 24);
    comboBoxSftAlg->setTooltip("Pitch shifting algorithm.\nSoundTouch: low latency.\nRubberBand: best quality, higher latency.\nautotalent / smbPitchShift: legacy options.");

    label2.reset(new Label("Min Freq", TRANS("Min Freq:")));
    addAndMakeVisible(label2.get());
    label2->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    label2->setJustificationType(Justification::centredLeft);
    label2->setEditable(false, false, false);
    label2->setColour(TextEditor::textColourId, Colours::black);
    label2->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
    label2->setBounds(208, 32, 64, 24);

    sliderMinFreq.reset(new Slider("new slider"));
    addAndMakeVisible(sliderMinFreq.get());
    sliderMinFreq->setRange(20, 2000, 1);
    sliderMinFreq->setSliderStyle(Slider::LinearBar);
    sliderMinFreq->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderMinFreq->addListener(this);
    sliderMinFreq->setBounds(280, 32, 64, 24);
    sliderMinFreq->setTooltip("Minimum detection frequency (Hz).\nSet just below the lowest expected vocal note (e.g. 70 Hz for bass, 150 Hz for soprano).");

    label3.reset(new Label("Max Freq", TRANS("Max Freq:")));
    addAndMakeVisible(label3.get());
    label3->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    label3->setJustificationType(Justification::centredLeft);
    label3->setEditable(false, false, false);
    label3->setColour(TextEditor::textColourId, Colours::black);
    label3->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
    label3->setBounds(208, 64, 64, 24);

    sliderMaxFreq.reset(new Slider("new slider"));
    addAndMakeVisible(sliderMaxFreq.get());
    sliderMaxFreq->setRange(20, 2000, 1);
    sliderMaxFreq->setSliderStyle(Slider::LinearBar);
    sliderMaxFreq->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderMaxFreq->addListener(this);
    sliderMaxFreq->setBounds(280, 64, 64, 24);
    sliderMaxFreq->setTooltip("Maximum detection frequency (Hz).\nSet just above the highest expected vocal note.");

    label4.reset(new Label("Afreq", TRANS("Afreq:")));
    addAndMakeVisible(label4.get());
    label4->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    label4->setJustificationType(Justification::centredLeft);
    label4->setEditable(false, false, false);
    label4->setColour(TextEditor::textColourId, Colours::black);
    label4->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
    label4->setBounds(352, 32, 48, 24);

    sliderAfreq.reset(new Slider("new slider"));
    addAndMakeVisible(sliderAfreq.get());
    sliderAfreq->setRange(430, 450, 1);
    sliderAfreq->setSliderStyle(Slider::LinearBar);
    sliderAfreq->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderAfreq->addListener(this);
    sliderAfreq->setBounds(408, 32, 64, 24);
    sliderAfreq->setTooltip("Concert A reference pitch (Hz). Standard tuning = 440 Hz.");

    label5.reset(new Label("Gate", TRANS("Gate:")));
    addAndMakeVisible(label5.get());
    label5->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    label5->setJustificationType(Justification::centredLeft);
    label5->setEditable(false, false, false);
    label5->setColour(TextEditor::textColourId, Colours::black);
    label5->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
    label5->setBounds(352, 64, 48, 24);

    sliderGate.reset(new Slider("new slider"));
    addAndMakeVisible(sliderGate.get());
    sliderGate->setRange(-100, -10, 1);
    sliderGate->setSliderStyle(Slider::LinearBar);
    sliderGate->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderGate->addListener(this);
    sliderGate->setBounds(408, 64, 64, 24);
    sliderGate->setTooltip("Noise gate (dBFS). Audio below this level is ignored by the pitch detector. Higher value = noisier input tolerated.");

    label6.reset(new Label("VThresh", TRANS("VThresh:")));
    addAndMakeVisible(label6.get());
    label6->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    label6->setJustificationType(Justification::centredLeft);
    label6->setEditable(false, false, false);
    label6->setColour(TextEditor::textColourId, Colours::black);
    label6->setColour(TextEditor::backgroundColourId, Colour(0x00000000));
    label6->setBounds(480, 32, 56, 24);

    sliderVThresh.reset(new Slider("new slider"));
    addAndMakeVisible(sliderVThresh.get());
    sliderVThresh->setRange(0.1, 1.0, 0.01);
    sliderVThresh->setSliderStyle(Slider::LinearBar);
    sliderVThresh->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderVThresh->addListener(this);
    sliderVThresh->setBounds(544, 32, 40, 24);
    sliderVThresh->setTooltip("Confidence threshold. Pitch correction is only applied when the detector confidence exceeds this value.\nLower = more correction; Higher = only on clearly detected pitches.");

    toggleButtonFormant.reset(new ToggleButton("Formant"));
    addAndMakeVisible(toggleButtonFormant.get());
    toggleButtonFormant->setButtonText(TRANS("Formant Preserve (RubberBand only)"));
    toggleButtonFormant->addListener(this);
    toggleButtonFormant->setBounds(16, 98, 356, 20);
    toggleButtonFormant->setTooltip("Preserve vocal formants when shifting pitch (RubberBand only).\nPrevents the 'chipmunk' effect when shifting pitch significantly.");

    // --- MIDI group ---
    groupMidi.reset(new GroupComponent("groupMidi", TRANS("MIDI")));
    addAndMakeVisible(groupMidi.get());
    groupMidi->setBounds(8, 144, 584, 80);

    toggleButtonMidiRecord.reset(new ToggleButton("MidiRecord"));
    addAndMakeVisible(toggleButtonMidiRecord.get());
    toggleButtonMidiRecord->setButtonText(TRANS("Record MIDI"));
    toggleButtonMidiRecord->addListener(this);
    toggleButtonMidiRecord->setBounds(16, 168, 176, 24);
    toggleButtonMidiRecord->setTooltip("Record incoming MIDI notes as tuning segments in the pitch editor.\nEnable this, then play a MIDI instrument to draw tuning segments.");

    toggleButtonMidiExport.reset(new ToggleButton("MidiExport"));
    addAndMakeVisible(toggleButtonMidiExport.get());
    toggleButtonMidiExport->setButtonText(TRANS("Export MIDI"));
    toggleButtonMidiExport->addListener(this);
    toggleButtonMidiExport->setBounds(208, 168, 176, 24);
    toggleButtonMidiExport->setTooltip("Output stored pitch segments as MIDI notes during playback.\nRequires Snap to be run first to create pitch segments.");

    toggleButtonMidiLive.reset(new ToggleButton("MidiLive"));
    addAndMakeVisible(toggleButtonMidiLive.get());
    toggleButtonMidiLive->setButtonText(TRANS("Live MIDI Follow"));
    toggleButtonMidiLive->addListener(this);
    toggleButtonMidiLive->setBounds(400, 168, 184, 24);
    toggleButtonMidiLive->setTooltip("Real-time MIDI pitch follower.\nOutputs the detected vocal pitch as MIDI notes immediately, with no pre-processing needed.");

    // --- SoundTouch group ---
    groupSoundTouch.reset(new GroupComponent("groupSoundTouch", TRANS("SoundTouch")));
    addAndMakeVisible(groupSoundTouch.get());
    groupSoundTouch->setBounds(8, 232, 584, 80);

    labelSeqMs.reset(new Label("labelSeqMs", TRANS("Seq ms:")));
    addAndMakeVisible(labelSeqMs.get());
    labelSeqMs->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    labelSeqMs->setJustificationType(Justification::centredLeft);
    labelSeqMs->setEditable(false, false, false);
    labelSeqMs->setBounds(16, 256, 52, 20);

    sliderSeqMs.reset(new Slider("sliderSeqMs"));
    addAndMakeVisible(sliderSeqMs.get());
    sliderSeqMs->setRange(1, 500, 1);
    sliderSeqMs->setSliderStyle(Slider::LinearBar);
    sliderSeqMs->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderSeqMs->addListener(this);
    sliderSeqMs->setBounds(72, 252, 72, 24);
    sliderSeqMs->setTooltip("SoundTouch: processing sequence length (ms).\nIncrease for smoother output; decrease to reduce latency.");

    labelSeekwinMs.reset(new Label("labelSeekwinMs", TRANS("Seekwin ms:")));
    addAndMakeVisible(labelSeekwinMs.get());
    labelSeekwinMs->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    labelSeekwinMs->setJustificationType(Justification::centredLeft);
    labelSeekwinMs->setEditable(false, false, false);
    labelSeekwinMs->setBounds(156, 256, 72, 20);

    sliderSeekwinMs.reset(new Slider("sliderSeekwinMs"));
    addAndMakeVisible(sliderSeekwinMs.get());
    sliderSeekwinMs->setRange(1, 500, 1);
    sliderSeekwinMs->setSliderStyle(Slider::LinearBar);
    sliderSeekwinMs->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderSeekwinMs->addListener(this);
    sliderSeekwinMs->setBounds(232, 252, 72, 24);
    sliderSeekwinMs->setTooltip("SoundTouch: seek window length (ms).\nAffects tempo-compensation sensitivity.");

    labelOverlapMs.reset(new Label("labelOverlapMs", TRANS("Overlap ms:")));
    addAndMakeVisible(labelOverlapMs.get());
    labelOverlapMs->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    labelOverlapMs->setJustificationType(Justification::centredLeft);
    labelOverlapMs->setEditable(false, false, false);
    labelOverlapMs->setBounds(316, 256, 72, 20);

    sliderOverlapMs.reset(new Slider("sliderOverlapMs"));
    addAndMakeVisible(sliderOverlapMs.get());
    sliderOverlapMs->setRange(1, 500, 1);
    sliderOverlapMs->setSliderStyle(Slider::LinearBar);
    sliderOverlapMs->setTextBoxStyle(Slider::TextBoxAbove, false, 80, 20);
    sliderOverlapMs->addListener(this);
    sliderOverlapMs->setBounds(392, 252, 72, 24);
    sliderOverlapMs->setTooltip("SoundTouch: crossfade overlap length (ms).\nAffects transition smoothness between processing segments.");

    // --- Extra params row ---
    labelExtra.reset(new Label("labelExtra", TRANS("Extra:")));
    addAndMakeVisible(labelExtra.get());
    labelExtra->setFont(Font(15.00f, Font::plain).withTypefaceStyle("Regular"));
    labelExtra->setJustificationType(Justification::centredLeft);
    labelExtra->setEditable(false, false, false);
    labelExtra->setBounds(16, 320, 48, 20);

    textEditorExtra.reset(new TextEditor("textEditorExtra"));
    addAndMakeVisible(textEditorExtra.get());
    textEditorExtra->setMultiLine(false);
    textEditorExtra->setReturnKeyStartsNewLine(false);
    textEditorExtra->setReadOnly(false);
    textEditorExtra->setScrollbarsShown(false);
    textEditorExtra->setCaretVisible(true);
    textEditorExtra->setPopupMenuEnabled(true);
    textEditorExtra->setText(String());
    textEditorExtra->setBounds(70, 316, 522, 28);
    textEditorExtra->setTooltip("Advanced: additional key=value parameters, one per line.\nExample: delay=100");

    // --- Bottom buttons ---
    textButtonApply.reset(new TextButton("Apply"));
    addAndMakeVisible(textButtonApply.get());
    textButtonApply->addListener(this);
    textButtonApply->setBounds(16, 356, 472, 36);
    textButtonApply->setTooltip("Apply all setting changes.");

    textButtonAppearance.reset(new TextButton("Appearance"));
    addAndMakeVisible(textButtonAppearance.get());
    textButtonAppearance->setButtonText(TRANS("Appearance..."));
    textButtonAppearance->addListener(this);
    textButtonAppearance->setBounds(496, 356, 96, 36);
    textButtonAppearance->setTooltip("Open the Appearance editor to customize UI colors.");

    setSize(600, 400);

    // --- Initialize controls from processor state ---
    auto getInt = [](const std::string& s, const std::string& key, int def) -> int {
        auto pos = s.find(key + "=");
        if (pos == std::string::npos) return def;
        return std::atoi(s.c_str() + pos + key.size() + 1);
    };
    auto getBool = [](const std::string& s, const std::string& key, bool def) -> bool {
        auto pos = s.find(key + "=");
        if (pos == std::string::npos) return def;
        return s[pos + key.size() + 1] == '1';
    };

    std::string misc = _proc.get_misc_param();

    comboBoxDetAlg->setSelectedId(
        (int)_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_ALG) + 1,
        dontSendNotification);
    comboBoxSftAlg->setSelectedId(
        (int)_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SFT_ALG) + 1,
        dontSendNotification);

    sliderMinFreq->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_MIN_FREQ), dontSendNotification);
    sliderMaxFreq->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_MAX_FREQ), dontSendNotification);
    sliderAfreq->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_AFREQ), dontSendNotification);
    sliderGate->setValue(-_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_GATE), dontSendNotification);
    sliderVThresh->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_VTHRESH), dontSendNotification);

    toggleButtonFormant->setToggleState(
        _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_FORMANT) > 0.f,
        dontSendNotification);

    sliderSeqMs->setValue(getInt(misc, "st.sequence_ms", 16), dontSendNotification);
    sliderSeekwinMs->setValue(getInt(misc, "st.seekwindow_ms", 4), dontSendNotification);
    sliderOverlapMs->setValue(getInt(misc, "st.overlap_ms", 4), dontSendNotification);

    toggleButtonMidiRecord->setToggleState(getBool(misc, "midi.record", false), dontSendNotification);
    toggleButtonMidiExport->setToggleState(getBool(misc, "midi.export", false), dontSendNotification);
    toggleButtonMidiLive->setToggleState(getBool(misc, "midi.live", false), dontSendNotification);

    // Strip known keys from misc, show only unknown lines in textEditorExtra
    {
        static const std::vector<std::string> knownKeys = {
            "st.sequence_ms", "st.seekwindow_ms", "st.overlap_ms",
            "midi.record", "midi.export", "midi.live"
        };
        std::string extra;
        std::istringstream iss(misc);
        std::string line;
        while (std::getline(iss, line)) {
            bool isKnown = false;
            for (const auto& k : knownKeys) {
                if (line.find(k + "=") == 0) { isKnown = true; break; }
            }
            if (!isKnown && !line.empty()) {
                if (!extra.empty()) extra += "\n";
                extra += line;
            }
        }
        textEditorExtra->setText(String(extra), false);
    }

    // Propagate tooltips to Slider internal child components (TextBoxAbove Label intercepts mouse)
    {
        Slider* sliders[] = {sliderMinFreq.get(), sliderMaxFreq.get(), sliderAfreq.get(),
                             sliderGate.get(), sliderVThresh.get(),
                             sliderSeqMs.get(), sliderSeekwinMs.get(), sliderOverlapMs.get()};
        for (Slider* s : sliders) {
            String tip = s->getTooltip();
            for (int i = 0; i < s->getNumChildComponents(); ++i)
                if (auto* tc = dynamic_cast<SettableTooltipClient*>(s->getChildComponent(i)))
                    tc->setTooltip(tip);
        }
    }

    // Tooltip window
    _tooltipWindow = std::make_unique<TooltipWindow>(this, 600);

    _updateSoundTouchVisibility();
}

SettingGui::~SettingGui()
{
    groupComponent         = nullptr;
    label9                 = nullptr;
    label10                = nullptr;
    label2                 = nullptr;
    label3                 = nullptr;
    label4                 = nullptr;
    label5                 = nullptr;
    label6                 = nullptr;
    comboBoxDetAlg         = nullptr;
    comboBoxSftAlg         = nullptr;
    sliderMinFreq          = nullptr;
    sliderMaxFreq          = nullptr;
    sliderAfreq            = nullptr;
    sliderGate             = nullptr;
    sliderVThresh          = nullptr;
    toggleButtonFormant    = nullptr;
    groupMidi              = nullptr;
    toggleButtonMidiRecord = nullptr;
    toggleButtonMidiExport = nullptr;
    toggleButtonMidiLive   = nullptr;
    groupSoundTouch        = nullptr;
    labelSeqMs             = nullptr;
    sliderSeqMs            = nullptr;
    labelSeekwinMs         = nullptr;
    sliderSeekwinMs        = nullptr;
    labelOverlapMs         = nullptr;
    sliderOverlapMs        = nullptr;
    labelExtra             = nullptr;
    textEditorExtra        = nullptr;
    textButtonApply        = nullptr;
    textButtonAppearance   = nullptr;
    _tooltipWindow         = nullptr;
}

//==============================================================================
void SettingGui::paint(Graphics& g)
{
    g.fillAll(Colour(0xff323e44));
}

void SettingGui::resized()
{
}

void SettingGui::comboBoxChanged(ComboBox* c)
{
    if (c == comboBoxSftAlg.get())
    {
        _updateSoundTouchVisibility();
    }
}

void SettingGui::sliderValueChanged(Slider* /*s*/)
{
}

void SettingGui::buttonClicked(Button* b)
{
    if (b == textButtonAppearance.get())
    {
        AppearanceGui component(_proc);
        juce::DialogWindow::showModalDialog("Appearance", &component, nullptr, juce::Colours::darkgrey, false, false, false);
        return;
    }

    if (b == textButtonApply.get())
    {
        std::string misc;
        misc += "st.sequence_ms=" + std::to_string((int)sliderSeqMs->getValue()) + "\n";
        misc += "st.seekwindow_ms=" + std::to_string((int)sliderSeekwinMs->getValue()) + "\n";
        misc += "st.overlap_ms=" + std::to_string((int)sliderOverlapMs->getValue()) + "\n";
        misc += std::string("midi.record=") + (toggleButtonMidiRecord->getToggleState() ? "1" : "0") + "\n";
        misc += std::string("midi.export=") + (toggleButtonMidiExport->getToggleState() ? "1" : "0") + "\n";
        misc += std::string("midi.live=")   + (toggleButtonMidiLive->getToggleState()   ? "1" : "0") + "\n";
        auto extra = textEditorExtra->getText().trim().toStdString();
        if (!extra.empty()) misc += extra + "\n";

        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_ALG,      (float)(comboBoxDetAlg->getSelectedId() - 1));
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_SFT_ALG,      (float)(comboBoxSftAlg->getSelectedId() - 1));
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_MIN_FREQ, (float)sliderMinFreq->getValue());
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_MAX_FREQ, (float)sliderMaxFreq->getValue());
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_AFREQ,        (float)sliderAfreq->getValue());
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_DET_GATE,     -(float)sliderGate->getValue());
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_VTHRESH,      (float)sliderVThresh->getValue());
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_FORMANT,      toggleButtonFormant->getToggleState() ? 1.f : 0.f);
        _proc.set_misc_param(misc);
        _proc.report_latency_samples();
    }
}

void SettingGui::_updateSoundTouchVisibility()
{
    bool show = (comboBoxSftAlg->getSelectedId() == 2);
    groupSoundTouch->setVisible(show);
    labelSeqMs->setVisible(show);
    sliderSeqMs->setVisible(show);
    labelSeekwinMs->setVisible(show);
    sliderSeekwinMs->setVisible(show);
    labelOverlapMs->setVisible(show);
    sliderOverlapMs->setVisible(show);
}
