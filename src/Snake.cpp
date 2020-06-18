#include "GameObjects.h"


GameObjects::Snake::Snake():
        food(NULL), head(5, 5), dir_is_changed(false), has_to_grow(false), movement_timer(400){

        TailPart *sub_segment = new TailPart(6, 5);
        tail_end = new TailPart(7, 5);

        head.connectPrev(sub_segment);
        sub_segment->connectPrev(tail_end);
}




void GameObjects::Snake::draw(SDL_Surface* surface){
    head.draw(surface);

    for(map<int, TailPart*>::iterator it = TailPart::tail.begin(); it != TailPart::tail.end(); it++){
        TailPart *segment = it->second;
        segment->draw(surface);
    }
}


void GameObjects::Snake::move(){
    if(has_to_grow) addSegment();
    else moveTail();

    head.move();

    has_to_grow = false;
    dir_is_changed = false;
    movement_timer.renew();
}

void GameObjects::Snake::moveTail(){
    TailPart *old_tail_end = tail_end;
    tail_end = (TailPart *)tail_end->getNext();
    old_tail_end->disconnectNext();
    head.insertSegment(old_tail_end);

    old_tail_end->setPos(head.getPos());
}

void GameObjects::Snake::addSegment(){
    TailPart *new_segment = new TailPart(head.getPos().x, head.getPos().y);
    head.insertSegment(new_segment);
}

void GameObjects::Snake::setFood(Food *_food){
    food = _food;
}

void GameObjects::Snake::grow(){
    has_to_grow = true;
}

bool GameObjects::Snake::availableToMove(){
    return dir_is_changed || movement_timer.isTriggered();
}

bool GameObjects::Snake::eatsFood(){
    SDL_Point head_pos = head.getNextPos();
    SDL_Point food_pos = food->getPos();
    return head_pos.x == food_pos.x && head_pos.y == food_pos.y;
}

bool GameObjects::Snake::bitesItself(){
    SDL_Point next_head_pos = head.getNextPos();

    return TailPart::isOcupied(next_head_pos);
}


void GameObjects::Snake::setDirDown(){
    dir_is_changed = head.down();
}

void GameObjects::Snake::setDirUp(){
    dir_is_changed = head.up();
}

void GameObjects::Snake::setDirLeft(){
    dir_is_changed = head.left();
}

void GameObjects::Snake::setDirRight(){
    dir_is_changed = head.right();
}



void GameObjects::Snake::highSpeed(){
    movement_timer.setInterval(40);
}

void GameObjects::Snake::lowSpeed(){
    movement_timer.setInterval(400);
}


bool GameObjects::Snake::isOcupied(SDL_Point pos){
    SDL_Point head_pos = head.getPos();
    return TailPart::isOcupied(pos) || (head_pos.x == pos.x && head_pos.y == pos.y);
}
