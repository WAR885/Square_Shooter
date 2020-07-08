#include "Enemy_Manager.h"

Enemy_Manager::Enemy_Manager()
{
    //ctor
}

void Enemy_Manager::enemy_renderer(SDL_Renderer *renderer)
{
    int l = 0;
    while (l < enemy_list.size())
    {
        if (enemy_list[l]->EnemyDead && enemy_list[l]->DeathAnimationCounter < 180)
        {
            enemy_list[l]->DeathAnimationRender(renderer);
        }
        else if (enemy_list[l]->EnemyDead)
        {
            enemy_list.erase(enemy_list.begin() + l);
        }
        else
        {
            enemy_list[l]->render(renderer);
            l++;
        }
    }
    l = 0;
    while (l < big_enemy_list.size())
    {
        if (big_enemy_list[l]->EnemyDead)
        {
            big_enemy_list.erase(big_enemy_list.begin() + l);
        }
        else
        {
            big_enemy_list[l]->render(renderer);
            l++;
        }
    }
    l = 0;
    while (l < spin_enemy_list.size())
    {
        if (spin_enemy_list[l]->EnemyDead)
        {
            spin_enemy_list.erase(spin_enemy_list.begin() + l);
        }
        else
        {
            spin_enemy_list[l]->render(renderer);
            l++;
        }
    }
}
void Enemy_Manager::Enemy_movement()
{
    for (Enemy *enemy : enemy_list)
    {
        enemy->movement();
    }
    for (big_Enemy *enemy : big_enemy_list)
    {
        enemy->movement();
    }
    for (spin_Enemy *enemy : spin_enemy_list)
    {
        enemy->movement();
    }
}

bool Enemy_Manager::check_any_collision(SDL_Rect collision_object, int &score, bool insta_kill)
{
    bool has_collided = false;
    for (Enemy *enemy : enemy_list)
    {
        bool if_enemy_collsion = enemy->CheckCollision(collision_object);
        has_collided = has_collided || if_enemy_collsion;
        if (if_enemy_collsion)
        {
            if (insta_kill)
            {
                enemy->EnemyDead = true;
            }
            score += enemy->score;
        }
    }
    for (big_Enemy *enemy : big_enemy_list)
    {
        bool if_enemy_collsion = enemy->CheckCollision(collision_object);
        has_collided = has_collided || if_enemy_collsion;
        if (if_enemy_collsion)
        {
            if (insta_kill)
            {
                enemy->EnemyDead = true;
            }
            score += enemy->score;
        }
    }
    for (spin_Enemy *enemy : spin_enemy_list)
    {
        bool if_enemy_collsion = enemy->CheckCollision(collision_object);
        has_collided = has_collided || if_enemy_collsion;
        if (if_enemy_collsion)
        {
            if (insta_kill)
            {
                enemy->EnemyDead = true;
            }
            score += enemy->score;
        }
    }
    return has_collided;
}
void Enemy_Manager::spawn_enemy()
{
    speedincrease += 0.001;
    if (rand() % 100 < big_enemy_chance)
    {
        if (big_enemy_chance <= 25)
        {
            big_enemy_chance++;
        }
        big_enemy_list.push_back(new big_Enemy(0.6 + speedincrease));
    }
    else if (rand() % 100 < spin_enemy_chance)

    {
        if (spin_enemy_chance <= 25)
        {
            spin_enemy_chance++;
        }
        spin_enemy_list.push_back(new spin_Enemy(0.6));
    }
    else
    {
        enemy_list.push_back(new Enemy(0.6 + speedincrease));
    }
}

Enemy_Manager::~Enemy_Manager()
{
    //dtor
}
