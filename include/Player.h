#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>
#include <SDL2/SDL_image.h>
#include "Bullet.h"
#include <vector>
#include "Common.h"
using namespace std;

class Player
{
public:
    int Health = 0;
    vector<Bul> bul_list;
    bool ifAnimation = false;
    Player();
    virtual ~Player();
    int player_animation_counter = 0;
    SDL_Rect position = {};
    Uint8 Red_E = 0;
    Uint8 Green_E = 0;
    Uint8 Blue_E = 0;
    int i = 0;
    void render(SDL_Renderer *renderer);
    void rotate_left();
    void rotate_right();
    void fire();
    void handle_collision();
    int fire_time = 0;
    bool ifFire = false;
    SDL_Texture *arrow = NULL;
    SDL_Surface *arrowsurface = IMG_Load("C:/Users/Ashton/Desktop/Game/Code blocks games/Game 1/bin/arrow.png");
    int center_x = 0;
    int center_y = 0;

protected:
private:
    void FireAnimation();
    int FireAnimationCounter = 0;
    int velocity_x = 0;
    int velocity_y = 0;
    float player_x = 0;
    float player_y = 0;
};

#endif // Player_H
