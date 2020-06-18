#ifndef HEAD_H
#define HEAD_H

#include <SDL.h>

#include "SnakePart.h"


class Head: public SnakePart{
    public:
        Head(int col, int row);

        void move();
        void insertSegment(SnakePart *segment);

        SDL_Point getNextPos();

        bool up();
        bool down();
        bool left();
        bool right();

        void setNext(SnakePart *new_next);
        void connectNext(SnakePart *new_next);
    protected:

    private:
        SDL_Point vel;

        SDL_Point moveAlongAxis();
};

#endif // HEAD_H
