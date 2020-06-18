#include "Game.h"


Game::Game():
        game_over(false){
    snake.setFood(&food);
    food.setSnake(&snake);
}


void Game::checkEvents(){
    while(SDL_PollEvent(&event) != 0){
        if(event.type == SDL_QUIT){
            game_over = true;
        }
    }

    checkKeyboardEvents();
}

void Game::iterate(){
    if(snake.availableToMove()){
        game_over = snake.bitesItself();

        if(!game_over){
            bool is_food_eaten = snake.eatsFood();
            if(is_food_eaten) snake.grow();
            snake.move();
            if(is_food_eaten) food.replace();
        }
    }
}

void Game::draw(SDL_Surface *surface){
    food.draw(surface);
    snake.draw(surface);
}


bool Game::isOver(){
    return game_over;
}


void Game::checkKeyboardEvents(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if(currentKeyStates[SDL_SCANCODE_W]){
        snake.setDirUp();
    }
    else if(currentKeyStates[SDL_SCANCODE_S]){
        snake.setDirDown();
    }
    else if(currentKeyStates[SDL_SCANCODE_A]){
        snake.setDirLeft();
    }
    else if(currentKeyStates[SDL_SCANCODE_D]){
        snake.setDirRight();
    }

    if(currentKeyStates[SDL_SCANCODE_SPACE]){
        snake.highSpeed();
    }
    else{
        snake.lowSpeed();
    }
}
