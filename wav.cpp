#include "wav.h"
#include <iostream>

void Wav::readFile(const std::string &filename){
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if(file.is_open()){ 
        //read the file that contains riff file info into an array of char pointers
        //pointers point to type wav_header data
        file.read((char*)&wavHeader, sizeof(wav_header));
        //check for 8-bit or 16-bit so right buffer is used
        if(wavHeader.sample_alignment == 1 && wavHeader.sample_alignment == 2){
            eightBuffer = new unsigned char[wavHeader.data_bytes];        
        }
        else{
            sixteenBuffer = new short[wavHeader.data_bytes];
        }

    }
}

void Wav::writeFile(const std::string &outFileName) {
    std::ofstream outFile(outFileName, std::ios::out | std::ios::binary);
    outFile.write((char*)&wavHeader,sizeof(wav_header));
    outFile.write((char*)buffer, wavHeader.data_bytes);
    outFile.close();
}

unsigned char *Wav::getBuffer(){
    return buffer;
}

Wav::~Wav() {
    if(buffer != NULL)
        delete[] buffer;
}

int Wav::getBufferSize() const {
    return wavHeader.data_bytes;
}