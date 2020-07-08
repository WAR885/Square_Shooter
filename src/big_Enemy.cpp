#include "big_Enemy.h"

big_Enemy::big_Enemy(double Velocity)
{
    Position_E.h = 80;
    Position_E.w = 80;
    Health = 6;
    Red_E = 133;
    Green_E = 0;
    Blue_E = 150;
    spawn_enemy(Velocity);
}

big_Enemy::~big_Enemy()
{
    //dtor
}
