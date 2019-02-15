/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioGainAudioProcessorEditor::AudioGainAudioProcessorEditor (AudioGainAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    /*
     db = 20*log(x)
     db/20 = log(x)
     10^(db/20) = x(processor.rawVolume)
     
     
     
     */
    
    
    //gainSlider.setRange(0.0, 1.0);
    gainSlider.setRange(-48.0, 0.0);
    //gainSlider.setValue(0.5);
    gainSlider.setValue(-1.0);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

AudioGainAudioProcessorEditor::~AudioGainAudioProcessorEditor()
{
}

//==============================================================================
void AudioGainAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    
}

void AudioGainAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void AudioGainAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if(slider == &gainSlider)
    {
        processor.rawVolume = pow(10, gainSlider.getValue() / 20);
    }
}
