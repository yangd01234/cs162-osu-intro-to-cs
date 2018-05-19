
CXX = g++ -std=c++11
CFLAGS=-c -Wall



Harrypotter: main.o Menu.o Validation.o Barbarian.o Bluemen.o Character.o Dice.o Gameplay.o Harrypotter.o Medusa.o Vampire.o 
	$(CXX) -g main.o Menu.o Validation.o Barbarian.o Bluemen.o Character.o Dice.o Gameplay.o Harrypotter.o Medusa.o Vampire.o -o game

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

Menu.o: Menu.cpp Menu.hpp
	$(CXX) $(CFLAGS) Menu.cpp

Validation.o: Validation.cpp Validation.hpp
	$(CXX) $(CFLAGS) Validation.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	$(CXX) $(CFLAGS) Barbarian.cpp

Bluemen.o: Bluemen.cpp Bluemen.hpp
	$(CXX) $(CFLAGS) Bluemen.cpp

Character.o: Character.cpp Character.hpp
	$(CXX) $(CFLAGS) Character.cpp

Dice.o: Dice.cpp Dice.hpp
	$(CXX) $(CFLAGS) Dice.cpp

Gameplay.o: Gameplay.cpp Gameplay.hpp
	$(CXX) $(CFLAGS) Gameplay.cpp

Harrypotter.o: Harrypotter.cpp Harrypotter.hpp
	$(CXX) $(CFLAGS) Harrypotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	$(CXX) $(CFLAGS) Medusa.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	$(CXX) $(CFLAGS) Vampire.cpp




clean:
	rm *.o game