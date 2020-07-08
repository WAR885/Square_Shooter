#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <SDL2/SDL_image.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "Enemy.h"
#include "big_Enemy.h"
#include "spin_Enemy.h"

class Enemy_Manager
{
    public:
        Enemy_Manager();
        virtual ~Enemy_Manager();

void Enemy_movement();
void spawn_enemy();
bool check_any_collision(SDL_Rect collision_object,int& score,bool insta_kill = false);
vector <Enemy*> enemy_list;
vector <big_Enemy*> big_enemy_list;
vector <spin_Enemy*> spin_enemy_list;
void enemy_renderer (SDL_Renderer* renderer);
double speedincrease = 0.0;
int big_enemy_chance = 5;
int spin_enemy_chance = 5;


    protected:

    private:
};

#endif // ENEMY_MANAGER_H
