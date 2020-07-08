#include "spin_Enemy.h"
#include <math.h>
#include <iostream>
using namespace std;

spin_Enemy::spin_Enemy(double Velocity)
{
    Position_E.h = 40;
    Position_E.w = 40;
    Health = 2;
    Red_E = 58;
    Green_E = 168;
    Blue_E = 50;
    spawn_enemy(Velocity);
}

void spin_Enemy::movement()
{
    double a = -300.0;
    double b = 15;
    double t = ((spiral_pos*Velocity*3.14)/50.0)+0.5;
    x = ((a+b*t)*cos(t+start_pos));
    // t = 0*0.6*3.14 = 0
    // t = 1*0.6*3.14 = 1.884
    // x = (1+5*0)*cos*(0)
    // x = (1+5*1.884)*cos*(1.884)
    // ~10.414

    y = ((a+b*t)*sin(t+start_pos));
    Position_E.x = int (x)+320;
    Position_E.y = int (y)+320;
    spiral_pos++;
}

spin_Enemy::~spin_Enemy()
{
    //dtor
}

void spin_Enemy::spawn_enemy(double _Velocity)
{
    start_pos = (rand() %628)/100.0;
    int height = Position_E.h;
    int width = Position_E.w;
    Velocity = _Velocity;


}
