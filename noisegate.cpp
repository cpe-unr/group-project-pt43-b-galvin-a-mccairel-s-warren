#include "noisegate.h"

//since 8-bit wav is read from the range 0-255, we set zero = 128
//i.e. zero volume level
const uint8_t ZERO = 128;

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize){
    for(int i = 0; i < bufferSize; i++){
        if((ZERO - 5) < buffer[i] < (ZERO +5)){
            buffer[i] = ZERO;
        }
    }
}
void NoiseGate::processShortBuffer(short* shortBuffer, int bufferSize){
    for(int i = 0; i < bufferSize; i++){
        if(-100 < shortBuffer[i] < 100){
            shortBuffer[i] = 0;
        }
    }
}

NoiseGate::NoiseGate(uint8_t threshold): threshold(threshold){}
