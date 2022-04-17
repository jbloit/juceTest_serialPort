#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    
    addAndMakeVisible(toggleButton);
    toggleButton.onStateChange = [this]()
    {
        if (toggleButton.getToggleState())
        {
            serialManager->
        }
    };
    
    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    toggleButton.setBounds(area.reduced(proportionOfWidth(0.3)));
}
