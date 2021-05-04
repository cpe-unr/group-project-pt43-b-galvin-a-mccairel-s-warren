#include "echo.h"
#include "Processor.h"
#include <cmath>
#include <iostream>

Echo::Echo(int delay): delay(delay){

}
void Echo::processBuffer(unsigned char* buffer, int bufferSize){
    float index, delayedIndex, val;
    float echoLevel = 0.5f;
    for(int i = 0; i < bufferSize - delay; i++){
        //set the index to a floating range of -128 to 128
        index = (float)(buffer[i]-128);
        //do the same for your index plus desired delay
        delayedIndex = (float)(buffer[i+delay]-128);
        val = echoLevel*index + delayedIndex*echoLevel + 128;
        //reassign buffer to unsigned char after adding delay
        buffer[i+delay] = (unsigned char)(round(val));
    }

}
void Echo::processShortBuffer(short* shortBuffer, int bufferSize){
    float index, delayedIndex, val;
    float echoLevel = 0.5f;
    for(int i = 0; i < bufferSize - delay; i+=2){
        //same as above except no need to zero signed short
        index = (float)(shortBuffer[i]);
        delayedIndex = (float)(shortBuffer[i+delay]*MAX_FLOAT);
        val = (echoLevel*index + delayedIndex*echoLevel)*(32767);
        shortBuffer[i+delay] = (short)(round(val));
    }
}

