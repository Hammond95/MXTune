/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "KeyDetectGui.h"
#include "SettingGui.h"
//[/Headers]

#include "PluginGui.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGui::PluginGui (AutotalentAudioProcessor& p)
    : AudioProcessorEditor(p), _proc(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    groupComponent6.reset (new GroupComponent ("new group",
                                               TRANS("Notes")));
    addAndMakeVisible (groupComponent6.get());

    groupComponent6->setBounds (144, 96, 712, 496);

    groupComponent4.reset (new GroupComponent ("new group",
                                               String()));
    addAndMakeVisible (groupComponent4.get());

    groupComponent4->setBounds (248, 8, 608, 88);

    groupComponent2.reset (new GroupComponent ("Key",
                                               TRANS("Key")));
    addAndMakeVisible (groupComponent2.get());

    groupComponent2->setBounds (8, 96, 136, 312);

    sliderAttack.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderAttack.get());
    sliderAttack->setRange (0, 500, 1);
    sliderAttack->setSliderStyle (Slider::LinearBar);
    sliderAttack->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderAttack->addListener (this);

    sliderAttack->setBounds (280, 56, 64, 24);

    groupComponent5.reset (new GroupComponent ("new group",
                                               TRANS("Notes")));
    addAndMakeVisible (groupComponent5.get());

    groupComponent5->setBounds (144, 96, 712, 496);

    groupComponent.reset (new GroupComponent ("new group",
                                              String()));
    addAndMakeVisible (groupComponent.get());

    groupComponent->setBounds (8, 8, 240, 88);

    toggleButtonTrack.reset (new ToggleButton ("Track"));
    addAndMakeVisible (toggleButtonTrack.get());
    toggleButtonTrack->addListener (this);

    toggleButtonTrack->setBounds (712, 24, 64, 24);

    toggleButtonAutoTune.reset (new ToggleButton ("AutoPitch"));
    addAndMakeVisible (toggleButtonAutoTune.get());
    toggleButtonAutoTune->addListener (this);

    toggleButtonAutoTune->setBounds (16, 24, 96, 24);

    toggleButtonNoteA.reset (new ToggleButton ("A"));
    addAndMakeVisible (toggleButtonNoteA.get());
    toggleButtonNoteA->addListener (this);
    toggleButtonNoteA->setToggleState (true, dontSendNotification);

    toggleButtonNoteA->setBounds (24, 216, 48, 24);

    toggleButtonNoteBb.reset (new ToggleButton ("Bb"));
    addAndMakeVisible (toggleButtonNoteBb.get());
    toggleButtonNoteBb->addListener (this);
    toggleButtonNoteBb->setToggleState (true, dontSendNotification);

    toggleButtonNoteBb->setBounds (24, 248, 48, 24);

    toggleButtonNoteB.reset (new ToggleButton ("B"));
    addAndMakeVisible (toggleButtonNoteB.get());
    toggleButtonNoteB->addListener (this);
    toggleButtonNoteB->setToggleState (true, dontSendNotification);

    toggleButtonNoteB->setBounds (24, 280, 48, 24);

    toggleButtonNoteC.reset (new ToggleButton ("C"));
    addAndMakeVisible (toggleButtonNoteC.get());
    toggleButtonNoteC->addListener (this);
    toggleButtonNoteC->setToggleState (true, dontSendNotification);

    toggleButtonNoteC->setBounds (24, 312, 48, 24);

    toggleButtonNoteDb.reset (new ToggleButton ("Db"));
    addAndMakeVisible (toggleButtonNoteDb.get());
    toggleButtonNoteDb->addListener (this);
    toggleButtonNoteDb->setToggleState (true, dontSendNotification);

    toggleButtonNoteDb->setBounds (24, 344, 48, 24);

    toggleButtonNoteD.reset (new ToggleButton ("D"));
    addAndMakeVisible (toggleButtonNoteD.get());
    toggleButtonNoteD->addListener (this);
    toggleButtonNoteD->setToggleState (true, dontSendNotification);

    toggleButtonNoteD->setBounds (24, 376, 48, 24);

    toggleButtonNoteEb.reset (new ToggleButton ("Eb"));
    addAndMakeVisible (toggleButtonNoteEb.get());
    toggleButtonNoteEb->addListener (this);
    toggleButtonNoteEb->setToggleState (true, dontSendNotification);

    toggleButtonNoteEb->setBounds (80, 216, 48, 24);

    toggleButtonNoteE.reset (new ToggleButton ("E"));
    addAndMakeVisible (toggleButtonNoteE.get());
    toggleButtonNoteE->addListener (this);
    toggleButtonNoteE->setToggleState (true, dontSendNotification);

    toggleButtonNoteE->setBounds (80, 248, 48, 24);

    toggleButtonNoteF.reset (new ToggleButton ("F"));
    addAndMakeVisible (toggleButtonNoteF.get());
    toggleButtonNoteF->addListener (this);
    toggleButtonNoteF->setToggleState (true, dontSendNotification);

    toggleButtonNoteF->setBounds (80, 280, 48, 24);

    toggleButtonNoteGb.reset (new ToggleButton ("Gb"));
    addAndMakeVisible (toggleButtonNoteGb.get());
    toggleButtonNoteGb->addListener (this);
    toggleButtonNoteGb->setToggleState (true, dontSendNotification);

    toggleButtonNoteGb->setBounds (80, 312, 48, 24);

    toggleButtonNoteAb.reset (new ToggleButton ("Ab"));
    addAndMakeVisible (toggleButtonNoteAb.get());
    toggleButtonNoteAb->addListener (this);
    toggleButtonNoteAb->setToggleState (true, dontSendNotification);

    toggleButtonNoteAb->setBounds (80, 376, 48, 24);

    toggleButtonNoteG.reset (new ToggleButton ("G"));
    addAndMakeVisible (toggleButtonNoteG.get());
    toggleButtonNoteG->addListener (this);
    toggleButtonNoteG->setToggleState (true, dontSendNotification);

    toggleButtonNoteG->setBounds (80, 344, 48, 24);

    textButtonSnapKey.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonSnapKey.get());
    textButtonSnapKey->setButtonText (TRANS("Snap Key"));
    textButtonSnapKey->addListener (this);
    textButtonSnapKey->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonSnapKey->setBounds (624, 24, 80, 24);

    textButtonClearPitch.reset (new TextButton ("ClearPitch"));
    addAndMakeVisible (textButtonClearPitch.get());
    textButtonClearPitch->setButtonText (TRANS("CPitch"));
    textButtonClearPitch->addListener (this);
    textButtonClearPitch->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonClearPitch->setBounds (784, 64, 64, 24);

    comboBoxKey.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBoxKey.get());
    comboBoxKey->setEditableText (false);
    comboBoxKey->setJustificationType (Justification::centredLeft);
    comboBoxKey->setTextWhenNothingSelected (TRANS("C"));
    comboBoxKey->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxKey->addItem (TRANS("A"), 1);
    comboBoxKey->addItem (TRANS("Bb"), 2);
    comboBoxKey->addItem (TRANS("B"), 3);
    comboBoxKey->addItem (TRANS("C"), 4);
    comboBoxKey->addItem (TRANS("Db"), 5);
    comboBoxKey->addItem (TRANS("D"), 6);
    comboBoxKey->addItem (TRANS("Eb"), 7);
    comboBoxKey->addItem (TRANS("E"), 8);
    comboBoxKey->addItem (TRANS("F"), 9);
    comboBoxKey->addItem (TRANS("Gb"), 10);
    comboBoxKey->addItem (TRANS("G"), 11);
    comboBoxKey->addItem (TRANS("Ab"), 12);
    comboBoxKey->addItem (TRANS("---"), 13);
    comboBoxKey->addListener (this);

    comboBoxKey->setBounds (32, 120, 88, 24);

    comboBoxKeyType.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBoxKeyType.get());
    comboBoxKeyType->setEditableText (false);
    comboBoxKeyType->setJustificationType (Justification::centredLeft);
    comboBoxKeyType->setTextWhenNothingSelected (TRANS("Chromatic"));
    comboBoxKeyType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBoxKeyType->addItem (TRANS("Major"), 1);
    comboBoxKeyType->addItem (TRANS("Minor"), 2);
    comboBoxKeyType->addItem (TRANS("Chromatic"), 3);
    comboBoxKeyType->addItem (TRANS("---"), 4);
    comboBoxKeyType->addListener (this);

    comboBoxKeyType->setBounds (32, 152, 88, 24);

    groupComponent3.reset (new GroupComponent ("Setting",
                                               TRANS("Setting")));
    addAndMakeVisible (groupComponent3.get());

    groupComponent3->setBounds (8, 408, 136, 184);

    sliderRelease.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderRelease.get());
    sliderRelease->setRange (0, 500, 1);
    sliderRelease->setSliderStyle (Slider::LinearBar);
    sliderRelease->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderRelease->addListener (this);

    sliderRelease->setBounds (368, 56, 64, 24);

    sliderAmount.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderAmount.get());
    sliderAmount->setRange (0, 1, 0.01);
    sliderAmount->setSliderStyle (Slider::LinearBar);
    sliderAmount->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderAmount->addListener (this);

    sliderAmount->setBounds (456, 56, 64, 24);

    label4.reset (new Label ("Attack(ms)",
                             TRANS("Attack(ms)")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (272, 24, 80, 24);

    label5.reset (new Label ("Release(ms)",
                             TRANS("Release(ms)")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (360, 24, 80, 24);

    label6.reset (new Label ("Amount",
                             TRANS("Amount")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (456, 24, 64, 24);

    toggleButtonSnap.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButtonSnap.get());
    toggleButtonSnap->setButtonText (TRANS("Snap"));
    toggleButtonSnap->addListener (this);
    toggleButtonSnap->setToggleState (true, dontSendNotification);

    toggleButtonSnap->setBounds (784, 24, 64, 24);

    textButtonClearNote.reset (new TextButton ("ClearNote"));
    addAndMakeVisible (textButtonClearNote.get());
    textButtonClearNote->setButtonText (TRANS("CNote"));
    textButtonClearNote->addListener (this);
    textButtonClearNote->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonClearNote->setBounds (712, 64, 64, 24);

    label7.reset (new Label ("Smooth",
                             TRANS("Smooth:")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (16, 56, 56, 24);

    sliderATSmooth.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderATSmooth.get());
    sliderATSmooth->setRange (0, 1, 0.01);
    sliderATSmooth->setSliderStyle (Slider::LinearBar);
    sliderATSmooth->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderATSmooth->addListener (this);

    sliderATSmooth->setBounds (72, 56, 40, 24);

    label8.reset (new Label ("Amount:",
                             TRANS("Amount:")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (128, 56, 56, 24);

    sliderATAmount.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderATAmount.get());
    sliderATAmount->setRange (0, 1, 0.01);
    sliderATAmount->setSliderStyle (Slider::LinearBar);
    sliderATAmount->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderATAmount->addListener (this);

    sliderATAmount->setBounds (184, 56, 40, 24);

    textButtonCANote.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonCANote.get());
    textButtonCANote->setButtonText (TRANS("CAutoNote"));
    textButtonCANote->addListener (this);
    textButtonCANote->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonCANote->setBounds (624, 64, 80, 24);

    textButtonDetectKey.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonDetectKey.get());
    textButtonDetectKey->setButtonText (TRANS("Detect"));
    textButtonDetectKey->addListener (this);
    textButtonDetectKey->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonDetectKey->setBounds (32, 184, 88, 24);

    label3.reset (new Label ("Length",
                             TRANS("Length:")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (16, 432, 56, 24);

    sliderMinLen.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderMinLen.get());
    sliderMinLen->setRange (0, 1000, 10);
    sliderMinLen->setSliderStyle (Slider::LinearBar);
    sliderMinLen->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderMinLen->addListener (this);

    sliderMinLen->setBounds (80, 432, 48, 24);

    label11.reset (new Label ("Interval",
                              TRANS("Interval:")));
    addAndMakeVisible (label11.get());
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label11->setBounds (16, 464, 56, 24);

    sliderMaxInterval.reset (new Slider ("new slider"));
    addAndMakeVisible (sliderMaxInterval.get());
    sliderMaxInterval->setRange (0, 1000, 10);
    sliderMaxInterval->setSliderStyle (Slider::LinearBar);
    sliderMaxInterval->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderMaxInterval->addListener (this);

    sliderMaxInterval->setBounds (80, 464, 48, 24);

    textButtonSetting.reset (new TextButton ("new button"));
    addAndMakeVisible (textButtonSetting.get());
    textButtonSetting->setButtonText (TRANS("Setting"));
    textButtonSetting->addListener (this);
    textButtonSetting->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonSetting->setBounds (24, 512, 104, 40);

    textButtonUndoNote.reset (new TextButton ("UndoNote"));
    addAndMakeVisible (textButtonUndoNote.get());
    textButtonUndoNote->setButtonText (TRANS("Undo"));
    textButtonUndoNote->addListener (this);
    textButtonUndoNote->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonUndoNote->setBounds (552, 24, 64, 24);

    textButtonRedoNote.reset (new TextButton ("RedoNote"));
    addAndMakeVisible (textButtonRedoNote.get());
    textButtonRedoNote->setButtonText (TRANS("Redo"));
    textButtonRedoNote->addListener (this);
    textButtonRedoNote->setColour (TextButton::buttonColourId, Colour (0x00a45c94));

    textButtonRedoNote->setBounds (552, 64, 64, 24);


    textButtonMore.reset (new TextButton ("More"));
    addAndMakeVisible (textButtonMore.get());
    textButtonMore->setButtonText (TRANS("More v"));
    textButtonMore->addListener (this);
    textButtonMore->setColour (TextButton::buttonColourId, Colour (0x00a45c94));
    textButtonMore->setBounds (796, 8, 56, 24);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (860, 600);
    setResizable (true, true);
    setResizeLimits (430, 300, 10000, 10000);

    //[Constructor] You can add your own custom stuff here..
    _update_gui_parameter();
    startTimer(1000 / 15);
    //[/Constructor]
}

PluginGui::~PluginGui()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent6 = nullptr;
    groupComponent4 = nullptr;
    groupComponent2 = nullptr;
    sliderAttack = nullptr;
    groupComponent5 = nullptr;
    groupComponent = nullptr;
    toggleButtonTrack = nullptr;
    toggleButtonAutoTune = nullptr;
    toggleButtonNoteA = nullptr;
    toggleButtonNoteBb = nullptr;
    toggleButtonNoteB = nullptr;
    toggleButtonNoteC = nullptr;
    toggleButtonNoteDb = nullptr;
    toggleButtonNoteD = nullptr;
    toggleButtonNoteEb = nullptr;
    toggleButtonNoteE = nullptr;
    toggleButtonNoteF = nullptr;
    toggleButtonNoteGb = nullptr;
    toggleButtonNoteAb = nullptr;
    toggleButtonNoteG = nullptr;
    textButtonSnapKey = nullptr;
    textButtonClearPitch = nullptr;
    comboBoxKey = nullptr;
    comboBoxKeyType = nullptr;
    groupComponent3 = nullptr;
    sliderRelease = nullptr;
    sliderAmount = nullptr;
    label4 = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    toggleButtonSnap = nullptr;
    textButtonClearNote = nullptr;
    label7 = nullptr;
    sliderATSmooth = nullptr;
    label8 = nullptr;
    sliderATAmount = nullptr;
    textButtonCANote = nullptr;
    textButtonDetectKey = nullptr;
    label3 = nullptr;
    sliderMinLen = nullptr;
    label11 = nullptr;
    sliderMaxInterval = nullptr;
    textButtonSetting = nullptr;
    textButtonUndoNote = nullptr;
    textButtonRedoNote = nullptr;
    textButtonMore = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGui::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    _update_gui_parameter();
    //[/UserPrePaint]

    g.fillAll (_proc.get_color_theme().background);

    {
        int x = 152, y = 112, width = 696, height = 472;
        Colour fillColour = Colour (0x04000000);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        {
            float sx = (float)getWidth()  / 860.0f;
            float sy = (float)getHeight() / 600.0f;

            int top_h   = (int)roundf(40 * sy);
            int panel_h = _more_open ? (int)roundf(80 * sy) : 0;
            int notes_y = top_h + panel_h;
            int label_w = (int)roundf(28 * sx);

            _draw_x = label_w;
            _draw_w = getWidth() - label_w;

            int gap = juce::jmax(1, (int)roundf(2 * sy));
            _scrub_bar_h = juce::jmax(8, (int)roundf(12 * sy));
            _scrub_bar_y = notes_y + gap;
            _draw_y      = _scrub_bar_y + _scrub_bar_h + gap;
            _draw_h      = getHeight() - _draw_y - gap;

            x      = 0;
            y      = notes_y;
            width  = getWidth();
            height = getHeight() - notes_y;
        }
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);

        // Top bar separator line
        float sy2 = (float)getHeight() / 600.0f;
        int top_h = (int)roundf(40 * sy2);
        g.setColour (juce::Colours::black.withAlpha(0.4f));
        g.drawLine (0, top_h, getWidth(), top_h, 1.0f);

        // More panel separator line (when open)
        if (_more_open) {
            int panel_bottom = top_h + (int)roundf(80 * sy2);
            g.setColour (juce::Colours::black.withAlpha(0.3f));
            g.drawLine (0, panel_bottom, getWidth(), panel_bottom, 1.0f);
        }
    }

    // Overview/minimap bar: shows the full timeline, the current view window,
    // and the playback cursor. Clicking/dragging pans the notes view.
    // (VST plugins have read-only transport — the host playhead cannot be moved
    //  programmatically, but the plugin view can navigate the whole song.)
    {
        // Dynamically size the total range to fit all known content + some headroom
        float data_end = _proc.get_manual_tune().get_time_len();
        _scrub_view_total = juce::jmax(60.f, juce::jmax(_cur_time * 1.2f, data_end * 1.1f));
        _scrub_view_total = juce::jmin(_scrub_view_total, (float)_time_max_len);

        auto t2sx = [&](float t) -> float {
            return _draw_x + t / _scrub_view_total * _draw_w;
        };

        // Background
        g.setColour(juce::Colour(0xff151d22));
        g.fillRect(_draw_x, _scrub_bar_y, _draw_w, _scrub_bar_h);

        // Current view window highlight
        float vx0 = juce::jmax((float)_draw_x,          t2sx(_time_left));
        float vx1 = juce::jmin((float)(_draw_x + _draw_w), t2sx(_time_right));
        g.setColour(juce::Colours::white.withAlpha(0.18f));
        g.fillRect((int)vx0, _scrub_bar_y, (int)(vx1 - vx0), _scrub_bar_h);

        // Playhead in the minimap
        float px = t2sx(_cur_time);
        if (px >= (float)_draw_x && px <= (float)(_draw_x + _draw_w))
        {
            float top = (float)_scrub_bar_y;
            float bot = (float)(_scrub_bar_y + _scrub_bar_h);
            g.setColour(juce::Colours::red);
            g.drawLine(px, top, px, bot, 1.5f);
            juce::Path tri;
            tri.addTriangle(px - 4.f, top + 1.f, px + 4.f, top + 1.f, px, bot - 1.f);
            g.fillPath(tri);
        }

        // Border
        g.setColour(juce::Colours::white.withAlpha(0.12f));
        g.drawRect(_draw_x, _scrub_bar_y, _draw_w, _scrub_bar_h, 1);
    }

    //[UserPaint] Add your own custom painting code here..
    //draw note grid
    {
        g.setOpacity(1.0);
        const char *node_name[12] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"};

        // Accidental (black key) note indices in the A=0 chromatic system:
        // Bb=1, Db=4, Eb=6, Gb=9, Ab=11
        auto is_accidental = [](int pitch) -> bool {
            int n = (pitch % 12 + 12) % 12;
            return n == 1 || n == 4 || n == 6 || n == 9 || n == 11;
        };

        // Draw alternating row backgrounds centered on each pitch (±0.5 semitone bands).
        // Separator lines fall at half-semitone boundaries between bands.
        for (int i = _pitch_down; i <= _pitch_up; i++)
        {
            // Each band spans from pitch-0.5 to pitch+0.5 (centered on the note)
            float y_bottom = _pitch_to_y(i - 0.5f);
            float y_top    = _pitch_to_y(i + 0.5f);
            // Clamp to draw area
            y_top    = juce::jmax(y_top,    (float)_draw_y);
            y_bottom = juce::jmin(y_bottom, (float)(_draw_y + _draw_h));

            if (is_accidental(i))
                g.setColour(_proc.get_color_theme().noteAccidental);
            else
                g.setColour(_proc.get_color_theme().noteNatural);

            g.fillRect((float)_draw_x, y_top, (float)_draw_w, y_bottom - y_top);
        }

        // For each pitch band:
        //   - separator lines at ±0.5 semitone boundaries (between bands)
        //   - a reference line at the exact tuned pitch (center of the band)
        //   - label centered in the band
        for (int i = _pitch_down; i <= _pitch_up; i++)
        {
            float y_center = _pitch_to_y(i);
            float y_sep    = round(_pitch_to_y(i + 0.5f)) + 0.5f;

            // Separator line at the top boundary of this band (between i and i+1)
            g.setColour(_proc.get_color_theme().separatorLine);
            g.drawLine(_draw_x, y_sep, _draw_x + _draw_w, y_sep, 1.0f);

            // Tuned-pitch reference line at the center of the band (exact pitch)
            float y_ref = round(y_center) + 0.5f;
            g.setColour(_proc.get_color_theme().pitchRefLine);
            g.drawLine(_draw_x, y_ref, _draw_x + _draw_w, y_ref, 0.7f);

            // Label centered vertically in the band
            if (_notes[(unsigned)(i + 12 * 8) % 12] > 0)
                g.setColour(juce::Colours::white);
            else
                g.setColour(juce::Colours::grey);

            if ((i + 12 * 8) % 12 == 3)
            {
                std::int32_t n = (i + 9 + 12 * 4) / 12;
                char name[32];
                snprintf(name, sizeof(name), "%s%d", node_name[(unsigned)(i + 12 * 8) % 12], n);
                g.drawText(name, _draw_x - 24, (int)(y_center - 12), 24, 24, juce::Justification::centred, true);
            }
            else
            {
                g.drawText(node_name[(unsigned)(i + 12 * 8) % 12], _draw_x - 24, (int)(y_center - 12), 24, 24, juce::Justification::centred, true);
            }
        }
    }

    // draw position
    {
        bool is_playing = _proc.is_playing();

        _cur_time = _proc.get_cur_time();
        if (is_playing)
        {
            float diff = _time_right - _time_left;
            if (_cur_time >= _time_right || _cur_time <= _time_left)
            {
                _time_left = _cur_time - diff * 0.1;
                _time_right = _time_left + diff;
            }
        }

        float x = _time_to_x(_cur_time);
        float y1 = _pitch_to_y(_pitch_up);
        float y2 = _pitch_to_y(_pitch_down);
        if (x > _draw_x && x < _draw_x + _draw_w)
        {
            g.setColour (_proc.get_color_theme().playhead);
            g.drawLine(x, y1, x, y2, 1);
        }

    }

    // draw measure and beat grid
    {
        double bpm = _proc.get_bpm();
        if (bpm > 0.0)
        {
            int numerator = _proc.get_time_sig_numerator();
            if (numerator <= 0) numerator = 4;

            double beat_len  = 60.0 / bpm;
            double ppq_time  = _cur_time - _proc.get_ppq_position() * beat_len;

            float y1 = _pitch_to_y(_pitch_up);
            float y2 = _pitch_to_y(_pitch_down);

            // first beat index at or before _time_left
            long long first_bi = (long long)floor((_time_left - ppq_time) / beat_len) - 1;

            float label_font_size = juce::jmax(9.0f, 11.0f * (float)getWidth() / 860.0f);
            g.setFont(Font(label_font_size));

            for (long long bi = first_bi; ; ++bi)
            {
                double t = ppq_time + bi * beat_len;
                if (t > _time_right) break;

                float x = _time_to_x((float)t);
                if (x < _draw_x || x > _draw_x + _draw_w) continue;

                // beat position within measure (handles negative bi correctly)
                int beat_in_measure = (int)(((bi % numerator) + numerator) % numerator);
                bool is_measure_start = (beat_in_measure == 0);

                if (is_measure_start)
                {
                    g.setColour(_proc.get_color_theme().measureLine.withAlpha(0.45f));
                    g.drawLine(x, y1, x, y2, 1.0f);

                    // 1-based measure number (floor division for correct negative handling)
                    long long measure_num = (long long)floor((double)bi / numerator) + 1;
                    if (measure_num >= 1)
                    {
                        g.setColour(_proc.get_color_theme().measureLine.withAlpha(0.65f));
                        g.drawText(String(measure_num),
                                   (int)x + 2, _draw_y + 2,
                                   40, (int)label_font_size + 4,
                                   Justification::centredLeft, false);
                    }
                }
                else
                {
                    g.setColour(juce::Colours::white.withAlpha(0.12f));
                    g.drawLine(x, y1, x, y2, 0.5f);
                }
            }
        }
    }

    // draw selected note
    if (_new_tune || _modify_tune)
    {
        float start_x = _time_to_x(_cur_node->time_start);
        float end_x = _time_to_x(_cur_node->time_end);
        float start_y = _pitch_to_y(_cur_node->pitch_start);
        float end_y = _pitch_to_y(_cur_node->pitch_end);
        _draw_note_limit(start_x, start_y, end_x, end_y);
        g.setColour (juce::Colours::red);
        g.setOpacity(0.5);
        g.drawLine(start_x, start_y, end_x, end_y, 12);


        {
            int x = end_x;
            int y = end_y;
            int width = 80;
            int height = 30;

            char str[32] = {0};
            if (_cur_node->time_end > _cur_node->time_start)
            {
                snprintf(str, sizeof(str), "%u(ms)", (std::uint32_t)((_cur_node->time_end - _cur_node->time_start) * 1000));
            }
            else
            {
                snprintf(str, sizeof(str), "%u(ms)", (std::uint32_t)((_cur_node->time_start - _cur_node->time_end) * 1000));
            }

            String text (str);
            Colour fillColour = Colours::black;
            g.setColour (fillColour);
            g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
            g.drawText (text, x, y, width, height,
                        Justification::centred, true);
        }


    }

    // draw notes
    {
        std::list<std::shared_ptr<manual_tune::tune_node> > list =
            _proc.get_manual_tune().get_tune(_time_left, _time_right);


        g.setColour (_proc.get_color_theme().tuneNodes);
        g.setOpacity(0.5);
        for (auto i: list)
        {
            float start_x = _time_to_x(i->time_start);
            float end_x = _time_to_x(i->time_end);
            float start_y = _pitch_to_y(i->pitch_start);
            float end_y = _pitch_to_y(i->pitch_end);

            _draw_note_limit(start_x, start_y, end_x, end_y);
            g.drawLine(start_x, start_y, end_x, end_y, 12);
        }
    }

    //draw inpitch line
    {
        std::list<std::pair<manual_tune::pitch_node, float> > pitch_list = _proc.get_manual_tune().get_inpitch(_time_left, _time_right);
        Path pitch_path;
        bool flag = true;
        for (auto i: pitch_list)
        {
            manual_tune::pitch_node& node = i.first;
            float time = i.second;
            float x = _time_to_x(time);
            float y = _pitch_to_y(node.pitch);

            if ((x > _draw_x && x < _draw_x + _draw_w && y > _draw_y && y < _draw_y + _draw_h) &&
                node.conf > _proc.get_mt_tune()->get_conf_shift_thresh())
            {
                if (flag)
                {
                    flag = false;
                    pitch_path.startNewSubPath (x, y);
                }
                else
                {
                    pitch_path.lineTo(x, y);
                }
            }
            else
            {
                flag = true;
            }
        }


        g.setColour (_proc.get_color_theme().inPitch);
        g.strokePath (pitch_path, PathStrokeType (2.0f));
    }

    // draw outpitch line
    {
        std::list<std::pair<manual_tune::pitch_node, float> > pitch_list = _proc.get_mt_tune()->get_outpitch(_time_left, _time_right);
        Path pitch_path;
        bool flag = true;
        for (auto i: pitch_list)
        {
            manual_tune::pitch_node& node = i.first;
            float time = i.second;
            float x = _time_to_x(time);
            float y = _pitch_to_y(node.pitch);

            if ((x > _draw_x && x < _draw_x + _draw_w && y > _draw_y && y < _draw_y + _draw_h) &&
                node.conf > _proc.get_mt_tune()->get_conf_shift_thresh())
            {
                if (flag)
                {
                    flag = false;
                    pitch_path.startNewSubPath (x, y);
                }
                else
                {
                    pitch_path.lineTo(x, y);
                }
            }
            else
            {
                flag = true;
            }
        }

        g.setColour (_proc.get_color_theme().outPitch);
        g.strokePath (pitch_path, PathStrokeType (1.5f));
    }

    //[/UserPaint]
}

void PluginGui::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    float sx = (float)getWidth()  / 860.0f;
    float sy = (float)getHeight() / 600.0f;

    auto sc = [&](int x, int y, int w, int h) -> juce::Rectangle<int> {
        return { (int)roundf (x * sx), (int)roundf (y * sy),
                 (int)roundf (w * sx), (int)roundf (h * sy) };
    };

    // All legacy group chrome hidden — layout is now flat top-bar + notes
    groupComponent->setVisible  (false);
    groupComponent4->setVisible (false);
    groupComponent2->setVisible (false);
    groupComponent3->setVisible (false);
    groupComponent5->setVisible (false);
    groupComponent6->setVisible (false);

    // ── Top bar (y=8, h=24 in base coords) ──────────────────────────────────
    toggleButtonAutoTune->setVisible (true);
    toggleButtonTrack->setVisible    (true);
    toggleButtonSnap->setVisible     (true);
    comboBoxKey->setVisible          (true);
    comboBoxKeyType->setVisible      (true);
    textButtonUndoNote->setVisible   (true);
    textButtonRedoNote->setVisible   (true);
    textButtonSnapKey->setVisible    (true);
    textButtonMore->setVisible       (true);

    toggleButtonAutoTune->setBounds (sc (4,   8, 78, 24));
    toggleButtonTrack->setBounds    (sc (86,  8, 52, 24));
    toggleButtonSnap->setBounds     (sc (142, 8, 52, 24));
    comboBoxKey->setBounds          (sc (202, 8, 68, 24));
    comboBoxKeyType->setBounds      (sc (274, 8, 84, 24));
    textButtonUndoNote->setBounds   (sc (370, 8, 52, 24));
    textButtonRedoNote->setBounds   (sc (426, 8, 52, 24));
    textButtonSnapKey->setBounds    (sc (486, 8, 72, 24));
    textButtonMore->setBounds       (sc (796, 8, 56, 24));

    // ── More panel (y=40..120, visible only when _more_open) ────────────────
    const int MY = 40;
    const bool sm = _more_open;

    label7->setVisible           (sm);  sliderATSmooth->setVisible   (sm);
    label8->setVisible           (sm);  sliderATAmount->setVisible   (sm);
    label4->setVisible           (sm);  sliderAttack->setVisible     (sm);
    label5->setVisible           (sm);  sliderRelease->setVisible    (sm);
    label6->setVisible           (sm);  sliderAmount->setVisible     (sm);
    label3->setVisible           (sm);  sliderMinLen->setVisible     (sm);
    label11->setVisible          (sm);  sliderMaxInterval->setVisible(sm);
    textButtonSetting->setVisible(sm);
    textButtonDetectKey->setVisible  (sm);
    textButtonCANote->setVisible     (sm);
    textButtonClearNote->setVisible  (sm);
    textButtonClearPitch->setVisible (sm);
    toggleButtonNoteA->setVisible    (sm);
    toggleButtonNoteBb->setVisible   (sm);
    toggleButtonNoteB->setVisible    (sm);
    toggleButtonNoteC->setVisible    (sm);
    toggleButtonNoteDb->setVisible   (sm);
    toggleButtonNoteD->setVisible    (sm);
    toggleButtonNoteEb->setVisible   (sm);
    toggleButtonNoteE->setVisible    (sm);
    toggleButtonNoteF->setVisible    (sm);
    toggleButtonNoteGb->setVisible   (sm);
    toggleButtonNoteG->setVisible    (sm);
    toggleButtonNoteAb->setVisible   (sm);

    if (sm)
    {
        // Row 1 (y = MY+12): AT smooth/amount, tuning attack/release/amount, snap length/interval, setting
        label7->setBounds            (sc (4,   MY+12, 52, 24));  // Smooth:
        sliderATSmooth->setBounds    (sc (58,  MY+12, 44, 24));
        label8->setBounds            (sc (106, MY+12, 52, 24));  // Amount:
        sliderATAmount->setBounds    (sc (162, MY+12, 44, 24));
        label4->setBounds            (sc (214, MY+12, 68, 24));  // Attack(ms)
        sliderAttack->setBounds      (sc (286, MY+12, 52, 24));
        label5->setBounds            (sc (342, MY+12, 68, 24));  // Release(ms)
        sliderRelease->setBounds     (sc (414, MY+12, 52, 24));
        label6->setBounds            (sc (470, MY+12, 52, 24));  // Amount
        sliderAmount->setBounds      (sc (526, MY+12, 52, 24));
        label3->setBounds            (sc (584, MY+12, 52, 24));  // Length:
        sliderMinLen->setBounds      (sc (640, MY+12, 44, 24));
        label11->setBounds           (sc (688, MY+12, 56, 24));  // Interval:
        sliderMaxInterval->setBounds (sc (748, MY+12, 44, 24));
        textButtonSetting->setBounds (sc (800, MY+12, 52, 24));

        // Row 2 (y = MY+44): 12 note toggles + action buttons
        toggleButtonNoteA->setBounds   (sc (4,   MY+44, 36, 24));
        toggleButtonNoteBb->setBounds  (sc (40,  MY+44, 36, 24));
        toggleButtonNoteB->setBounds   (sc (76,  MY+44, 36, 24));
        toggleButtonNoteC->setBounds   (sc (112, MY+44, 36, 24));
        toggleButtonNoteDb->setBounds  (sc (148, MY+44, 36, 24));
        toggleButtonNoteD->setBounds   (sc (184, MY+44, 36, 24));
        toggleButtonNoteEb->setBounds  (sc (220, MY+44, 36, 24));
        toggleButtonNoteE->setBounds   (sc (256, MY+44, 36, 24));
        toggleButtonNoteF->setBounds   (sc (292, MY+44, 36, 24));
        toggleButtonNoteGb->setBounds  (sc (328, MY+44, 36, 24));
        toggleButtonNoteG->setBounds   (sc (364, MY+44, 36, 24));
        toggleButtonNoteAb->setBounds  (sc (400, MY+44, 36, 24));
        textButtonDetectKey->setBounds (sc (444, MY+44, 64, 24));
        textButtonCANote->setBounds    (sc (512, MY+44, 76, 24));
        textButtonClearNote->setBounds (sc (592, MY+44, 60, 24));
        textButtonClearPitch->setBounds(sc (656, MY+44, 60, 24));
    }
    //[/UserResized]
}

void PluginGui::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == sliderAttack.get())
    {
        //[UserSliderCode_sliderAttack] -- add your slider handling code here..
        if (_cur_node)
        {
            _cur_node->attack = sliderThatWasMoved->getValue() / 1000.;
        }
        else
        {
            _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_ATTACK, sliderThatWasMoved->getValue() / 1000.);
        }
        //[/UserSliderCode_sliderAttack]
    }
    else if (sliderThatWasMoved == sliderRelease.get())
    {
        //[UserSliderCode_sliderRelease] -- add your slider handling code here..
        if (_cur_node)
        {
            _cur_node->release = sliderThatWasMoved->getValue() / 1000.;
        }
        else
        {
            _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_RELEASE, sliderThatWasMoved->getValue() / 1000.);
        }
        //[/UserSliderCode_sliderRelease]
    }
    else if (sliderThatWasMoved == sliderAmount.get())
    {
        //[UserSliderCode_sliderAmount] -- add your slider handling code here..
        if (_cur_node)
        {
            _cur_node->amount = sliderThatWasMoved->getValue();
        }
        else
        {
            _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_AMOUNT, sliderThatWasMoved->getValue());
        }
        //[/UserSliderCode_sliderAmount]
    }
    else if (sliderThatWasMoved == sliderATSmooth.get())
    {
        //[UserSliderCode_sliderATSmooth] -- add your slider handling code here..
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_AT_SMOOTH, sliderThatWasMoved->getValue());
        //[/UserSliderCode_sliderATSmooth]
    }
    else if (sliderThatWasMoved == sliderATAmount.get())
    {
        //[UserSliderCode_sliderATAmount] -- add your slider handling code here..
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_AT_AMOUNT, sliderThatWasMoved->getValue());
        //[/UserSliderCode_sliderATAmount]
    }
    else if (sliderThatWasMoved == sliderMinLen.get())
    {
        //[UserSliderCode_sliderMinLen] -- add your slider handling code here..
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MIN_LENGHT, sliderThatWasMoved->getValue() / 1000.);
        //[/UserSliderCode_sliderMinLen]
    }
    else if (sliderThatWasMoved == sliderMaxInterval.get())
    {
        //[UserSliderCode_sliderMaxInterval] -- add your slider handling code here..
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MAX_INTERVAL, sliderThatWasMoved->getValue() / 1000.);
        //[/UserSliderCode_sliderMaxInterval]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PluginGui::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButtonTrack.get())
    {
        //[UserButtonCode_toggleButtonTrack] -- add your button handler code here..
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_ENABLE_TRACK, buttonThatWasClicked->getToggleState()? 1.: 0.);
        //[/UserButtonCode_toggleButtonTrack]
    }
    else if (buttonThatWasClicked == toggleButtonAutoTune.get())
    {
        //[UserButtonCode_toggleButtonAutoTune] -- add your button handler code here..
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_ENABLE_AUTOTUNE, buttonThatWasClicked->getToggleState()? 1.: 0.);
        //[/UserButtonCode_toggleButtonAutoTune]
    }
    else if (buttonThatWasClicked == toggleButtonNoteA.get())
    {
        //[UserButtonCode_toggleButtonNoteA] -- add your button handler code here..
        _notes[_key_A] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_A, (_notes[_key_A] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteA]
    }
    else if (buttonThatWasClicked == toggleButtonNoteBb.get())
    {
        //[UserButtonCode_toggleButtonNoteBb] -- add your button handler code here..
        _notes[_key_Bb] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Bb, (_notes[_key_Bb] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteBb]
    }
    else if (buttonThatWasClicked == toggleButtonNoteB.get())
    {
        //[UserButtonCode_toggleButtonNoteB] -- add your button handler code here..
        _notes[_key_B] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_B, (_notes[_key_B] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteB]
    }
    else if (buttonThatWasClicked == toggleButtonNoteC.get())
    {
        //[UserButtonCode_toggleButtonNoteC] -- add your button handler code here..
        _notes[_key_C] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_C, (_notes[_key_C] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteC]
    }
    else if (buttonThatWasClicked == toggleButtonNoteDb.get())
    {
        //[UserButtonCode_toggleButtonNoteDb] -- add your button handler code here..
        _notes[_key_Db] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Db, (_notes[_key_Db] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteDb]
    }
    else if (buttonThatWasClicked == toggleButtonNoteD.get())
    {
        //[UserButtonCode_toggleButtonNoteD] -- add your button handler code here..
        _notes[_key_D] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_D, (_notes[_key_D] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteD]
    }
    else if (buttonThatWasClicked == toggleButtonNoteEb.get())
    {
        //[UserButtonCode_toggleButtonNoteEb] -- add your button handler code here..
        _notes[_key_Eb] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Eb, (_notes[_key_Eb] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteEb]
    }
    else if (buttonThatWasClicked == toggleButtonNoteE.get())
    {
        //[UserButtonCode_toggleButtonNoteE] -- add your button handler code here..
        _notes[_key_E] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_E, (_notes[_key_E] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteE]
    }
    else if (buttonThatWasClicked == toggleButtonNoteF.get())
    {
        //[UserButtonCode_toggleButtonNoteF] -- add your button handler code here..
        _notes[_key_F] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_F, (_notes[_key_F] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteF]
    }
    else if (buttonThatWasClicked == toggleButtonNoteGb.get())
    {
        //[UserButtonCode_toggleButtonNoteGb] -- add your button handler code here..
        _notes[_key_Gb] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Gb, (_notes[_key_Gb] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteGb]
    }
    else if (buttonThatWasClicked == toggleButtonNoteAb.get())
    {
        //[UserButtonCode_toggleButtonNoteAb] -- add your button handler code here..
        _notes[_key_Ab] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Ab, (_notes[_key_Ab] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteAb]
    }
    else if (buttonThatWasClicked == toggleButtonNoteG.get())
    {
        //[UserButtonCode_toggleButtonNoteG] -- add your button handler code here..
        _notes[_key_G] = buttonThatWasClicked->getToggleState()? 1: -1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_G, (_notes[_key_G] > 0)? 1.: 0.);
        _key = _key_custom;
        _key_type = _key_type_custom;
        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        //[/UserButtonCode_toggleButtonNoteG]
    }
    else if (buttonThatWasClicked == textButtonSnapKey.get())
    {
        //[UserButtonCode_textButtonSnapKey] -- add your button handler code here..

        float attack = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_ATTACK);
        float release = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_RELEASE);
        float amount = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_AMOUNT);
        float min_length = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MIN_LENGHT);
        float max_interval = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MAX_INTERVAL);

        _proc.get_mt_tune()->snap_key(min_length, max_interval, attack, release, amount);
        //[/UserButtonCode_textButtonSnapKey]
    }
    else if (buttonThatWasClicked == textButtonClearPitch.get())
    {
        //[UserButtonCode_textButtonClearPitch] -- add your button handler code here..
        _proc.get_mt_tune()->clear_pitch();
        //[/UserButtonCode_textButtonClearPitch]
    }
    else if (buttonThatWasClicked == toggleButtonSnap.get())
    {
        //[UserButtonCode_toggleButtonSnap] -- add your button handler code here..
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP, buttonThatWasClicked->getToggleState()? 1: 0);
        //[/UserButtonCode_toggleButtonSnap]
    }
    else if (buttonThatWasClicked == textButtonClearNote.get())
    {
        //[UserButtonCode_textButtonClearNote] -- add your button handler code here..
        _proc.get_mt_tune()->clear_note();
        //[/UserButtonCode_textButtonClearNote]
    }
    else if (buttonThatWasClicked == textButtonCANote.get())
    {
        //[UserButtonCode_textButtonCANote] -- add your button handler code here..
        _proc.get_manual_tune().clear_auto_note();
        //[/UserButtonCode_textButtonCANote]
    }
    else if (buttonThatWasClicked == textButtonDetectKey.get())
    {
        //[UserButtonCode_textButtonDetectKey] -- add your button handler code here..
        float min_length = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MIN_LENGHT);
        float max_interval = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MAX_INTERVAL);

        float notes_weights[12];
        if (_proc.get_manual_tune().check_key(notes_weights, min_length, max_interval))
        {
            std::int32_t notes[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
            std::int32_t key = _key_custom;
            KeyDetectGui component(notes_weights, notes, key);

            std::int32_t r = juce::DialogWindow::showModalDialog("Key Detect", &component, 0, juce::Colours::whitesmoke, false, false, false);
            if (r > 0)
            {
                if (key == _key_custom)
                {
                    _key = _key_custom;
                    _key_type = _key_type_custom;
                }
                else
                {
                    _key = key;
                    _key_type = _key_type_major;
                }

                for (std::int32_t i = 0; i < 12; i++)
                {
                    _notes[i] = notes[i];
                }

                comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
                comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);

                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);


                toggleButtonNoteA->setToggleState((_notes[0] > 0), dontSendNotification);
                toggleButtonNoteBb->setToggleState((_notes[1] > 0), dontSendNotification);
                toggleButtonNoteB->setToggleState((_notes[2] > 0), dontSendNotification);
                toggleButtonNoteC->setToggleState((_notes[3] > 0), dontSendNotification);
                toggleButtonNoteDb->setToggleState((_notes[4] > 0), dontSendNotification);
                toggleButtonNoteD->setToggleState((_notes[5] > 0), dontSendNotification);
                toggleButtonNoteEb->setToggleState((_notes[6] > 0), dontSendNotification);
                toggleButtonNoteE->setToggleState((_notes[7] > 0), dontSendNotification);
                toggleButtonNoteF->setToggleState((_notes[8] > 0), dontSendNotification);
                toggleButtonNoteGb->setToggleState((_notes[9] > 0), dontSendNotification);
                toggleButtonNoteG->setToggleState((_notes[10] > 0), dontSendNotification);
                toggleButtonNoteAb->setToggleState((_notes[11] > 0), dontSendNotification);


                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_A, (_notes[0] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Bb, (_notes[1] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_B, (_notes[2] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_C, (_notes[3] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Db, (_notes[4] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_D, (_notes[5] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Eb, (_notes[6] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_E, (_notes[7] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_F, (_notes[8] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Gb, (_notes[9] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_G, (_notes[10] > 0)? 1.: 0.);
                _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Ab, (_notes[11] > 0)? 1.: 0.);
            }
        }
        //[/UserButtonCode_textButtonDetectKey]
    }
    else if (buttonThatWasClicked == textButtonSetting.get())
    {
        //[UserButtonCode_textButtonSetting] -- add your button handler code here..
        SettingGui component(_proc);
        juce::DialogWindow::showModalDialog("Settings", &component, 0, juce::Colours::whitesmoke, false, false, false);
        //[/UserButtonCode_textButtonSetting]
    }
    else if (buttonThatWasClicked == textButtonUndoNote.get())
    {
        //[UserButtonCode_textButtonUndoNote] -- add your button handler code here..
        if (_modify_tune)
        {
            _cur_node->attack = sliderAttack->getValue() / 1000.;
            _cur_node->release = sliderRelease->getValue() / 1000.;
            _cur_node->amount = sliderAmount->getValue();
            _proc.get_manual_tune().unselect_tune();
            _cur_node.reset();
            _modify_tune = false;
        }
        _proc.get_mt_tune()->undo();
        //[/UserButtonCode_textButtonUndoNote]
    }
    else if (buttonThatWasClicked == textButtonRedoNote.get())
    {
        //[UserButtonCode_textButtonRedoNote] -- add your button handler code here..
        if (_modify_tune)
        {
            _cur_node->attack = sliderAttack->getValue() / 1000.;
            _cur_node->release = sliderRelease->getValue() / 1000.;
            _cur_node->amount = sliderAmount->getValue();
            _proc.get_manual_tune().unselect_tune();
            _cur_node.reset();
            _modify_tune = false;
        }
        _proc.get_mt_tune()->redo();
        //[/UserButtonCode_textButtonRedoNote]
    }

    else if (buttonThatWasClicked == textButtonMore.get())
    {
        _more_open = !_more_open;
        textButtonMore->setButtonText(_more_open ? TRANS("Less ^") : TRANS("More v"));
        resized();
        repaint();
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void PluginGui::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBoxKey.get())
    {
        //[UserComboBoxCode_comboBoxKey] -- add your combo box handling code here..
        _key = comboBoxThatHasChanged->getSelectedId() - 1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY, _key);
        _update_notes();
        //[/UserComboBoxCode_comboBoxKey]
    }
    else if (comboBoxThatHasChanged == comboBoxKeyType.get())
    {
        //[UserComboBoxCode_comboBoxKeyType] -- add your combo box handling code here..
        _key_type = comboBoxThatHasChanged->getSelectedId() - 1;
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE, _key_type);
        _update_notes();
        //[/UserComboBoxCode_comboBoxKeyType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void PluginGui::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    std::int32_t x = e.getMouseDownX();
    std::int32_t y = e.getMouseDownY();
    _mouse_down_time = _x_to_time(x);

    // Minimap bar: left-click/drag pans the notes view to that song position
    if (e.mods.isLeftButtonDown()
        && y >= _scrub_bar_y && y < _scrub_bar_y + _scrub_bar_h
        && x >= _draw_x && x <= _draw_x + _draw_w)
    {
        _scrub_dragging = true;
        float t = _scrub_view_total * (x - _draw_x) / (float)_draw_w;
        float diff = _time_right - _time_left;
        _time_left  = juce::jmax(0.f, t - diff * 0.5f);
        _time_right = _time_left + diff;
        if (_time_right > _time_max_len) { _time_right = _time_max_len; _time_left = juce::jmax(0.f, _time_right - diff); }
        repaint();
        return;
    }

    if (e.mods.isLeftButtonDown())
    {
        if (_modify_tune)
        {
            _cur_node->attack = sliderAttack->getValue() / 1000.;
            _cur_node->release = sliderRelease->getValue() / 1000.;
            _cur_node->amount = sliderAmount->getValue();
            _proc.get_manual_tune().unselect_tune();
            _cur_node.reset();
            _modify_tune = false;
        }

        _cur_node = _proc.get_manual_tune().select_tune(_x_to_time(e.getMouseDownX()), _y_to_pitch(e.getMouseDownY()), _select_pos);
        if (_cur_node)
        {
            _modify_tune = true;
            sliderAttack->setValue(_cur_node->attack * 1000);
            sliderRelease->setValue(_cur_node->release * 1000);
            sliderAmount->setValue(_cur_node->amount);
            if (_select_pos == manual_tune::SELECT_MID || _select_pos == manual_tune::SELECT_LEFT)
            {
                _select_xd = _cur_node->time_start - _x_to_time(x);
                _select_yd = _cur_node->pitch_start - _y_to_pitch(y);
            }
            else if (_select_pos == manual_tune::SELECT_RIGHT)
            {
                _select_xd = _cur_node->time_end - _x_to_time(x);
                _select_yd = _cur_node->pitch_end - _y_to_pitch(y);
            }
        }
        else
        {
            sliderAttack->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_ATTACK) * 1000);
            sliderRelease->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_RELEASE) * 1000);
            sliderAmount->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_AMOUNT));
        }

        repaint();
    }

    //[/UserCode_mouseDown]
}

