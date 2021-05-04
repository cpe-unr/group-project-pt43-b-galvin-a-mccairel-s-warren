wavManager: main.cpp main.o wav.o echo.o noisegate.o Processor.o normalization.o UIElements.o processorChoice.o
	g++ -std=c++11 main.o wav.o echo.o noisegate.o Processor.o normalization.o UIElements.o processorChoice.o -o wavManager

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

wav.o: wav.cpp wav.h waveHeader.h
	g++ -c -std=c++11 wav.cpp

Processor.o: Processor.cpp Processor.h
	g++ -c -std=c++11 Processor.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -c -std=c++11 noisegate.cpp

echo.o: echo.cpp echo.h
	g++ -c -std=c++11 echo.cpp

normalization.o: normalization.cpp normalization.h 
	g++ -c -std=c++11 normalization.cpp

UIElements.o: UIElements.cpp UIElements.h
	g++ -c -std=c++11 UIElements.cpp 

processorChoice.o: processorChoice.cpp processorChoice.h
	g++ -c -std=c++11 processorChoice.cpp

clean:
	rm *.o wavManager