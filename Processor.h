//Created by Sariah Warren on 5/3/21

#ifndef PROCESSOR_H
#define PROCESSOR_H


#include <cstdint>
#include <cmath>

class Processor {
public:
    virtual void processBuffer(unsigned char* buffer, int bufferSize) = 0;
    //The user may choose to process a file by choosing one or more processors. 
    //Processors should be applied in sequence. The provided processors should include normalization,
    // noisegating, and echo. After processing, the user should be prompted for a file name and if valid, 
    //anew file is created with the processed audio. 
    //The user is not allowed to save the file under thesame name as any of the existing files.

};

#endif