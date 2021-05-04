//Created by Sariah Warren on 5/3/21

#include <iostream>
#include "Processor.h"

#ifndef NOISEGATE_H
#define NOISEGATE_H

class Noisegate : public Processor{
    const uint8_t threshold;
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize);
    Noisegate(uint8_t threshold);
};
#endif