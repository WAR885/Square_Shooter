#include "big_Enemy.h"

big_Enemy::big_Enemy(double Velocity, SDL_Renderer *renderer) : Enemy(Velocity, renderer)
{
    Position_E.h = 80;
    Position_E.w = 80;
    Health = 6;
    Red_E = 133;
    Green_E = 0;
    Blue_E = 150;
    spawn_enemy(Velocity);
    enemysurface = IMG_Load("C:/Users/Ashton/Documents/GitHub/Square_Shooter/bin/big enemy.png");
    enemy = SDL_CreateTextureFromSurface(renderer, enemysurface);
}

big_Enemy::~big_Enemy()
{
    //dtor
}
