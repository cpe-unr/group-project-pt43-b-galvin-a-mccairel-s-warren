/*
*Author: Alexander McCairel
*Date: 4/25/2021
*Group Project
*/

#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "wav.h"

class Processor{
public:
    /**
     * This is an abstract method for processing 8-bit audio buffers 
     * @param buffer an unsigned char* audio buffer
     * @param bufferSize the size of the audio buffer
     */
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
    
    /**
     * This is an abstract method for processing 16-bit audio buffers 
     * @param buffer a short* audio buffer
     * @param bufferSize the size of the audio buffer
     */
    virtual void processShortBuffer(short* shortBuffer, int bufferSize) = 0;
};

#endif
