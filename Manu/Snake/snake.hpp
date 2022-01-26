 #pragma once

class Segment{
    private:
    Segment* next;
};

class Snake {
public:
    Snake();
    void ChangeDir();
    void Move();
    void Eat();
    void Draw();
    void Print();

    SDL_Rect GetHead();
private:
    Segment* head;
    SDL_Rect snake;
    int dir;
    int speed;
};

