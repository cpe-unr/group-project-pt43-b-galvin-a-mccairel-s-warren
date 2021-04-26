wavManager: main.o wav.o
	g++ -o wavManager main.o wav.o

main.o: main.cpp
	g++ -c main.cpp

wav.o: wav.cpp wav.h waveHeader.h
	g++ -c wav.cpp
clean:
	rm *.o wavManager