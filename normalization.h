//Sariah Warren 5/3/21
#ifndef NORMALIZE_H
#define NORMALIZE_H


#include <cstdint>
#include <cmath>
#include <utility>

#include "Processor.h"

class Normalization : public Processor {
private:
    float absmax = 0;
public:
    Normalization() = default;
    /** Constructor that takes in a desiredPeak for normalization */
    Normalization(float desiredPeak);

    /**
     * Overrides the abstract method that takes an 8-bit buffer to allow normalization
     * 
     * @param buffer 8-bit audio buffer
     * @param bufferSize total size in bytes
     */
    void processBuffer(unsigned char* buffer, int bufferSize) override;

    /**
     * Overrides the abstract method that takes an 8-bit buffer to allow normalization
     * 
     * @param shortBuffer 16-bit audio buffer
     * @param bufferSize total size in bytes
     */
    void processShortBuffer(short* shortBuffer, int bufferSize) override;
};


#endif