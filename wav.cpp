#include "wav.h"
#include <iostream>

void Wav::readFile(const std::string &filename){
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if(file.is_open()){
        file.read((char*)&wavHeader, sizeof(wav_header));
        if(wavHeader.sample_alignment == 1 && wavHeader.sample_alignment == 2){
            eightBitBuffer = new unsigned char[wavHeader.data_bytes];        
            std::cout << wavHeader.bit_depth << std::endl;
        }
        else{
            sixteenBuffer = new short[wavHeader.data_bytes];
            std::cout << wavHeader.bit_depth << std::endl;

        }

    }
}