void PluginGui::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    std::int32_t x = e.position.getX();
    std::int32_t y = e.position.getY();

    if (_scrub_dragging)
    {
        float t = _scrub_view_total * (x - _draw_x) / (float)_draw_w;
        float diff = _time_right - _time_left;
        _time_left  = juce::jmax(0.f, t - diff * 0.5f);
        _time_right = _time_left + diff;
        if (_time_right > _time_max_len) { _time_right = _time_max_len; _time_left = juce::jmax(0.f, _time_right - diff); }
        repaint();
        return;
    }

    if (e.mods.isLeftButtonDown())
    {
        if (_mouse_down_time < _time_left || _mouse_down_time > _time_right)
        {
            return;
        }

        if (_modify_tune == false && _new_tune == false && abs(e.getMouseDownX() - x) > 5)
        {
            _new_tune = true;

            _cur_node.reset(new manual_tune::tune_node);
            _cur_node->is_manual = true;
            _cur_node->attack = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_ATTACK);
            _cur_node->release = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_RELEASE);
            _cur_node->amount = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_AMOUNT);
            sliderAttack->setValue(_cur_node->attack * 1000.);
            sliderRelease->setValue(_cur_node->release * 1000.);
            sliderAmount->setValue(_cur_node->amount);

            float pitch = _y_to_pitch(e.getMouseDownY());
            float time = _x_to_time(e.getMouseDownX());
            pitch = _snap_pitch(pitch);

            _cur_node->pitch_start = pitch;


            _cur_node->pitch_end = _cur_node->pitch_start;
            _cur_node->time_start = time;
            _cur_node->time_end = _cur_node->time_start;
        }

        if (_new_tune)
        {
            _cur_node->time_end = _x_to_time(x);

            if (_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP) > 0.)
            {
                _cur_node->pitch_end = _cur_node->pitch_start;
            }
            else
            {
                _cur_node->pitch_end = _y_to_pitch(y);
            }
        }
        else if (_modify_tune)
        {
            _cur_node->is_manual = true;
            if (_select_pos == manual_tune::SELECT_MID)
            {
                float time_start = _x_to_time(x) + _select_xd;
                float time_end = time_start + _cur_node->time_end - _cur_node->time_start;
                _cur_node->time_start = time_start;
                _cur_node->time_end = time_end;

                float pitch_start = _y_to_pitch(y) + _select_yd;
                pitch_start = _snap_pitch(pitch_start);

                if (abs(pitch_start - _cur_node->pitch_start) > 0.001)
                {
                    float pitch_end = pitch_start + _cur_node->pitch_end - _cur_node->pitch_start;
                    _cur_node->pitch_start = pitch_start;
                    _cur_node->pitch_end = pitch_end;
                }
            }
            else if (_select_pos == manual_tune::SELECT_LEFT)
            {
                float time_start = _x_to_time(x) + _select_xd;
                _cur_node->time_start = time_start;

                float pitch_start = _y_to_pitch(y) + _select_yd;
                pitch_start = _snap_pitch(pitch_start);

                if (abs(pitch_start - _cur_node->pitch_start) > 0.001)
                {
                    _cur_node->pitch_start = pitch_start;
                }
            }
            else if (_select_pos == manual_tune::SELECT_RIGHT)
            {
                float time_end = _x_to_time(x) + _select_xd;
                _cur_node->time_end = time_end;

                float pitch_end = _y_to_pitch(y) + _select_yd;
                pitch_end = _snap_pitch(pitch_end);

                if (abs(pitch_end - _cur_node->pitch_end) > 0.001)
                {
                    _cur_node->pitch_end = pitch_end;
                }
            }
        }

        repaint();
    }

    //[/UserCode_mouseDrag]
}

