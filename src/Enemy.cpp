#include "Enemy.h"

Enemy::Enemy(double Velocity, SDL_Renderer *renderer)
{
    Position_E.h = 40;
    Position_E.w = 40;
    spawn_enemy(Velocity);
    Position_E.x = x;
    Position_E.y = y;
    Health = 2;
    enemy_animation_counter = 0;
    Red_E = 255;
    Green_E = 0;
    Blue_E = 0;
    enemysurface = IMG_Load("C:/Users/Ashton/Documents/GitHub/Square_Shooter/bin/enemy.png");
    enemy = SDL_CreateTextureFromSurface(renderer, enemysurface);
}
Enemy::~Enemy()
{
    //dtor
    delete enemysurface;
    delete enemy;
}

void Enemy::spawn_enemy(double Velocity)
{
    int screen_center_x = SCREEN_WIDTH / 2;
    int screen_center_y = SCREEN_HEIGHT / 2;
    int side = rand() % 4;
    int side_pos = rand() % SCREEN_WIDTH;
    int centerX, centerY;
    double Opposite, Adjacent, Degree;
    int height = Position_E.h;
    int width = Position_E.w;
    switch (side)
    {
    case 0:
        y = 0;
        x = side_pos;
        centerX = x + width / 2;
        centerY = y + height / 2;
        Opposite = screen_center_y - centerY;
        Adjacent = abs(screen_center_x - centerX);
        Degree = atan(Opposite / Adjacent);
        if (centerX < screen_center_x)
        {
            Degree = 6.283 - Degree;
        }
        else
        {
            Degree = 3.1415 + Degree;
        }
        velocity_x = 1 * cos(Degree);
        velocity_y = -1 * sin(Degree);
        cout << x << " " << y << " " << Opposite << " " << Adjacent << " " << Degree << endl;
        break;
    case 1:
        x = SCREEN_WIDTH - width;
        y = side_pos;
        centerX = x + width / 2;
        centerY = y + height / 2;
        Opposite = centerX - screen_center_x;
        Adjacent = abs(screen_center_y - centerY);
        Degree = atan(Opposite / Adjacent);
        if (centerY < screen_center_y)
        {
            Degree = 4.712 - Degree;
        }
        else
        {
            Degree = 1.507 + Degree;
        }
        velocity_x = 1 * cos(Degree);
        velocity_y = -1 * sin(Degree);
        cout << x << " " << y << " " << Opposite << " " << Adjacent << " " << Degree << endl;
        break;
    case 2:
        y = SCREEN_HEIGHT - height;
        x = side_pos;
        centerX = x + width / 2;
        centerY = y + height / 2;
        Opposite = centerY - screen_center_y;
        Adjacent = abs(screen_center_x - centerX);
        Degree = atan(Opposite / Adjacent);
        if (centerX > screen_center_x)
        {
            Degree = 3.1415 - Degree;
        }
        else
        {
            Degree = 0 + Degree;
        }
        velocity_x = 1 * cos(Degree);
        velocity_y = -1 * sin(Degree);
        cout << x << " " << y << " " << Opposite << " " << Adjacent << " " << Degree << endl;
        break;
    case 3:
        x = 0;
        y = side_pos;
        centerX = x + width / 2;
        centerY = y + height / 2;
        Opposite = screen_center_x - centerX;
        Adjacent = abs(screen_center_y - centerY);
        Degree = atan(Opposite / Adjacent);
        if (centerY > screen_center_y)
        {
            Degree = 1.507 - Degree;
        }
        else
        {
            Degree = 4.713 + Degree;
        }
        velocity_x = 1 * cos(Degree);
        velocity_y = -1 * sin(Degree);
        cout << x << " " << y << " " << Opposite << " " << Adjacent << " " << Degree << endl;
        break;
    }
    velocity_x *= Velocity;
    velocity_y *= Velocity;
}
void Enemy::render(SDL_Renderer *renderer)
{
    if (enemy_animation_counter < 10 && enemy_animation_counter > 0)
    {
        enemy_animation_counter++;
        SDL_SetTextureAlphaMod(enemy, Uint8(255 / enemy_animation_counter));
    }
    else
    {
        SDL_SetTextureAlphaMod(enemy, 0xFF);
    }
    int angle = EnemyAngle();
    SDL_RenderCopyEx(renderer, enemy, NULL, &Position_E, angle + 90, NULL, SDL_FLIP_NONE);
}

void Enemy::DeathAnimationRender(SDL_Renderer *renderer)
{

    if (DeathAnimationCounter < 30)
    {
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        DeathAnimationCounter++;
        Uint8 AlphaChannel = 255 - ((255.0 / 30.0) * DeathAnimationCounter);
        SDL_SetTextureAlphaMod(enemy, AlphaChannel);
    }
    int angle = EnemyAngle();
    SDL_RenderCopyEx(renderer, enemy, NULL, &Position_E, angle + 90, NULL, SDL_FLIP_NONE);
}
void Enemy::movement()
{
    x += velocity_x;
    y += velocity_y;
    Position_E.x = int(x);
    Position_E.y = int(y);
    if (Position_E.x > SCREEN_WIDTH + Position_E.w ||
        Position_E.x < -Position_E.w ||
        Position_E.y > SCREEN_HEIGHT + Position_E.h ||
        Position_E.y < -Position_E.h)
    {
        cout << "Enemy Deleted" << endl;
        EnemyDead = true;
    }
}

bool Enemy::CheckCollision(SDL_Rect ColObj)
{
    if ((Position_E.x > ColObj.x && Position_E.x < ColObj.x + ColObj.w) || (ColObj.x > Position_E.x && ColObj.x < Position_E.x + Position_E.w))
    {

        if ((Position_E.y > ColObj.y && Position_E.y < ColObj.y + ColObj.h) || (ColObj.y > Position_E.y && ColObj.y < Position_E.y + Position_E.h))
        {
            Health--;
            enemy_animation_counter = 1;
            if (Health == 0)
            {
                EnemyDead = true;
            }
            return true;
        }
    }
    return false;
}
int Enemy::EnemyAngle()
{
    int center_y = SCREEN_HEIGHT / 2;
    int center_x = SCREEN_WIDTH / 2;
    double angle = atan2(center_y - Position_E.y, center_x - Position_E.x) * 180 / PI;
    return angle;
}