
CXX = g++ -std=c++11
CFLAGS=-c -Wall



zoo: main.o menu.o validation.o game.o animal.o penguin.o tiger.o turtle.o zoo.o
	$(CXX) -g main.o menu.o validation.o game.o animal.o penguin.o tiger.o turtle.o zoo.o -o zoo

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

menu.o: menu.cpp menu.hpp
	$(CXX) $(CFLAGS) menu.cpp

validation.o: validation.cpp validation.hpp
	$(CXX) $(CFLAGS) validation.cpp

game.o: game.cpp game.hpp
	$(CXX) $(CFLAGS) game.cpp

animal.o: animal.cpp animal.hpp
	$(CXX) $(CFLAGS) animal.cpp

penguin.o: penguin.cpp penguin.hpp
	$(CXX) $(CFLAGS) penguin.cpp

tiger.o: tiger.cpp tiger.hpp
	$(CXX) $(CFLAGS) tiger.cpp

turtle.o: turtle.cpp turtle.hpp
	$(CXX) $(CFLAGS) turtle.cpp

zoo.o: zoo.cpp zoo.hpp
	$(CXX) $(CFLAGS) zoo.cpp

clean:
	rm *.o zoo