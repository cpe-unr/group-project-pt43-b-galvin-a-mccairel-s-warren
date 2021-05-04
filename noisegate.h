#ifndef NOISEGATE_H
#define NOISEGATE_H
#include "Processor.h"

class NoiseGate: public Processor{
    const uint8_t threshold;
public:
    /**
    * Default constructor
    */
    NoiseGate() = default;

    /**
     * Overrides the abstract method processBuffer to noisegate the buffer
     * 
     * @param buffer a buffer of unsigned char pointers
     * @param bufferSize the size of the wav buffer for bounds
     */
    void processBuffer(unsigned char* buffer, int bufferSize) override;
    
    /**
     * Overrides the abstract method processBuffer to noisegate the buffer
     * 
     * @param shortBuffer a buffer of short pointers
     * @param bufferSize the size of the wav buffer for bounds
     */
    void processShortBuffer(short* shortBuffer, int bufferSize) override;

    NoiseGate(uint8_t threshold);
};
#endif