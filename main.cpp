/** @file */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

#include "wav.h"
#include "waveHeader.h"
#include "UIElements.h"
#include "Processor.h"
#include "noisegate.h"
#include "echo.h"
#include "processorChoice.h"
/**
 * \brief   The function bar.
 *
 * \details This function does something which is doing nothing. So this text
 *          is totally senseless and you really do not need to read this,
 *          because this text is basically saying nothing.
 *
 * \note    This text shall only show you, how such a \"note\" section
 *          is looking. There is nothing which really needs your notice,
 *          so you do not really need to read this section.
 *
 * \param[in]     a    Description of parameter a.
 * \param[out]    b    Description of the parameter b.
 * \param[in,out] c    Description of the parameter c.
 *
 * \return        The error return code of the function.
 *
 * \retval        ERR_SUCCESS    The function is successfully executed
 * \retval        ERR_FAILURE    An error occurred
 * 
 *
 */

typedef struct  WAV_HEADER
{
    /* RIFF Chunk Descriptor */
    uint8_t         RIFF[4];        // RIFF Header
    uint32_t        ChunkSize;      // RIFF Chunk Size
    uint8_t         WAVE[4];        // WAVE Header
    /* "fmt" sub-chunk */
    uint8_t         fmt[4];         // FMT header
    uint32_t        Subchunk1Size;  // Size of the fmt chunk
    uint16_t        AudioFormat;    // Audio format
    uint16_t        NumOfChan;      // Number of channels 1=Mono 2=Sterio
    uint32_t        SamplesPerSec;  // Sampling Frequency in Hz
    uint32_t        bytesPerSec;    // bytes per second
    uint16_t        blockAlign;
    uint16_t        bitsPerSample;  // Number of bits per sample
    uint8_t         Subchunk2ID[4]; // "data"  string
    uint32_t        Subchunk2Size;  // Sampled data length
} wav_hdr;


//const std::string testfile = "yes-16-bit-mono.wav";//this is for testing
const std::string testfile;
int getFileSize(FILE* testfile);

int main(int argc, char* argv[])
{
    wav_hdr wavHeader;
    Wav wav;
    int headerSize = sizeof(wav_hdr), filelength = 0;
    int newUserInput;

    const char* filePath;
    string input;
    if (argc <= 1)
    {
        cout << "Input wave file name: ";
        cin >> input;
        cin.get();
        filePath = input.c_str();
    }
    else
    {
        filePath = argv[1];
        cout << "Input wave file name: " << testfile << endl;
    }

    FILE* wavFile = fopen(filePath, "r");
    if (wavFile == nullptr)
    {
        fprintf(stderr, "Unable to open wave file: %s\n", filePath);
        return 1;
    }

    //Read the header
    size_t bytesRead = fread(&wavHeader, 1, headerSize, wavFile);
    cout << "Header Read " << bytesRead << " bytes." << endl;
    if (bytesRead > 0)
    {
        //Read the data
        uint16_t bytesPerSample = wavHeader.bitsPerSample / 8;      //Number of bytes per sample
        uint64_t numSamples = wavHeader.ChunkSize / bytesPerSample;
        static const uint16_t BUFFER_SIZE = 4096;
        int8_t* buffer = new int8_t[BUFFER_SIZE];
        while ((bytesRead = fread(buffer, sizeof buffer[0], BUFFER_SIZE / (sizeof buffer[0]), wavFile)) > 0)
        {
        }
        delete [] buffer;
        buffer = nullptr;
        filelength = getFileSize(wavFile);

        cout << "File is                    :" << filelength << " bytes." << endl;
        cout << "WAVE header                :" << wavHeader.WAVE[0] << wavHeader.WAVE[1] << wavHeader.WAVE[2] << wavHeader.WAVE[3] << endl;
        cout << "Data size                  :" << wavHeader.ChunkSize << endl;

        // Display the sampling Rate from the header
        cout << "Number of bits used        :" << wavHeader.bitsPerSample << endl;
        cout << "Number of bytes per second :" << wavHeader.bytesPerSec << endl;
        cout << "Sampling Rate              :" << wavHeader.SamplesPerSec << endl;
        cout << "Data length                :" << wavHeader.Subchunk2Size << endl;
        cout << "Audio Format               :" << wavHeader.AudioFormat << endl;
        cout << endl;

        UIElements UIElement;
        ProcessorChoice choice;
        UIElement.promptUser();
        if(UIElement.getUserInput() == 1){
            UIElement.promptUser1();
            UIElement.printProccesing();
            UIElement.getArtist();
	        UIElement.getSongTitle();
	        UIElement.getGenre();
	        UIElement.getTrackNumber();
	        UIElement.getYear();
	        UIElement.getComments();
            UIElement.setUserInput(newUserInput);
            choice.promptUserFirst();
            choice.promptUserSecond();
            choice.promptUserThird();
            choice.printProccesing();
        }
        else{
            choice.promptUserFirst();
            choice.promptUserSecond();
            if(choice.getUserInput2() == 3){
                //Echo processing
                //keeps segmentation faulting
                wav.readFile(testfile);
                Processor *processor = new Echo(32000);
                processor->processBuffer(wav.getBuffer(),wav.getBufferSize());
                wav.writeFile(testfile);
                std::cout << "Processing Echo Successful" << std::endl;
            }
            else if(choice.getUserInput2() == 2){
                //Noisegate processing
                //keeps segmentation faulting
                wav.readFile(testfile);
                Processor *noisegate = new NoiseGate(7);
                noisegate->processBuffer(wav.getBuffer(),wav.getBufferSize());
                wav.writeFile(testfile);
                std::cout << "Processing Noisegate Successful" << std::endl;
            }
            else if(choice.getUserInput2() == 1){
                wav.readFile(testfile);
                //uncomment when normalization is finished
                // Processor *normalization = new 
                //normalization->processBuffer(wav.getBuffer(), wav.getBufferSize());
                //wav.writefile(testfile);
                //std::cout << "Processing Normalization Successful" << std::endl;

            }
            choice.promptUserThird();
            choice.printProccesing();
        }


    }
    fclose(wavFile);    
    return 0;

}

// find the file size
int getFileSize(FILE* inFile)
{
    int fileSize = 0;
    fseek(inFile, 0, SEEK_END);

    fileSize = ftell(inFile);

    fseek(inFile, 0, SEEK_SET);
    return fileSize;
}
