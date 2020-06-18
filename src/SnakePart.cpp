#include "SnakePart.h"

SnakePart::SnakePart(int col, int row): Cell(col, row),
        next(NULL), prev(NULL){

}

SnakePart::~SnakePart(){
    if(prev != NULL) delete(prev);
}

SnakePart *SnakePart::getNext(){
    return next;
}

SnakePart *SnakePart::getPrev(){
    return prev;
}

void SnakePart::setNext(SnakePart *new_next){
    next = new_next;
}

void SnakePart::setPrev(SnakePart *new_prev){
    prev = new_prev;
}

void SnakePart::connectNext(SnakePart *new_next){
    this->setNext(new_next);
    new_next->setPrev(this);
}

void SnakePart::connectPrev(SnakePart *new_prev){
    this->setPrev(new_prev);
    new_prev->setNext(this);
}

void SnakePart::disconnectNext(){
    next->setPrev(NULL);
    this->setNext(NULL);
}

void SnakePart::disconnectPrev(){
    prev->setNext(NULL);
    this->setPrev(NULL);
}
