#ifndef ECHO_H
#define ECHO_H
#include "Processor.h"
#include <cmath>

const float MAX_FLOAT = 1/32767;

class Echo : public Processor {
private:
    int delay;
public:
    Echo() = default;

    /**
    * This default constructor allows the user to induce an echo on a wav file
    * 
    * @param delay the desired echo(delay) that the user would like to process
    */
    Echo(int delay);
    
    /**
    * Override unsigned char buffer to produce echo
    * 
    * @param buffer sample data from 8-bit file
    * @param bufferSize size of sample data in bytes
    */
    void processBuffer(unsigned char* buffer, int bufferSize) override;
    
    /**
    * Override short buffer to produce echo
    * 
    * @param shortBuffer sample data from 16-bit file
    * @param bufferSize size of sample data in bytes
    */
    void processShortBuffer(short* shortBuffer, int bufferSize) override;

};

#endif