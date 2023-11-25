#include <iostream>
#include <SDL2/SDL.h>

#include "person.h"


int main()
{
    auto p = Person("zahash");
    std::cout << p << std::endl;

    return 0;
}

void sdl_run()
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL2 Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    SDL_Delay(3000); // Wait for 3 seconds
    SDL_DestroyWindow(window);
    SDL_Quit();
}
