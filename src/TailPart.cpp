#include "TailPart.h"

map<int, TailPart*> TailPart::tail;

TailPart::TailPart(int col, int row): SnakePart(col, row){
    color = {255, 255, 255};

    addToTail();
}

bool TailPart::isOcupied(SDL_Point _pos){
    int index = map_param::pos2index(_pos);
    return tail.find(index) != tail.end();
}

void TailPart::addToTail(){
    int index = map_param::pos2index(pos);
    tail[index] = this;
}

void TailPart::deleteFromTail(){
    if(isOcupied(pos)){
        int index = map_param::pos2index(pos);
        tail.erase(index);
    }
}

void TailPart::setPos(SDL_Point new_pos){
    deleteFromTail();
    Cell::setPos(new_pos);
    addToTail();
}




void TailPart::draw(SDL_Surface *surface){
    SDL_Rect rect = cell_param::get(pos);

    if(next != NULL){
        SDL_Point vec;
        vec.x = next->getPos().x - pos.x;
        vec.y = next->getPos().y - pos.y;

        if(vec.x == -1) rect = cell_param::getExpandedLeft(pos);
        else if(vec.x == 1) rect = cell_param::getExpandedRight(pos);
        else if(vec.y == -1) rect = cell_param::getExpandedUp(pos);
        else if(vec.y == 1) rect = cell_param::getExpandedDown(pos);
    }

    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, color.r, color.g, color.b));
}
