#include "Processor.h"
#include "noisegate.h"

const uint8_t ZERO = 0x80;

void Noisegate::processBuffer(unsigned char* buffer, int bufferSize){
    for(int n = 1; n < bufferSize; n++){
        if(buffer[n] > (ZERO - threshold) && buffer[n] < (ZERO + threshold)){
            buffer[n] = ZERO;
        }

    }
}
Noisegate::Noisegate(uint8_t threshold): threshold(threshold){}