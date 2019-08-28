
CXX = g++ -std=c++11
CFLAGS=-c -Wall



langston: main.o board.o ant.o validation.o
	$(CXX) -g main.o board.o ant.o validation.o -o langston

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

board.o: board.cpp board.hpp
	$(CXX) $(CFLAGS) board.cpp

ant.o: ant.cpp ant.hpp
	$(CXX) $(CFLAGS) ant.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CFLAGS) validation.cpp

clean:
	rm *.o letters