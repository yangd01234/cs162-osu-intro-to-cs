/*********************************************************************
** Program name: Zoo Tycoon
** Author: Derek Yang
** Date:10/21/2017
** Description:This is the animal parent class.  Tiger, Turtle, and
 * Pengun are child classes and inherit from this class.
*********************************************************************/

#include "animal.hpp"
#include <iostream>

//default constructor
Animal::Animal(){
    //do not add more variables!
    int age;
    int cost;
    int number_of_babies;
    double base_food_cost;
    double payoff;
}

//sets the info
void Animal::setInfo(int ageIn, int costIn, int babiesIn, double foodCostIn, double payoffIn){
    age = ageIn;
    cost = costIn;
    number_of_babies = babiesIn;
    base_food_cost = foodCostIn;
    payoff = payoffIn;
}

//returns age
int Animal::get_age(){
    return age;
}

//returns cost
int Animal::get_cost() {
    return cost;
}

//returns number of babies
int Animal::get_number_of_babies() {
    return number_of_babies;
}

//returns base food multiplier
double Animal::get_base_food_cost() {
    return base_food_cost;
}

//returns payoff multiplier
double Animal::get_payoff() {
    return payoff;
}

//prints all info for animal.  Used in testing
void Animal::printAll(){
    std::cout<<"Age: "<<age<<std::endl;
    std::cout<<"Cost: "<<cost<<std::endl;
    std::cout<<"Number of Babies: "<<number_of_babies<<std::endl;
    std::cout<<"Base Food Cost: "<<base_food_cost<<std::endl;
    std::cout<<"Payoff: "<<payoff<<std::endl;
}


//gets animal type, used in testing
A_Type Animal::get_type(){
    return AnimalE;
}

//sets the defaults for tiger used in testing
void Animal::set_tiger(){

    age = 1;
    cost = 10000;
    number_of_babies = 1;
    base_food_cost = 5;
    payoff = .20;

}
//sets the defaults for turtle used in testing
void Animal::set_turtle(){

    age = 1;
    cost = 100;
    number_of_babies = 10;
    base_food_cost = .5;
    payoff = .05;

}
//sets the defaults for pengui used in testing
void Animal::set_penguin(){

    age = 1;
    cost = 1000;
    number_of_babies = 5;
    base_food_cost = 1;
    payoff = .10;

}

//sets the age
void Animal::set_age(int ageIn) {
    age = ageIn;
}
//kills the animal by setting all values to 0
void Animal::kill_animal() {
    age = 0;
    cost = 0;
    number_of_babies = 0;
    base_food_cost = 0;
    payoff = 0;
}

//returns true if animal is dead, otherwise returns false used in testing
bool Animal::dead_status(){
    int dead_stat = age+cost+number_of_babies+base_food_cost+payoff;
    if(dead_stat == 0){
        return true;
    } else{
        return false;
    }
};
//returns a string if the animal is an adult or baby
std::string Animal::get_age_str() {
    if(age >= 3){
        return "Adult";
    } else{
        return "Baby";
    }
}

//destructor
Animal::~Animal() {

}