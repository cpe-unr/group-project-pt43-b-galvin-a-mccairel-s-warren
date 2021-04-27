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
    unsigned char* eightBuffer = NULL;
    short* sixteenBuffer = NULL;
public:
    /**
     * A function for reading wav files based on their filename.
     * 
     * @param filename The name of the file that we would like to read data from, 
     *                 this is expected to be a .wav file.
     */
    void readFile(const std::string &filename);
    //virtual ~Wav();

};

#endif