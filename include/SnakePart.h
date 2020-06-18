#ifndef SNAKEPART_H
#define SNAKEPART_H

#include "Cell.h"


class SnakePart: public Cell{
    public:
        SnakePart(int col, int row);
        ~SnakePart();

        SnakePart *getNext();
        SnakePart *getPrev();

        void setNext(SnakePart *new_next);
        void setPrev(SnakePart *new_prev);

        void connectNext(SnakePart *new_next);
        void connectPrev(SnakePart *new_prev);

        void disconnectNext();
        void disconnectPrev();
    protected:
        SnakePart *next;
        SnakePart *prev;
};

#endif // SNAKEPART_H
