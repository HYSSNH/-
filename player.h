#ifndef PLAYER_H
#define PLAYER_H

#include <head.h>

class Player : public QObject
{
public:
    Player();
    Player(QString name1,int number1,QString age1,QString starts1);
    QString getName(){return name;}
    int getNumber(){return number;}
    QString getAge(){return age;}
    QString getStarts(){return starts;}

private:
    QString name;
    int number;
    QString age;
    QString starts;

};

#endif // PLAYER_H
