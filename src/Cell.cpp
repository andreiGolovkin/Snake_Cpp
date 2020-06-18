#include "Cell.h"

Cell::Cell(int col, int row){
    pos = {col, row};
    color = {0, 255, 0};
}


SDL_Point Cell::getPos(){
    return pos;
}

void Cell::setPos(SDL_Point new_pos){
    pos = new_pos;
}

void Cell::setPos(int x, int y){
    pos.x = x;
    pos.y = y;
}

void Cell::setPos(int index){
    pos = map_param::index2pos(index);
}


void Cell::draw(SDL_Surface* surface){
    SDL_Rect rect = cell_param::get(pos);
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, color.r, color.g, color.b));
}
