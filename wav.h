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

    /**
     * A method for writing to desired outFile
     * 
     * @param outFileName new file to be written to
     */
    void writeFile(const std::string &outFileName);

    /** dtor made for buffers allocated on the heap */
    virtual ~Wav();

    /** Accessor method for audio buffer */
    unsigned char *getBuffer();

    /** Accessor method for bufferSize */
    int getBufferSize() const;

public:
    unsigned char* buffer = NULL;

};

#endif