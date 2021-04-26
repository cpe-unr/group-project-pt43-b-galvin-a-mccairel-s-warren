/*
*Author: Alexander McCairel
*Date: 4/25/2021
*Group Project
*/
#ifndef WAV_H
#define WAV_H
#include "waveHeader.h"
#include <string>
#include <fstream>

class Wav{
private:
    wav_header wavHeader;
    unsigned char* eightBitBuffer = NULL;
    short* sixteenBuffer = NULL;
public:
    void readFile(const std::string &filename);
    //virtual ~Wav();

};

#endif