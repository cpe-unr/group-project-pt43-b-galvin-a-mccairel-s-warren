wavManager: main.cpp main.o wav.o
	g++ -std=c++11 main.cpp main.o wav.o -o wavManager

main.o: main.cpp
	g++ -std=c++11 main.cpp

wav.o: wav.cpp wav.h waveHeader.h
	g++ -std=c++11 wav.cpp
clean:
	rm *.o wavManager