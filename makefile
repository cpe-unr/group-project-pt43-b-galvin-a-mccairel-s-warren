wavManager: main.cpp main.o wav.o echo.o noisegate.o processor.o
	g++ -std=c++11 main.cpp main.o wav.o echo.o noisegate.o processor.o -o wavManager

main.o: main.cpp
	g++ -std=c++11 main.cpp

wav.o: wav.cpp wav.h waveHeader.h
	g++ -std=c++11 wav.cpp

processor.o: processor.cpp processor.h
	g++ -std=c++11 processor.cpp

noisegate.o: noisegate.cpp noisegate.h
	g++ -std=c++11 noisegate.cpp

echo.o: echo.cpp echo.h
	g++ -std=c++11 echo.cpp

normalization.o: normalization.cpp normalization.h
	g++ -std=c++11 echo.cpp
clean:
	rm *.o wavManager