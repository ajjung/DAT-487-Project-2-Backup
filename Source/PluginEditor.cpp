/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
ReverbAudioProcessorEditor::ReverbAudioProcessorEditor (ReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	setSize(700, 200);
	addAndMakeVisible(knob1 = new Slider("Knob - 1"));
	addAndMakeVisible(knob2 = new Slider("Knob - 2"));
	addAndMakeVisible(knob3 = new Slider("Knob - 3"));
	addAndMakeVisible(knob4 = new Slider("Knob - 4"));
	addAndMakeVisible(knob5 = new Slider("Knob - 5"));
	addAndMakeVisible(knob6 = new Slider("Knob - 6"));
	addAndMakeVisible(knob7 = new Slider("Knob - 7"));

	//knob1 // Gain 
	knob1->setRange(0.0, 100.0);
	knob1->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob1->setTextValueSuffix(" %");
	knob1->setSliderStyle(Slider::Rotary);
	knob1->setColour(Slider::rotarySliderFillColourId, Colours::black);
	knob1->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	knob1->addListener(this);
	knob1->setValue(100.0, sendNotification);
	knob1->setBounds(10, 90, 90, 90);

	//knob 2 //this is the delay amount (m_fDelay_ms)
	knob2->setRange(0.0, 500.0);
	knob2->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob2->setTextValueSuffix(" ms");
	knob2->setSliderStyle(Slider::Rotary);
	knob2->setColour(Slider::rotarySliderFillColourId, Colours::black);
	knob2->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	knob2->addListener(this);
	knob2->setBounds(100, 90, 90, 90);

	//knob3 // Feedback Amount (m_f_FeedBack_pct)
	knob3->setRange(0.0, 100.0);
	knob3->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob3->setTextValueSuffix(" %");
	knob3->setSliderStyle(Slider::Rotary);
	knob3->setColour(Slider::rotarySliderFillColourId, Colours::black);
	knob3->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	knob3->addListener(this);
	knob3->setBounds(190, 90, 90, 90);

	//knob4 // Damping (%)
	knob4->setRange(0.0, 100.0);
	knob4->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob4->setTextValueSuffix(" %");
	knob4->setSliderStyle(Slider::Rotary);
	knob4->setColour(Slider::rotarySliderFillColourId, Colours::black);
	knob4->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	knob4->addListener(this);
	knob4->setBounds(280, 90, 90, 90);

	//knob5  // RoomSize (%)
	knob5->setRange(0.0, 100.0);
	knob5->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob5->setTextValueSuffix(" %");
	knob5->setSliderStyle(Slider::Rotary);
	knob5->setColour(Slider::rotarySliderFillColourId, Colours::black);
	knob5->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	knob5->addListener(this);
	knob5->setBounds(370, 90, 90, 90);

	//knob6 // Width (%)
	knob6->setRange(0.0, 100.0);
	knob6->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob6->setTextValueSuffix(" %");
	knob6->setSliderStyle(Slider::Rotary);
	knob6->setColour(Slider::rotarySliderFillColourId, Colours::black);
	knob6->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	knob6->addListener(this);
	knob6->setBounds(460, 90, 90, 90);

	//knob7  // this is wet / dry (m_f_WetLevel_pct)
	knob7->setRange(0.0, 100.0);
	knob7->setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
	knob7->setTextValueSuffix(" %");
	knob7->setSliderStyle(Slider::Rotary);
	knob7->setColour(Slider::rotarySliderFillColourId, Colours::black);
	knob7->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	knob7->addListener(this);
	knob7->setBounds(550, 90, 90, 90);

	startTimer(50);
}

ReverbAudioProcessorEditor::~ReverbAudioProcessorEditor()
{
	knob1 = nullptr;
	knob2 = nullptr;
	knob3 = nullptr;
	knob4 = nullptr;
	knob5 = nullptr;
	knob6 = nullptr;
	knob7 = nullptr;
}

//==============================================================================
void ReverbAudioProcessorEditor::paint (Graphics& g)
{
	g.fillAll(Colours::maroon);
	g.setColour(Colours::black);
	g.setFont(Font("Arial", 13, Font::bold + Font::italic));
	//knob text
	g.drawSingleLineText("Gain", 42, 80); //this is knob 1
	g.drawSingleLineText("Pre-Delay", 120, 80); //this is knob 2
	g.drawSingleLineText("Feedback", 211, 80); //this is knob 3
	g.drawSingleLineText("Damping", 295, 80); //this is knob 4
	g.drawSingleLineText("Room Size", 393, 80); //this is knob 5
	g.drawSingleLineText("Width", 493, 80); //this is knob 6
	g.drawSingleLineText("Wet / Dry Mix", 593, 80); //this is knob 7
}

void ReverbAudioProcessorEditor::timerCallback()
{
	knob1->setValue(processor.getParameter(ReverbAudioProcessor::knob1Param), NotificationType::dontSendNotification);
	knob2->setValue(processor.getParameter(ReverbAudioProcessor::knob2Param), NotificationType::dontSendNotification);
	knob3->setValue(processor.getParameter(ReverbAudioProcessor::knob3Param), NotificationType::dontSendNotification);
	knob4->setValue(processor.getParameter(ReverbAudioProcessor::knob4Param), NotificationType::dontSendNotification);
	knob5->setValue(processor.getParameter(ReverbAudioProcessor::knob5Param), NotificationType::dontSendNotification);
	knob6->setValue(processor.getParameter(ReverbAudioProcessor::knob6Param), NotificationType::dontSendNotification);
	knob7->setValue(processor.getParameter(ReverbAudioProcessor::knob7Param), NotificationType::dontSendNotification);
}

void ReverbAudioProcessorEditor::sliderValueChanged(Slider* sliderThatWasChanged)
{
	if (sliderThatWasChanged == knob1)
	{
		processor.setParameterNotifyingHost(ReverbAudioProcessor::knob1Param, (float)knob1->getValue());
	}
	else if (sliderThatWasChanged == knob2)
	{
		processor.setParameterNotifyingHost(ReverbAudioProcessor::knob2Param, (float)knob2->getValue());
	}
	else if (sliderThatWasChanged == knob3)
	{
		processor.setParameterNotifyingHost(ReverbAudioProcessor::knob3Param, (float)knob3->getValue());
	}
	else if (sliderThatWasChanged == knob4)
	{
		processor.setParameterNotifyingHost(ReverbAudioProcessor::knob4Param, (float)knob4->getValue());
	}
	else if (sliderThatWasChanged == knob5)
	{
		processor.setParameterNotifyingHost(ReverbAudioProcessor::knob5Param, (float)knob5->getValue());
	}
	else if (sliderThatWasChanged == knob6)
	{
		processor.setParameterNotifyingHost(ReverbAudioProcessor::knob6Param, (float)knob4->getValue());
	}
	else if (sliderThatWasChanged == knob7)
	{
		processor.setParameterNotifyingHost(ReverbAudioProcessor::knob7Param, (float)knob5->getValue());
	}
}
