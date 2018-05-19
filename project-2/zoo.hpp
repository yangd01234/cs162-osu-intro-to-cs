/*********************************************************************
** Program name: Zoo Tycoon
** Author: Derek Yang
** Date:10/21/2017
** Description:This is the zoo class header file.
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP


#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "animal.hpp"
#include "validation.hpp"


class Zoo {
private:
    int tiger_babies_check;
    int turtle_babies_check;
    int penguin_babies_check;
    int tiger_arr_size;
    int turtle_arr_size;
    int penguin_arr_size;
    double daily_profit;
    double base_food_cost;
    Tiger *tigerArr;
    Turtle *turtleArr;
    Penguin *penguinArr;
    Validation v1;
public:
    Zoo();
    void deleteArr();
    void insertAnimal(int arrPos, A_Type typeIn);
    void resizeArr(A_Type typeIn);
    bool kill_animal(A_Type typeIn);
    void kill_all_check();
    void inc_age();
    void tigerBaby();
    void turtleBaby();
    void penguinBaby();
    void create_all_babies();
    void add_adult(double &bankIn);
    void profit(double &bank);
    void subtractBank(double &bankIn, int quantIn, A_Type typeIn);

    bool gameOver(double &bankIn);
    double bonus();
    bool checkBaby(A_Type typeIn);

};


#endif //ZOO_HPP
