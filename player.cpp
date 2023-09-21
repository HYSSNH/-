#include "player.h"

Player::Player()
{
    name = "Salah";
    number = 0;
    age = "0";
    starts= "0";
}

Player::Player(QString name1,int number1,QString age1,QString starts1)
{
    name = name1;
    number = number1;
    age = age1;
    starts = starts1;
}
