#include "snake.hpp"
#include <cstdlib>

/*void Snake::Move(int dir){
    switch (dir)
    {
    case 1:
        snake.x += speed;
        break;
    case 2:
        snake.x -= speed;
        break;
    case 3:
        snake.y -= speed;
        break;
    case 4:
        snake.y += speed;
        break;
    default:
        break;
    }
}*/

Fruit::Fruit(){
    this->pos[0] = 0;
    this->pos[1] = 0;
}

int *Fruit::GenerateFruit(){
    pos[0] = rand() % 19 + 1;
    pos[1] = rand() % 19 + 1;

    return pos;
}