void PluginGui::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...

    if (_scrub_dragging)
    {
        _scrub_dragging = false;
        float t = _scrub_view_total * (e.position.getX() - _draw_x) / (float)_draw_w;
        float diff = _time_right - _time_left;
        _time_left  = juce::jmax(0.f, t - diff * 0.5f);
        _time_right = _time_left + diff;
        if (_time_right > _time_max_len) { _time_right = _time_max_len; _time_left = juce::jmax(0.f, _time_right - diff); }
        repaint();
        return;
    }

    if (e.mods.isLeftButtonDown())
    {
        if (_modify_tune == false && _new_tune == false)
        {
            _cur_time = _x_to_time(e.position.getX());
        }

        if (_new_tune)
        {
            _new_tune = false;
            _modify_tune = false;
            _proc.get_manual_tune().add_tune(_cur_node);
            _cur_node = _proc.get_manual_tune().select_tune(_cur_node->time_start, _cur_node->pitch_start, _select_pos);
            _select_pos = manual_tune::SELECT_NONE;
            if (_cur_node)
            {
                _modify_tune = true;
            }
        }
        repaint();
    }
    else if (e.mods.isRightButtonDown())
    {
        if (_modify_tune)
        {
            _cur_node.reset();
            _proc.get_manual_tune().del_selected();
            _modify_tune = false;
        }
        else if (_new_tune)
        {
            _cur_node.reset();
            _new_tune = false;
        }
        else
        {
            _cur_node = _proc.get_manual_tune().select_tune(_x_to_time(e.getMouseDownX()), _y_to_pitch(e.getMouseDownY()), _select_pos);
            if (_cur_node)
            {
                _cur_node.reset();
                _proc.get_manual_tune().del_selected();
            }
        }
        repaint();
    }
    //[/UserCode_mouseUp]
}

