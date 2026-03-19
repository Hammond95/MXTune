#include "AppearanceGui.h"

static constexpr int ROW_H    = 32;
static constexpr int ROW_Y0   = 16;
static constexpr int LABEL_W  = 160;
static constexpr int SWATCH_W = 140;
static constexpr int PAD      = 8;

AppearanceGui::AppearanceGui(AutotalentAudioProcessor& p)
    : _proc(p)
{
    ColorTheme& t = _proc.get_color_theme();

    addRow("Background",         t.background);
    addRow("Natural note rows",  t.noteNatural);
    addRow("Accidental note rows", t.noteAccidental);
    addRow("Band separator line",t.separatorLine);
    addRow("Pitch reference line", t.pitchRefLine);
    addRow("Input pitch (voice)", t.inPitch);
    addRow("Output pitch (tuned)", t.outPitch);
    addRow("Tune segments",      t.tuneNodes);
    addRow("Playhead",           t.playhead);
    addRow("Measure lines",      t.measureLine);

    _btnReset.reset(new juce::TextButton("Reset to Defaults"));
    _btnReset->addListener(this);
    addAndMakeVisible(_btnReset.get());

    _btnApply.reset(new juce::TextButton("Apply & Close"));
    _btnApply->addListener(this);
    addAndMakeVisible(_btnApply.get());

    int totalH = ROW_Y0 + (int)_rows.size() * ROW_H + PAD + 40 + PAD;
    setSize(LABEL_W + SWATCH_W + PAD * 3, totalH);
}

AppearanceGui::~AppearanceGui() {}

void AppearanceGui::addRow(const juce::String& labelText, juce::Colour& colorRef)
{
    Row row;

    row.label.reset(new juce::Label());
    row.label->setText(labelText, juce::dontSendNotification);
    row.label->setJustificationType(juce::Justification::centredRight);
    addAndMakeVisible(row.label.get());

    row.swatch.reset(new juce::TextButton());
    row.swatch->addListener(this);
    row.colorPtr = &colorRef;
    addAndMakeVisible(row.swatch.get());

    _rows.push_back(std::move(row));
    updateSwatches();
}

void AppearanceGui::updateSwatches()
{
    for (auto& row : _rows)
    {
        if (row.colorPtr == nullptr) continue;
        juce::Colour c = *row.colorPtr;
        row.swatch->setColour(juce::TextButton::buttonColourId, c);
        row.swatch->setColour(juce::TextButton::textColourOffId, c.contrasting(0.8f));
        row.swatch->setButtonText("#" + c.toDisplayString(true).toUpperCase());
    }
}

void AppearanceGui::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff2a3540));
}

void AppearanceGui::resized()
{
    int x_label  = PAD;
    int x_swatch = PAD + LABEL_W + PAD;
    int y = ROW_Y0;

    for (auto& row : _rows)
    {
        row.label->setBounds(x_label,  y + (ROW_H - 20) / 2, LABEL_W, 20);
        row.swatch->setBounds(x_swatch, y + (ROW_H - 24) / 2, SWATCH_W, 24);
        y += ROW_H;
    }

    int btnY  = y + PAD;
    int btnW  = (getWidth() - PAD * 3) / 2;
    _btnReset->setBounds(PAD,          btnY, btnW, 32);
    _btnApply->setBounds(PAD * 2 + btnW, btnY, btnW, 32);
}

void AppearanceGui::openPicker(juce::Colour& colorRef, juce::TextButton* swatch)
{
    _editing = &colorRef;

    auto* selector = new juce::ColourSelector(
        juce::ColourSelector::showColourspace |
        juce::ColourSelector::showSliders     |
        juce::ColourSelector::showColourAtTop |
        juce::ColourSelector::editableColour);
    selector->setSize(300, 380);
    selector->setCurrentColour(colorRef);
    selector->addChangeListener(this);

    juce::CallOutBox::launchAsynchronously(
        std::unique_ptr<juce::Component>(selector),
        swatch->getScreenBounds(),
        nullptr);
}

void AppearanceGui::buttonClicked(juce::Button* b)
{
    if (b == _btnApply.get())
    {
        _proc.get_color_theme().save();
        if (auto* dialog = findParentComponentOfClass<juce::DialogWindow>())
            dialog->exitModalState(1);
        return;
    }

    if (b == _btnReset.get())
    {
        _proc.get_color_theme().reset();
        updateSwatches();
        repaint();
        return;
    }

    // Swatch button clicked — open color picker
    for (auto& row : _rows)
    {
        if (b == row.swatch.get() && row.colorPtr != nullptr)
        {
            openPicker(*row.colorPtr, row.swatch.get());
            return;
        }
    }
}

void AppearanceGui::changeListenerCallback(juce::ChangeBroadcaster* source)
{
    if (_editing == nullptr) return;
    if (auto* cs = dynamic_cast<juce::ColourSelector*>(source))
    {
        *_editing = cs->getCurrentColour();
        updateSwatches();
        repaint();
    }
}
