#include "Player.h"
void Player::FireAnimation()
{
    if (FireAnimationCounter == 5)
    {
        velocity_x = -10 * cos((i - 90) * PI / 180.0);
        velocity_y = -10 * sin((i - 90) * PI / 180.0);
        player_x = position.x + velocity_x;
        player_y = position.y + velocity_y;
    }
    else
    {
        player_x -= velocity_x / 4.0;
        player_y -= velocity_y / 4.0;
    }
    position.x = player_x;
    position.y = player_y;
    FireAnimationCounter--;
}
void Player::rotate_left()
{
    i -= 5;
}
void Player::rotate_right()
{
    i += 5;
}

void Player::fire()
{
    if (fire_time >= 10 && Health > 0)
    {
        FireAnimationCounter = 5;
        double bul_degree = i - 95 + (rand() % 10);
        fire_time = 0;
        SDL_Rect bul;
        bul.h = 24;
        bul.w = 6;
        ifFire = true;
        double velocity_x = 5 * cos(bul_degree * PI / 180.0);
        double velocity_y = 5 * sin(bul_degree * PI / 180.0);
        Bul new_bul;
        new_bul.Position_E = bul;
        new_bul.velocity_x = velocity_x;
        new_bul.velocity_y = velocity_y;
        new_bul.x = center_x;
        new_bul.y = center_y;
        new_bul.fire_angle = i;
        bul_list.push_back(new_bul);
    }
}
void Player::handle_collision()
{
    player_animation_counter = 0;
    Health--;
    ifAnimation = true;
}

Player::Player()
{
    SDL_SetColorKey(playersurface, SDL_TRUE, SDL_MapRGB(playersurface->format, 0, 0xFF, 0xFF));
    position.x = SCREEN_WIDTH / 2 - SCREEN_WIDTH / 16;
    position.y = SCREEN_HEIGHT / 2 - SCREEN_HEIGHT / 16;
    position.h = SCREEN_HEIGHT / 8;
    position.w = SCREEN_WIDTH / 8;

    int fire_angle = 0;
    i = 0;
    ifFire = false;
    fire_time = 0;
    center_x = (SCREEN_WIDTH / 2) - 3;
    center_y = (SCREEN_HEIGHT / 2) - 10;
    i = i % 360;
    Health = 3;
}
//TODO - turn bullets into gun class which player class uses.

Player::~Player()
{
    //dtor
}

void Player::render(SDL_Renderer *renderer)
{
    if (FireAnimationCounter > 0)
    {
        FireAnimation();
    }
    player = SDL_CreateTextureFromSurface(renderer, playersurface);
    bullet = SDL_CreateTextureFromSurface(renderer, bulletsurface);
    int playerheight = playersurface->h;
    int playerwidth = playersurface->w;
    if (Health > 0)
    {
        if (ifAnimation && player_animation_counter < 5)
        {
            player_animation_counter++;
        }
        else
        {
            SDL_RenderCopyEx(renderer, player, NULL, &position, i, NULL, SDL_FLIP_NONE);
        }
    }
    fire_time++;
}
