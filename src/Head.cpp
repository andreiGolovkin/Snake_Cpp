#include "Head.h"

Head::Head(int col, int row): SnakePart(col, row){
    vel = {-1, 0};
    color = {255, 0, 0};
}


void Head::move(){
    pos = getNextPos();
}

void Head::insertSegment(SnakePart *segment){
    prev->connectNext(segment);
    this->connectPrev(segment);
}



SDL_Point Head::moveAlongAxis(){
    SDL_Point new_pos;

    new_pos.x = pos.x + vel.x;
    new_pos.y = pos.y + vel.y;

    return new_pos;
}

SDL_Point Head::getNextPos(){
    SDL_Point next_pos = moveAlongAxis();
    next_pos = map_param::validatePos(next_pos);

    return next_pos;
}



bool Head::up(){
    bool valid_change = vel.y == 0;
    if(valid_change){
        vel.x = 0;
        vel.y = -1;
    }
    return valid_change;
}

bool Head::down(){
    bool valid_change = vel.y == 0;
    if(valid_change){
        vel.x = 0;
        vel.y = 1;
    }
    return valid_change;
}

bool Head::left(){
    bool valid_change = vel.x == 0;
    if(valid_change){
        vel.x = -1;
        vel.y = 0;
    }
    return valid_change;
}

bool Head::right(){
    bool valid_change = vel.x == 0;
    if(valid_change){
        vel.x = 1;
        vel.y = 0;
    }
    return valid_change;
}







void Head::setNext(SnakePart *new_next){}
void Head::connectNext(SnakePart *new_next){}
