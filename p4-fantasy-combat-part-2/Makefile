
CXX = g++ -std=c++11
CFLAGS=-c -Wall



tournement: main.o Menu.o Validation.o QueueNode.o Queue.o Barbarian.o Bluemen.o Character.o Dice.o Gameplay.o Harrypotter.o Medusa.o Vampire.o Node.o doubleLink.o
	$(CXX) -g main.o Menu.o Validation.o QueueNode.o Queue.o Barbarian.o Bluemen.o Character.o Dice.o Gameplay.o Harrypotter.o Medusa.o Vampire.o Node.o doubleLink.o -o tournement

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

Menu.o: Menu.cpp Menu.hpp
	$(CXX) $(CFLAGS) Menu.cpp

Validation.o: Validation.cpp Validation.hpp
	$(CXX) $(CFLAGS) Validation.cpp

QueueNode.o: QueueNode.cpp QueueNode.hpp
	$(CXX) $(CFLAGS) QueueNode.cpp

Queue.o: Queue.cpp Queue.hpp
	$(CXX) $(CFLAGS) Queue.cpp

Node.o: Node.cpp Node.hpp
	$(CXX) $(CFLAGS) Node.cpp

doubleLink.o: doubleLink.cpp doubleLink.hpp
	$(CXX) $(CFLAGS) doubleLink.cpp

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
	rm *.o tournement