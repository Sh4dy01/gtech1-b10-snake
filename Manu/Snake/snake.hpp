 #pragma once

#include "segment.hpp"

class Snake {
public:
    void Move(int dir);
    void Eat();
    void Print();
private:
    Segment* head;
};