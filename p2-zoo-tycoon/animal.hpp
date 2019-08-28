/*********************************************************************
** Program name: Zoo Tycoon
** Author: Derek Yang
** Date:10/21/2017
** Description:This is the animal parent class header file.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

enum A_Type{TigerE, PenguinE, TurtleE, AnimalE};


class Animal {
private:
    int age;
    int cost;
    int number_of_babies;
    double base_food_cost;
    double payoff;
public:
    Animal();

    std::string get_age_str();

    //making the function virtual will make it so that it uses the child class instead
    void printAll();
    int get_age();
    int get_cost();
    int get_number_of_babies();
    double get_base_food_cost();
    double get_payoff();

    void kill_animal();
    virtual void set_tiger();
    void set_penguin();
    void set_turtle();
    void set_age(int ageIn);
    bool dead_status();
    virtual A_Type get_type();


    void setInfo(int ageIn, int costIn, int babiesIn, double foodCostIn, double payoffIn);

    ~Animal();//destructor

};


#endif
