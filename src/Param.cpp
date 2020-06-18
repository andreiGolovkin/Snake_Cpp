#include "Param.h"

SDL_Rect cell_param::get(SDL_Point pos){
    SDL_Rect rect;

    rect.x = gap + (side + gap) * pos.x;
    rect.y = gap + (side + gap) * pos.y;
    rect.w = side;
    rect.h = side;

    return rect;
}

SDL_Rect cell_param::getExpandedLeft(SDL_Point pos){
    SDL_Rect cell = cell_param::get(pos);

    cell.x -= cell_param::gap;
    cell.w += cell_param::gap;

    return cell;
}

SDL_Rect cell_param::getExpandedRight(SDL_Point pos){
    SDL_Rect cell = cell_param::get(pos);

    cell.w += cell_param::gap;

    return cell;
}

SDL_Rect cell_param::getExpandedUp(SDL_Point pos){
    SDL_Rect cell = cell_param::get(pos);

    cell.y -= cell_param::gap;
    cell.h += cell_param::gap;

    return cell;
}

SDL_Rect cell_param::getExpandedDown(SDL_Point pos){
    SDL_Rect cell = cell_param::get(pos);

    cell.h += cell_param::gap;

    return cell;
}

int map_param::pos2index(SDL_Point pos){
    return map_param::pos2index(pos.x, pos.y);
}

int map_param::pos2index(int x, int y){
    int index = map_param::validPos(x, y) ? map_param::width * y + x : -1;
    return index;
}

SDL_Point map_param::index2pos(int index){
    SDL_Point pos;

    pos.x = index % map_param::width;
    pos.y = (index - pos.x) / map_param::width;

    return pos;
}

int map_param::getMaxIndex(){
    return pos2index(map_param::width-1, map_param::height-1);
}

bool map_param::validPos(SDL_Point pos){
    return map_param::validPos(pos.x, pos.y);
}

bool map_param::validPos(int x, int y){
    return x >= 0 && x < map_param::width && y >= 0 && y < map_param::height;
}


bool map_param::behindRightBorder(SDL_Point pos){
    return pos.x >= map_param::width;
}

bool map_param::behindLeftBorder(SDL_Point pos){
    return pos.x < 0;
}

bool map_param::behindUpperBorder(SDL_Point pos){
    return pos.y < 0;
}

bool map_param::behindLowerBorder(SDL_Point pos){
    return pos.y >= map_param::height;
}



SDL_Point map_param::validatePos(SDL_Point pos){
    if(!map_param::validPos(pos)){
        if(map_param::behindRightBorder(pos)) pos.x = 0;
        else if(map_param::behindLeftBorder(pos)) pos.x = map_param::width - 1;

        if(map_param::behindUpperBorder(pos)) pos.y = map_param::height - 1;
        else if(map_param::behindLowerBorder(pos)) pos.y = 0;
    }

    return pos;
}
