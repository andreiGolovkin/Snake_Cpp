#include "GameObjects.h"

GameObjects::Food::Food(): Cell(0, 0),
        snake(NULL){
    replace();
}

void GameObjects::Food::setSnake(Snake *_snake){
    snake = _snake;
}

void GameObjects::Food::replace(){
    int max_index = map_param::getMaxIndex();
    int index = rand() % max_index;
    if(snake != NULL){
        while(snake->isOcupied(map_param::index2pos(index))){
            index = rand() % max_index;
        }
    }
    setPos(index);
}
