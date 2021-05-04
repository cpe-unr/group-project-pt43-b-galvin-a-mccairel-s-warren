//Sariah Warren on May 3 2021
#include "echo.h"
#include "Processor.h"
#include <iostream>

void Echo::processBuffer(unsigned char* buffer, int bufferSize){
    float adj_n;
    float adj_delayed_n;
    float echolevel = 0.5f;
    float val;
        for(int n = 0; n < bufferSize - delay; n++){
            adj_n = (float)(buffer[n] - ZERO);
            adj_delayed_n = (float)(buffer[n + delay] - ZERO);
            val = adj_n * echolevel + adj_delayed_n * SCALE_FACTOR + ZERO;
            buffer[n+delay] = (unsigned char)(round(val));
        }
    float f = 2.9f;
    auto j = (unsigned char)f;
}

Echo::Echo(int delay) : delay(delay) {}