#include <SDL.h>

#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#include "Game.h"

using namespace std;

void background(SDL_Surface* screenSurface, SDL_Color color){
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, color.r, color.g, color.b));
}

const int SCREEN_WIDTH = 631;
const int SCREEN_HEIGHT = 631;

int main(int argc, char* args[]){
    srand(time(0));

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else{
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(window == NULL){
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else{
		    screenSurface = SDL_GetWindowSurface(window);

            Game game;

            while(!game.isOver()){
                game.checkEvents();
                game.iterate();

                background(screenSurface, {0, 0, 0});

                game.draw(screenSurface);

                SDL_UpdateWindowSurface(window);
                SDL_Delay(10);
            }
		}
	}

    return 0;
}
