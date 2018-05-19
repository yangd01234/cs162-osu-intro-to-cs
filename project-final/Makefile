CXX = g++ -std=c++11
CFLAGS=-c -Wall



final: main.o Menu.o Validation.o Course.o Dice.o Finals.o Space.o Topic1.o Topic2.o Topic3.o Topic4.o Topic5.o Topic6.o
	$(CXX) -g main.o Menu.o Validation.o Course.o Dice.o Finals.o Space.o Topic1.o Topic2.o Topic3.o Topic4.o Topic5.o Topic6.o -o final

main.o: main.cpp
	$(CXX) $(CFLAGS) main.cpp

Menu.o: Menu.cpp Menu.hpp
	$(CXX) $(CFLAGS) Menu.cpp

Validation.o: Validation.cpp Validation.hpp
	$(CXX) $(CFLAGS) Validation.cpp

Course.o: Course.cpp Course.hpp
	$(CXX) $(CFLAGS) Course.cpp

Dice.o: Dice.cpp Dice.hpp
	$(CXX) $(CFLAGS) Dice.cpp

Finals.o: Finals.cpp Finals.hpp
	$(CXX) $(CFLAGS) Finals.cpp

Space.o: Space.cpp Space.hpp
	$(CXX) $(CFLAGS) Space.cpp

Topic1.o: Topic1.cpp Topic1.hpp
	$(CXX) $(CFLAGS) Topic1.cpp

Topic2.o: Topic2.cpp Topic2.hpp
	$(CXX) $(CFLAGS) Topic2.cpp

Topic3.o: Topic3.cpp Topic3.hpp
	$(CXX) $(CFLAGS) Topic3.cpp

Topic4.o: Topic4.cpp Topic4.hpp
	$(CXX) $(CFLAGS) Topic4.cpp

Topic5.o: Topic5.cpp Topic5.hpp
	$(CXX) $(CFLAGS) Topic5.cpp

Topic6.o: Topic6.cpp Topic6.hpp
	$(CXX) $(CFLAGS) Topic6.cpp

clean:
	rm *.o final