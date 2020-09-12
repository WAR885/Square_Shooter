#ifndef SPIN_ENEMY_H
#define SPIN_ENEMY_H
#include "Enemy.h"
#include "Common.h"

class spin_Enemy : public Enemy
{
public:
    spin_Enemy(double Velocity, SDL_Renderer *renderer);
    spin_Enemy() : Enemy()
    {
    }
    virtual ~spin_Enemy();
    void movement();
    int enemy_type = 3;
    double spiral_pos = 0.0;
    double start_pos = 0.0;
    double Velocity;
    void spawn_enemy(double _Velocity);
    int score = 150;

protected:
private:
};

#endif // spin_Enemy_H