void PluginGui::mouseWheelMove (const MouseEvent& /*e*/, const MouseWheelDetails& wheel)
{
    //[UserCode_mouseWheelMove] -- Add your code here...
#if 0
    if (_modify_tune)
    {
        if (!_is_ctrl && !_is_shift && !_is_alt)
        {
            if (wheel.deltaY > 0)
            {
                _cur_node->amount += sliderAmount->getInterval();
                if (_cur_node->amount > sliderAmount->getMaximum())
                {
                    _cur_node->amount = sliderAmount->getMaximum();
                }
            }
            else
            {
                _cur_node->amount -= sliderAmount->getInterval();
                if (_cur_node->amount < sliderAmount->getMinimum())
                {
                    _cur_node->amount = sliderAmount->getMinimum();
                }
            }
            sliderAmount->setValue(_cur_node->amount);
        }
        else if (_is_ctrl && !_is_shift && !_is_alt)
        {
            float attack = _cur_node->attack * 1000.;
            if (wheel.deltaY > 0)
            {
                attack += sliderAttack->getInterval();
                if (attack > sliderAttack->getMaximum())
                {
                    attack = sliderAttack->getMaximum();
                }
            }
            else
            {
                attack -= sliderAttack->getInterval();
                if (attack < sliderAttack->getMinimum())
                {
                    attack = sliderAttack->getMinimum();
                }
            }
            sliderAttack->setValue(attack);
            _cur_node->attack = attack / 1000.;
        }
        else if (!_is_ctrl && !_is_shift && _is_alt)
        {
            float release = _cur_node->release * 1000.;
            if (wheel.deltaY > 0)
            {
                release += sliderRelease->getInterval();
                if (release > sliderRelease->getMaximum())
                {
                    release = sliderRelease->getMaximum();
                }
            }
            else
            {
                release -= sliderRelease->getInterval();
                if (release < sliderRelease->getMinimum())
                {
                    release = sliderRelease->getMinimum();
                }
            }
            sliderRelease->setValue(release);
            _cur_node->release = release / 1000.;
        }
        return;
    }
#endif


    // x zoom
    if (!_is_ctrl && !_is_shift && _is_alt)
    {
        _x_zoom(wheel.deltaY > 0);
        repaint();
    }
    else if (!_is_ctrl && _is_shift && !_is_alt) //x move
    {
        _x_move(wheel.deltaY > 0);
        repaint();
    }
    else if (_is_ctrl && !_is_shift && !_is_alt) // y zoom
    {
        _y_zoom(wheel.deltaY > 0);
        repaint();
    }
    else if (!_is_ctrl && !_is_shift && !_is_alt) //y move
    {
        _y_move(wheel.deltaY > 0);
        repaint();
    }
    //[/UserCode_mouseWheelMove]
}

