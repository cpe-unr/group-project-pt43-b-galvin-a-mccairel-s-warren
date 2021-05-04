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
    void NormalizeAudio();
};


#endif