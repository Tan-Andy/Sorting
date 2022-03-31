all: driver
driver: driver.cpp file.o sorter.h bubble.h insert.h merge.h 
	g++ -std=c++11 -o driver driver.cpp file.o
file: file.cpp file.h
	g++ -std=c++11 -c file.cpp
clean:
	rm *.o driver