bool PluginGui::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
    if (key == juce::KeyPress::deleteKey)
    {
        if (_modify_tune)
        {
            _cur_node.reset();
            _proc.get_manual_tune().del_selected();
            _modify_tune = false;
        }
        else if (_new_tune)
        {
            _cur_node.reset();
            _new_tune = false;
        }
        else
        {
            //_cur_node = _proc.get_manual_tune().select_tune(_x_to_time(e.getMouseDownX()), _y_to_pitch(e.getMouseDownY()), _select_pos);
        }
        repaint();
        return true;
    }
    else if (key == juce::KeyPress::leftKey)
    {
        _jump_to_measure(false);
        repaint();
        return true;
    }
    else if (key == juce::KeyPress::rightKey)
    {
        _jump_to_measure(true);
        repaint();
        return true;
    }
    else if (key.getKeyCode() == 'A')
    {
        _x_move(true);
        repaint();
    }
    else if (key.getKeyCode() == 'D')
    {
        _x_move(false);
        repaint();
    }
    else if (key.getKeyCode() == 'W')
    {
        _y_move(true);
        repaint();
    }
    else if (key.getKeyCode() == 'S')
    {
        _y_move(false);
        repaint();
    }
    else if (key.getKeyCode() == '-' || key.getKeyCode() == 'Q')
    {
        if (!_is_ctrl)
        {
            _x_zoom(false);
        }
        else
        {
            _y_zoom(false);
        }
        repaint();
    }
    else if (key.getKeyCode() == '=' || key.getKeyCode() == 'E')
    {
        if (!_is_ctrl)
        {
            _x_zoom(true);
        }
        else
        {
            _y_zoom(true);
        }
        repaint();
    }

    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}

