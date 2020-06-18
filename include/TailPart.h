#ifndef TAILPART_H
#define TAILPART_H

#include <map>

#include "SnakePart.h"


using namespace std;

class TailPart: public SnakePart{
    public:
        TailPart(int col, int row);

        void draw(SDL_Surface *surface);

        void setPos(SDL_Point new_pos);

        void deleteFromTail();
        void addToTail();

        static map<int, TailPart*> tail;
        static bool isOcupied(SDL_Point pos);
    protected:

    private:
};

#endif // TAILPART_H
