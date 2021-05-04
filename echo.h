//Sariah Warren 5/3/21
#ifndef ECHO_H
#define ECHO_H


#include <cstdint>
#include <cmath>
#include <utility>

static const uint8_t ZERO = 128;

static const float SCALE_FACTOR = 0.5F;

#include "Processor.h"

class Echo : public Processor {
private:
    int delay;
public:
    explicit Echo(int delay);

    virtual void processBuffer(unsigned char* buffer, int bufferSize) override;
};


#endif