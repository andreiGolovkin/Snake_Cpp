#ifndef PARAM_H
#define PARAM_H

#include <SDL.h>


namespace cell_param{
    const int gap = 1;
    const int side = 20;

    SDL_Rect get(SDL_Point pos);
    SDL_Rect getExpandedLeft(SDL_Point pos);
    SDL_Rect getExpandedRight(SDL_Point pos);
    SDL_Rect getExpandedUp(SDL_Point pos);
    SDL_Rect getExpandedDown(SDL_Point pos);
}


namespace map_param{
    const int width = 30;
    const int height = 30;

    int pos2index(SDL_Point pos);
    int pos2index(int x, int y);

    int getMaxIndex();

    SDL_Point index2pos(int index);

    bool validPos(SDL_Point pos);
    bool validPos(int x, int y);

    bool behindRightBorder(SDL_Point pos);
    bool behindLeftBorder(SDL_Point pos);
    bool behindUpperBorder(SDL_Point pos);
    bool behindLowerBorder(SDL_Point pos);

    SDL_Point validatePos(SDL_Point pos);
}

#endif // PARAM_H