void PluginGui::modifierKeysChanged (const ModifierKeys& modifiers)
{
    //[UserCode_modifierKeysChanged] -- Add your code here...
    if (modifiers.isCtrlDown())
    {
        _is_ctrl = true;
    }
    else
    {
        _is_ctrl = false;
    }

    if (modifiers.isShiftDown())
    {
        _is_shift = true;
    }
    else
    {
        _is_shift = false;
    }

    if (modifiers.isAltDown())
    {
        _is_alt = true;
    }
    else
    {
        _is_alt = false;
    }
    //[/UserCode_modifierKeysChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginGui::timerCallback()
{
    repaint();
}

void PluginGui::_update_gui_parameter()
{
    std::uint32_t id = _proc.get_parameters_update_id();
    if (id == _parameter_update_id)
    {
        return;
    }

    _parameter_update_id = _proc.get_parameters_update_id();

    toggleButtonAutoTune->setToggleState(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_ENABLE_AUTOTUNE) > 0., dontSendNotification);
    toggleButtonSnap->setToggleState(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP) > 0., dontSendNotification);
    toggleButtonTrack->setToggleState(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_ENABLE_TRACK) > 0., dontSendNotification);

    sliderAttack->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_ATTACK) * 1000, dontSendNotification);
    sliderRelease->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_RELEASE) * 1000, dontSendNotification);
    sliderAmount->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_DEF_AMOUNT), dontSendNotification);

    sliderATAmount->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_AT_AMOUNT), dontSendNotification);
    sliderATSmooth->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_AT_SMOOTH), dontSendNotification);


    {
        _key = (std::int32_t)std::round(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY));
        _key_type = (std::int32_t)std::round(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_KEY_TYPE));

        comboBoxKey->setSelectedId(_key + 1, dontSendNotification);
        comboBoxKeyType->setSelectedId(_key_type + 1, dontSendNotification);

        _notes[_key_A] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_A) > 0 ? 1: -1;
        _notes[_key_Bb] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_Bb) > 0 ? 1: -1;
        _notes[_key_B] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_B) > 0 ? 1: -1;
        _notes[_key_C] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_C) > 0 ? 1: -1;
        _notes[_key_Db] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_Db) > 0 ? 1: -1;
        _notes[_key_D] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_D) > 0 ? 1: -1;
        _notes[_key_Eb] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_Eb) > 0 ? 1: -1;
        _notes[_key_E] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_E) > 0 ? 1: -1;
        _notes[_key_F] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_F) > 0 ? 1: -1;
        _notes[_key_Gb] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_Gb) > 0 ? 1: -1;
        _notes[_key_G] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_G) > 0 ? 1: -1;
        _notes[_key_Ab] = _proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_Ab) > 0 ? 1: -1;

        toggleButtonNoteA->setToggleState((_notes[_key_A] > 0), dontSendNotification);
        toggleButtonNoteBb->setToggleState((_notes[_key_Bb] > 0), dontSendNotification);
        toggleButtonNoteB->setToggleState((_notes[_key_B] > 0), dontSendNotification);
        toggleButtonNoteC->setToggleState((_notes[_key_C] > 0), dontSendNotification);
        toggleButtonNoteDb->setToggleState((_notes[_key_Db] > 0), dontSendNotification);
        toggleButtonNoteD->setToggleState((_notes[_key_D] > 0), dontSendNotification);
        toggleButtonNoteEb->setToggleState((_notes[_key_Eb] > 0), dontSendNotification);
        toggleButtonNoteE->setToggleState((_notes[_key_E] > 0), dontSendNotification);
        toggleButtonNoteF->setToggleState((_notes[_key_F] > 0), dontSendNotification);
        toggleButtonNoteGb->setToggleState((_notes[_key_Gb] > 0), dontSendNotification);
        toggleButtonNoteG->setToggleState((_notes[_key_G] > 0), dontSendNotification);
        toggleButtonNoteAb->setToggleState((_notes[_key_Ab] > 0), dontSendNotification);

    }

    sliderMinLen->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MIN_LENGHT) * 1000, dontSendNotification);
    sliderMaxInterval->setValue(_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP_MAX_INTERVAL) * 1000, dontSendNotification);
}

