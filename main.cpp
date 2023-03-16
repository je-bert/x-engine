#include <iostream>
#include <SDL.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char * args[]) {
    SDL_Window* window = nullptr;
    SDL_Surface* screenSurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not be initialized: " << SDL_GetError();
    } else {
        window = SDL_CreateWindow( "X Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
          screenSurface = SDL_GetWindowSurface(window);
          SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
          SDL_UpdateWindowSurface(window);

          std::cout << "SDL video system is ready to go" << std::endl;

          //Hack to get window to stay up
          SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


