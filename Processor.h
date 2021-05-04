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
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
    virtual void processShortBuffer(short* shortBuffer, int bufferSize) = 0;
};