float PluginGui::_snap_pitch(float pitch)
{
    std::int32_t i = round(pitch);
    std::int32_t left = i;
    std::int32_t right = i;

    if (_proc.get_parameter(AutotalentAudioProcessor::PARAMETER_ID_SNAP) < 1 || _is_ctrl)
    {
        return pitch;
    }

    std::int32_t *notes = _notes;
    std::int32_t notes_chromatic[12] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    if (_is_alt)
    {
        notes = notes_chromatic;
    }

    for (std::int32_t j = 0; j < 12; j++)
    {
        if (notes[(left + 12 * 8) % 12] < 0)
        {
            left--;
        }
        else
        {
            break;
        }
    }

    for (std::int32_t j = 0; j < 12; j++)
    {
        if (notes[(right + 12 * 8) % 12] < 0)
        {
            right++;
        }
        else
        {
            break;
        }
    }

    if (fabs(pitch - (float)left) < fabs((float)right - pitch))
    {
        return left;
    }
    else
    {
        return right;
    }
}

float PluginGui::_pitch_to_y(float pitch)
{
    float tmp = (_pitch_up - _pitch_down);
    return (_pitch_up - pitch) / tmp * (_draw_h - _margin) + _margin / 2. + _draw_y;
}

float PluginGui::_y_to_pitch(float y)
{
    float tmp = (_pitch_up - _pitch_down);
    return _pitch_up - ((y - _draw_y) - _margin / 2.) / (_draw_h - _margin) * tmp;
}

float PluginGui::_time_to_x(float time)
{
    float tmp = (_time_right - _time_left);

    return (time - _time_left) / tmp * (_draw_w - _margin) + _margin / 2. + _draw_x;
}

float PluginGui::_x_to_time(float x)
{
    float tmp = (_time_right - _time_left);
    return ((x - _draw_x) - _margin / 2.) / (_draw_w - _margin) * tmp + _time_left;
}


