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

    void showLed(bool shouldShowLed);
    
    
private:
    std::unique_ptr<SerialPortInputStream> pInputStream;
    std::unique_ptr<SerialPortOutputStream> pOutputStream;
    
    
    void changeListenerCallback (juce::ChangeBroadcaster* source) override;
};

