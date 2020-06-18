#ifndef CELL_H
#define CELL_H

#include <SDL.h>

#include "Param.h"


class Cell{
    public:
        Cell(int col, int row);

        SDL_Point getPos();
        void setPos(SDL_Point new_pos);
        void setPos(int x, int y);
        void setPos(int index);

        void draw(SDL_Surface* surface);
    protected:
        SDL_Point pos;
        SDL_Color color;
    private:
};

#endif // CELL_H
