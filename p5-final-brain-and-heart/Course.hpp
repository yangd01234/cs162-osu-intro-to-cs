

#ifndef PROJECT_COURSE_HPP
#define PROJECT_COURSE_HPP

#include "Topic1.hpp"
#include "Topic2.hpp"
#include "Topic3.hpp"
#include "Topic4.hpp"
#include "Topic5.hpp"
#include "Topic6.hpp"
#include "Finals.hpp"
#include "Validation.hpp"
#include "Menu.hpp"
#include "Dice.hpp"
class Course {
private:
    Validation v1;
    std::vector <std::string> masteries;
    std::vector <Space*> locations;
    std::vector <std::string> directions;



    Space* current;
    Space* t1 = new Topic1();
    Space* t2 = new Topic2();
    Space* t3 = new Topic3();
    Space* t4 = new Topic4();
    Space* t5 = new Topic5();
    Space* t6 = new Topic6();
    Space* tFinal = new Finals();


    bool collectedAll = false;
    int serotonin;
    int input;

public:
    Course();
    void linkRooms();
    bool navigate(bool &playIn);
    void printMap();
    void addMastery();
    ~Course();
};


#endif
