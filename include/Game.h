#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include "GameObjects.h"

using GameObjects::Snake;
using GameObjects::Food;

class Game{
    public:
        Game();

        void checkEvents();
        void iterate();
        void draw(SDL_Surface *surface);

        bool isOver();
    protected:

    private:
        bool game_over;

        Snake snake;
        Food food;

        SDL_Event event;

        void checkKeyboardEvents();
};

#endif // GAME_H
