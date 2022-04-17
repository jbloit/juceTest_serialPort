/*
  ==============================================================================

    SerialManager.h
    Created: 17 Apr 2022 9:48:35am
    Author:  Julien Bloit

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SerialManager : public juce::ChangeListener
{
public:
    SerialManager();
    ~SerialManager();

    void changeListenerCallback (juce::ChangeBroadcaster* source) override;
    
};

