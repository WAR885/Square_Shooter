#ifndef BULLET_H
#define BULLET_H
#include <SDL2/SDL.h>

struct Bul
{
    SDL_Rect Position_E = {};
    double fire_angle = 0;
    double velocity_x ;
    double velocity_y ;
    double x=0;
    double y=0;

};

class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();

    protected:

    private:
};

#endif // BULLET_H
