#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <SDL.h>

#include <iostream>

#include <stdlib.h>

#include <map>

#include "Cell.h"
#include "Param.h"
#include "Head.h"
#include "TailPart.h"
#include "Timer.h"

using namespace std;


namespace GameObjects{

    class Food;

    class Snake{
        public:
            Snake();

            void draw(SDL_Surface* surface);
            void move();
            void moveTail();
            void addSegment();
            void grow();

            bool availableToMove();
            bool eatsFood();
            bool isOcupied(SDL_Point pos);
            bool bitesItself();

            void setFood(Food *_food);

            void setDirDown();
            void setDirUp();
            void setDirLeft();
            void setDirRight();

            void highSpeed();
            void lowSpeed();
        protected:

        private:
            Food *food;

            Head head;
            TailPart *tail_end;

            bool dir_is_changed;
            bool has_to_grow;

            Timer movement_timer;
    };








    class Food : public Cell{
        public:
            Food();

            void setSnake(Snake *_snake);

            void replace();
        protected:

        private:
            Snake *snake;
    };

}

#endif // GAMEOBJECTS_H