void PluginGui::_update_notes()
{
    if (_key_type < _key_type_custom)
    {
        if (_key < _key_custom && _key_type == _key_type_major)
        {
            std::int32_t major[12] = {1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1};
            for (std::int32_t i = 0; i < 12; i++)
            {
                _notes[(_key + i) % 12] = major[i];
            }
        }
        else if (_key < _key_custom && _key_type == _key_type_minor)
        {
            std::int32_t minor[12] = {1, -1, 1, 1, -1, 1, -1, 1, 1, -1, 1, -1};
            for (std::int32_t i = 0; i < 12; i++)
            {
                _notes[(_key + i) % 12] = minor[i];
            }
        }
        else if (_key_type == _key_type_chromatic)
        {
            for (std::int32_t i = 0; i < 12; i++)
            {
                _notes[i] = 1;
            }
        }

        toggleButtonNoteA->setToggleState((_notes[0] > 0), dontSendNotification);
        toggleButtonNoteBb->setToggleState((_notes[1] > 0), dontSendNotification);
        toggleButtonNoteB->setToggleState((_notes[2] > 0), dontSendNotification);
        toggleButtonNoteC->setToggleState((_notes[3] > 0), dontSendNotification);
        toggleButtonNoteDb->setToggleState((_notes[4] > 0), dontSendNotification);
        toggleButtonNoteD->setToggleState((_notes[5] > 0), dontSendNotification);
        toggleButtonNoteEb->setToggleState((_notes[6] > 0), dontSendNotification);
        toggleButtonNoteE->setToggleState((_notes[7] > 0), dontSendNotification);
        toggleButtonNoteF->setToggleState((_notes[8] > 0), dontSendNotification);
        toggleButtonNoteGb->setToggleState((_notes[9] > 0), dontSendNotification);
        toggleButtonNoteG->setToggleState((_notes[10] > 0), dontSendNotification);
        toggleButtonNoteAb->setToggleState((_notes[11] > 0), dontSendNotification);


        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_A, (_notes[0] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Bb, (_notes[1] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_B, (_notes[2] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_C, (_notes[3] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Db, (_notes[4] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_D, (_notes[5] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Eb, (_notes[6] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_E, (_notes[7] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_F, (_notes[8] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Gb, (_notes[9] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_G, (_notes[10] > 0)? 1.: 0.);
        _proc.set_parameter(AutotalentAudioProcessor::PARAMETER_ID_Ab, (_notes[11] > 0)? 1.: 0.);
    }
}

void PluginGui::_x_move(bool left)
{
    float diff = _time_right - _time_left;
    if (left)
    {
        _time_left -= (diff * 0.1);
        if (_time_left < 0.)
        {
            _time_left = 0.;
        }
        _time_right = _time_left + diff;
        if (_time_right > _time_max_len)
        {
            _time_right = _time_max_len;
        }
    }
    else
    {
        _time_right += (diff * 0.1);;
        if (_time_right > _time_max_len)
        {
            _time_right = _time_max_len;
        }
        _time_left = _time_right - diff;
        if (_time_left < 0.)
        {
            _time_left = 0.;
        }
    }

}

void PluginGui::_jump_to_measure(bool forward)
{
    double bpm = _proc.get_bpm();
    if (bpm <= 0.0) return;

    int numerator = _proc.get_time_sig_numerator();
    if (numerator <= 0) numerator = 4;

    double beat_len    = 60.0 / bpm;
    double measure_len = numerator * beat_len;
    double ppq_time    = _proc.get_cur_time() - _proc.get_ppq_position() * beat_len;

    // Measure index that _time_left currently falls in (floor division)
    long long cur_measure = (long long)floor((_time_left - ppq_time) / measure_len);
    long long target      = forward ? cur_measure + 1 : cur_measure - 1;

    double new_left = ppq_time + target * measure_len;
    new_left = juce::jmax(0.0, new_left);

    double diff    = _time_right - _time_left;
    _time_left     = new_left;
    _time_right    = _time_left + diff;

    if (_time_right > _time_max_len)
    {
        _time_right = _time_max_len;
        _time_left  = _time_right - diff;
        if (_time_left < 0.0) _time_left = 0.0;
    }
}

void PluginGui::_y_move(bool up)
{
    if (up)
    {
        if (_pitch_up < _pitch_max)
        {
            _pitch_up++;
            _pitch_down++;
        }
    }
    else
    {
        if (_pitch_down > _pitch_min)
        {
            _pitch_up--;
            _pitch_down--;
        }
    }
}

void PluginGui::_x_zoom(bool in)
{
    float diff = _time_right - _time_left;
    if (in)
    {
        diff -= (diff * 0.1);
        if (diff > _time_min_len)
        {
            _time_left = _cur_time - diff * 0.5;
            if (_time_left < 0)
            {
                _time_left = 0.;
            }
            _time_right = _time_left + diff;
            if (_time_right > _time_max_len)
            {
                _time_right = _time_max_len;
            }
        }
    }
    else
    {
        diff += (diff * 0.1);
        if (diff < _time_max_len)
        {
            _time_left = _cur_time - diff * 0.5;
            if (_time_left < 0)
            {
                _time_left = 0.;
            }
            _time_right = _time_left + diff;
            if (_time_right > _time_max_len)
            {
                _time_right = _time_max_len;
            }
        }
    }
}

void PluginGui::_y_zoom(bool in)
{
    std::int32_t diff = _pitch_up - _pitch_down;
    if (in)
    {
        if (diff > 2)
        {
            _pitch_down++;
            _pitch_up--;
        }
    }
    else
    {
        if (diff < 24 && _pitch_up < _pitch_max && _pitch_down > _pitch_min)
        {
            _pitch_up++;
            _pitch_down--;
        }
    }
}

void PluginGui::_draw_note_limit(float& start_x, float& start_y, float& end_x, float& end_y)
{
    float x0 = start_x;
    float y0 = start_y;
    float x1 = end_x;
    float y1 = end_y;

    if (x0 < _draw_x)
    {
        x0 = _draw_x;
        y0 = start_y + (end_y - start_y) / (end_x - start_x) * (x0 - start_x);
    }

    if (x0 >= _draw_x + _draw_w)
    {
        x0 = _draw_x + _draw_w - 1;
        y0 = start_y + (end_y - start_y) / (end_x - start_x) * (x0 - start_x);
    }

    if (x1 < _draw_x)
    {
        x1 = _draw_x;
        y1 = start_y + (end_y - start_y) / (end_x - start_x) * (x1 - start_x);
    }

    if (x1 >= _draw_x + _draw_w)
    {
        x1 = _draw_x + _draw_w - 1;
        y1 = start_y + (end_y - start_y) / (end_x - start_x) * (x1 - start_x);
    }



    if (y0 < _draw_y)
    {
        y0 = _draw_y;
        x0 = (end_x - start_x) * (y0 - start_y) / (end_y - start_y) + start_x;
    }

    if (y0 >= _draw_y + _draw_h)
    {
        y0 = _draw_y + _draw_h - 1;
        x0 = (end_x - start_x) * (y0 - start_y) / (end_y - start_y) + start_x;
    }


    if (y1 < _draw_y)
    {
        y1 = _draw_y;
        x1 = (end_x - start_x) * (y1 - start_y) / (end_y - start_y) + start_x;
    }

    if (y1 >= _draw_y + _draw_h)
    {
        y1 = _draw_y + _draw_h - 1;
        x1 = (end_x - start_x) * (y1 - start_y) / (end_y - start_y) + start_x;
    }

    start_x = x0;
    start_y = y0;
    end_x = x1;
    end_y = y1;
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGui" componentName=""
                 parentClasses="public AudioProcessorEditor, public Timer" constructorParams="AutotalentAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor(p), _proc(p)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="860" initialHeight="600">
  <METHODS>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="modifierKeysChanged (const ModifierKeys&amp; modifiers)"/>
    <METHOD name="mouseWheelMove (const MouseEvent&amp; e, const MouseWheelDetails&amp; wheel)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="152 112 696 472" fill="solid: 4000000" hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="2efd593a5cb91513" memberName="groupComponent6"
                  virtualName="" explicitFocusOrder="0" pos="144 96 712 496" title="Notes"/>
  <GROUPCOMPONENT name="new group" id="fe9a3479d2a7d612" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="248 8 608 88" title=""/>
  <GROUPCOMPONENT name="Key" id="c819674330435c53" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 96 136 312" title="Key"/>
  <SLIDER name="new slider" id="970facfde35ebf14" memberName="sliderAttack"
          virtualName="" explicitFocusOrder="0" pos="280 56 64 24" min="0.0"
          max="500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <GROUPCOMPONENT name="new group" id="cc29711a8f0b4c59" memberName="groupComponent5"
                  virtualName="" explicitFocusOrder="0" pos="144 96 712 496" title="Notes"/>
  <GROUPCOMPONENT name="new group" id="c7e247cd0bd1faa6" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 8 240 88" title=""/>
  <TOGGLEBUTTON name="Track" id="96b9e7d23267fe2e" memberName="toggleButtonTrack"
                virtualName="" explicitFocusOrder="0" pos="712 24 64 24" buttonText="Track"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="AutoPitch" id="f4d4a673f50ff58f" memberName="toggleButtonAutoTune"
                virtualName="" explicitFocusOrder="0" pos="16 24 96 24" buttonText="AutoPitch"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="A" id="379b4bb7d2fbcace" memberName="toggleButtonNoteA"
                virtualName="" explicitFocusOrder="0" pos="24 216 48 24" buttonText="A"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="Bb" id="c5a5631674e84c6d" memberName="toggleButtonNoteBb"
                virtualName="" explicitFocusOrder="0" pos="24 248 48 24" buttonText="Bb"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="B" id="118f5e02b9feb93a" memberName="toggleButtonNoteB"
                virtualName="" explicitFocusOrder="0" pos="24 280 48 24" buttonText="B"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="C" id="64fa9722fea3f930" memberName="toggleButtonNoteC"
                virtualName="" explicitFocusOrder="0" pos="24 312 48 24" buttonText="C"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="Db" id="fe20e3be7521d3e5" memberName="toggleButtonNoteDb"
                virtualName="" explicitFocusOrder="0" pos="24 344 48 24" buttonText="Db"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="D" id="6c379b8e283b6172" memberName="toggleButtonNoteD"
                virtualName="" explicitFocusOrder="0" pos="24 376 48 24" buttonText="D"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="Eb" id="4f9effd6fff17c8c" memberName="toggleButtonNoteEb"
                virtualName="" explicitFocusOrder="0" pos="80 216 48 24" buttonText="Eb"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="E" id="b85394a33c50f2b4" memberName="toggleButtonNoteE"
                virtualName="" explicitFocusOrder="0" pos="80 248 48 24" buttonText="E"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="F" id="99e08323176a0a04" memberName="toggleButtonNoteF"
                virtualName="" explicitFocusOrder="0" pos="80 280 48 24" buttonText="F"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="Gb" id="4de424495467f77f" memberName="toggleButtonNoteGb"
                virtualName="" explicitFocusOrder="0" pos="80 312 48 24" buttonText="Gb"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="Ab" id="b13f751ddb7ba042" memberName="toggleButtonNoteAb"
                virtualName="" explicitFocusOrder="0" pos="80 376 48 24" buttonText="Ab"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TOGGLEBUTTON name="G" id="6d2077e61f10a098" memberName="toggleButtonNoteG"
                virtualName="" explicitFocusOrder="0" pos="80 344 48 24" buttonText="G"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="new button" id="6322078c6ba4dfdb" memberName="textButtonSnapKey"
              virtualName="" explicitFocusOrder="0" pos="624 24 80 24" bgColOff="a45c94"
              buttonText="Snap Key" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="ClearPitch" id="2162a44ccaf901a6" memberName="textButtonClearPitch"
              virtualName="" explicitFocusOrder="0" pos="784 64 64 24" bgColOff="a45c94"
              buttonText="CPitch" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="fe39f8a969668fb0" memberName="comboBoxKey"
            virtualName="" explicitFocusOrder="0" pos="32 120 88 24" editable="0"
            layout="33" items="A&#10;Bb&#10;B&#10;C&#10;Db&#10;D&#10;Eb&#10;E&#10;F&#10;Gb&#10;G&#10;Ab&#10;---"
            textWhenNonSelected="C" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="735378d9912f9354" memberName="comboBoxKeyType"
            virtualName="" explicitFocusOrder="0" pos="32 152 88 24" editable="0"
            layout="33" items="Major&#10;Minor&#10;Chromatic&#10;---" textWhenNonSelected="Chromatic"
            textWhenNoItems="(no choices)"/>
  <GROUPCOMPONENT name="Setting" id="483f2306d19611c8" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="8 408 136 184" title="Setting"/>
  <SLIDER name="new slider" id="3ba450cd3750e8bc" memberName="sliderRelease"
          virtualName="" explicitFocusOrder="0" pos="368 56 64 24" min="0.0"
          max="500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="f581cb7cddbce5f" memberName="sliderAmount"
          virtualName="" explicitFocusOrder="0" pos="456 56 64 24" min="0.0"
          max="1.0" int="0.01" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Attack(ms)" id="1ae5d807d1d03286" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="272 24 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack(ms)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Release(ms)" id="40333d99763aadcd" memberName="label5"
         virtualName="" explicitFocusOrder="0" pos="360 24 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release(ms)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Amount" id="e338f10f9eadcccf" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="456 24 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Amount" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="new toggle button" id="b054268f61961dfe" memberName="toggleButtonSnap"
                virtualName="" explicitFocusOrder="0" pos="784 24 64 24" buttonText="Snap"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <TEXTBUTTON name="ClearNote" id="5c74ee40a315b111" memberName="textButtonClearNote"
              virtualName="" explicitFocusOrder="0" pos="712 64 64 24" bgColOff="a45c94"
              buttonText="CNote" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Smooth" id="73e3856f04859fc1" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="16 56 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Smooth:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="7421acdac299c74d" memberName="sliderATSmooth"
          virtualName="" explicitFocusOrder="0" pos="72 56 40 24" min="0.0"
          max="1.0" int="0.01" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Amount:" id="6bb22626d8b4863e" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="128 56 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Amount:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="79ef7d9f1d333c4" memberName="sliderATAmount"
          virtualName="" explicitFocusOrder="0" pos="184 56 40 24" min="0.0"
          max="1.0" int="0.01" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="new button" id="27f7687f35fd023c" memberName="textButtonCANote"
              virtualName="" explicitFocusOrder="0" pos="624 64 80 24" bgColOff="a45c94"
              buttonText="CAutoNote" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="f86e3d01596458b4" memberName="textButtonDetectKey"
              virtualName="" explicitFocusOrder="0" pos="32 184 88 24" bgColOff="a45c94"
              buttonText="Detect" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Length" id="dc4dd3223ddffbdd" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="16 432 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Length:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="1f530dc457b303af" memberName="sliderMinLen"
          virtualName="" explicitFocusOrder="0" pos="80 432 48 24" min="0.0"
          max="1000.0" int="10.0" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Interval" id="621be6075a1201a" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="16 464 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Interval:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="b808f0a215270bf5" memberName="sliderMaxInterval"
          virtualName="" explicitFocusOrder="0" pos="80 464 48 24" min="0.0"
          max="1000.0" int="10.0" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="new button" id="900521ff5a75116a" memberName="textButtonSetting"
              virtualName="" explicitFocusOrder="0" pos="24 512 104 40" bgColOff="a45c94"
              buttonText="Setting" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="UndoNote" id="c06b8b766e66bc35" memberName="textButtonUndoNote"
              virtualName="" explicitFocusOrder="0" pos="552 24 64 24" bgColOff="a45c94"
              buttonText="Undo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="RedoNote" id="8e6e4099a433af02" memberName="textButtonRedoNote"
              virtualName="" explicitFocusOrder="0" pos="552 64 64 24" bgColOff="a45c94"
              buttonText="Redo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

