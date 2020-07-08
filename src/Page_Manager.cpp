#include "Page_Manager.h"
#include "Events.h"

void Page_Manager::start()
{
    bool quit = false;
    SDL_Event event;

    Uint32 start;
    while (!quit)
    {
        start = SDL_GetTicks();
        while (SDL_PollEvent(&event))
        {
            //cout << event.type << endl;
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (event.type == ResetGame)
            {
                current_page_index = 1;
                page_list[current_page_index]->Reset();
            }
            else
            {
                page_list[current_page_index]->HandleEvent(event);
            }
        }
        page_render();
        Uint32 timetaken = SDL_GetTicks() - start;

        if (timetaken < 1000 / 60)
        {
            SDL_Delay(1000 / 60 - timetaken);
        }
    }
}