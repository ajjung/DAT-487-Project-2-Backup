/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class ReverbAudioProcessorEditor : public AudioProcessorEditor,
	Slider::Listener,
	Timer
{
public:
    ReverbAudioProcessorEditor (ReverbAudioProcessor&);
    ~ReverbAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
	void timerCallback()override;
	void sliderValueChanged(Slider* sliderThatWasChanged) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ReverbAudioProcessor& processor;
	ScopedPointer<Slider> knob1;
	ScopedPointer<Slider> knob2;
	ScopedPointer<Slider> knob3;
	ScopedPointer<Slider> knob4;
	ScopedPointer<Slider> knob5;
	ScopedPointer<Slider> knob6;
	ScopedPointer<Slider> knob7;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
