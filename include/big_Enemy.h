#ifndef BIG_ENEMY_H
#define BIG_ENEMY_H
#include "Enemy.h"
#include "Common.h"

class big_Enemy : public Enemy
{
public:
    big_Enemy(double Velocity, SDL_Renderer *renderer);
    int score = 200;
    big_Enemy() : Enemy()
    {
    }
    virtual ~big_Enemy();
    int enemy_type = 2;

protected:
private:
};

#endif // BIG_ENEMY_H
