#ifndef ENEMY_H
#define ENEMY_H
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include "Common.h"
using namespace std;

class Enemy
{
public:
    int Health = 0;
    Enemy(double Velocity);
    Enemy()
    {

    }
    virtual ~Enemy();
    int enemy_animation_counter = 0;
    SDL_Rect Position_E = {};
    double velocity_x;
    double velocity_y;
    double x = 0;
    double y = 0;
    Uint8 Red_E = 0;
    Uint8 Green_E = 0;
    Uint8 Blue_E = 0;
    void render (SDL_Renderer*renderer);
    bool EnemyDead = false;
    void spawn_enemy(double Velocity);
    bool CheckCollision (SDL_Rect ColObj);
    virtual void movement();
    int enemy_type = 1;
    int score = 100;
    int DeathAnimationCounter = 0;
    void DeathAnimationRender(SDL_Renderer *renderer);

protected:
private:
};

#endif // ENEMY_H
