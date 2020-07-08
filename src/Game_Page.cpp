#include "Game_Page.h"

Game_Page::Game_Page():Page()
{
    //ctor
  TTF_Font* pixel_font = TTF_OpenFont("C:/Users/Ashton/Desktop/Game/Code blocks games/Game 1/bin/VT323-Regular.ttf",24);
  main_player = Player();
  LivesText = Text(20,0,100,50,pixel_font);
  ScoreText = Text(500,0,100,50,pixel_font);
}

void Game_Page::Reset()
{
  main_player = Player();
  enemy_manager = Enemy_Manager();
  GameScore = 0;
  framecount = 0;
}

Game_Page::~Game_Page()
{
    //dtor
}
void Game_Page::render(SDL_Renderer* renderer)
{
     SDL_PumpEvents();
                if (keystate[SDL_SCANCODE_RIGHT])
                {
                    main_player.rotate_right();
                }
                if (keystate[SDL_SCANCODE_LEFT])
                {
                    main_player.rotate_left();
                }
                if (keystate[SDL_SCANCODE_SPACE])
                {
                    main_player.fire();
                }   
                SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
                SDL_RenderClear(renderer);
                framecount=framecount%90;
                if (framecount== 0)
                {
                    enemy_manager.spawn_enemy();
                }
                framecount++;
                int cur_bul_index = 0;
                while (cur_bul_index < main_player.bul_list.size())
                {
                    bool hascollided = false;
                    if (enemy_manager.check_any_collision(main_player.bul_list[cur_bul_index].Position_E,GameScore))
                    {
                     main_player.bul_list.erase(main_player.bul_list.begin()+cur_bul_index);
                    }
                    if (!hascollided)
                    {
                        cur_bul_index++;
                    }
                }
                enemy_manager.Enemy_movement();


                    if (main_player.Health>0 && enemy_manager.check_any_collision(main_player.position,GameScore,true))
                    {
                      main_player.handle_collision();
                    }
                    enemy_manager.enemy_renderer(renderer);

                cur_bul_index = 0;
                while (cur_bul_index < main_player.bul_list.size())
                {
                    main_player.bul_list[cur_bul_index].x += main_player.bul_list[cur_bul_index].velocity_x;
                    main_player.bul_list[cur_bul_index].y += main_player.bul_list[cur_bul_index].velocity_y;
                    main_player.bul_list[cur_bul_index].Position_E.x = int (main_player.bul_list[cur_bul_index].x);
                    main_player.bul_list[cur_bul_index].Position_E.y = int (main_player.bul_list[cur_bul_index].y);
                    if (main_player.bul_list[cur_bul_index].Position_E.x>SCREEN_WIDTH+main_player.bul_list[cur_bul_index].Position_E.w||
                    main_player.bul_list[cur_bul_index].Position_E.x<-main_player.bul_list[cur_bul_index].Position_E.w||
                    main_player.bul_list[cur_bul_index].Position_E.y>SCREEN_HEIGHT+main_player.bul_list[cur_bul_index].Position_E.h||
                    main_player.bul_list[cur_bul_index].Position_E.y<-main_player.bul_list[cur_bul_index].Position_E.h)
                    {
                        cout<<"Bullet Deleted"<<endl;
                        main_player.bul_list.erase(main_player.bul_list.begin()+cur_bul_index);
                    }
                    else
                    {
                        SDL_RenderCopyEx(renderer,main_player.arrow,NULL,&(main_player.bul_list[cur_bul_index].Position_E),main_player.bul_list[cur_bul_index].fire_angle,NULL,SDL_FLIP_NONE);
                        cur_bul_index++;
                    }

                }
                main_player.render (renderer);
                LivesText.render(renderer,"Lives: "+to_string(main_player.Health));
                ScoreText.render(renderer,"Score: "+to_string(GameScore));
  SDL_RenderPresent(renderer);
}

