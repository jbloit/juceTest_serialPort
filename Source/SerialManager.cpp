/*
  ==============================================================================

    SerialManager.cpp
    Created: 17 Apr 2022 9:48:35am
    Author:  Julien Bloit

  ==============================================================================
*/

#include "SerialManager.h"

SerialManager::SerialManager()
{
    
    juce::StringPairArray portlist = SerialPort::getSerialPortPaths();
    
    DBG("------------------- PORTLIST -------------------");
    DBG(portlist.getDescription());
    DBG("------------------------------------------------");
    
    
    if(portlist.size())
    {
        //open the first port on the system
        
        auto config = SerialPortConfig(9600,
                         8,
                         SerialPortConfig::SERIALPORT_PARITY_NONE,
                         SerialPortConfig::STOPBITS_1,
                         SerialPortConfig::FLOWCONTROL_NONE
                         );
        
        SerialPort * pSP = new SerialPort(portlist.getAllValues()[0], config, [](juce::String a, juce::String b){
            DBG(a); DBG(b);
            
        });
        
        if(pSP->exists())
        {
            //create streams for reading/writing
            pOutputStream.reset(new SerialPortOutputStream(pSP));
            pInputStream.reset(new SerialPortInputStream(pSP));

            pOutputStream->write("hello world via serial", 22); //write some bytes

            //read chars one at a time:
            char c;
            while(!pInputStream->isExhausted())
                pInputStream->read(&c, 1);

            //or, read line by line:
            juce::String s;
            while(pInputStream->canReadLine())
                s = pInputStream->readNextLine();

            //or ask to be notified when a new line is available:
            pInputStream->addChangeListener(this); //we must be a ChangeListener to receive notifications
            pInputStream->setNotify(SerialPortInputStream::NOTIFY_ON_CHAR, '\n');

            //or ask to be notified whenever any character is received
            //NOTE - use with care at high baud rates!!!!
            pInputStream->setNotify(SerialPortInputStream::NOTIFY_ALWAYS);

            //please see class definitions for other features/functions etc
        }
    }

}

SerialManager::~SerialManager()
{
    
}



void SerialManager::changeListenerCallback (juce::ChangeBroadcaster* source)
{
    DBG("a new line is available");
}

void SerialManager::showLed(bool shouldShowLed)
{
    
}

