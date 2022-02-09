#pragma once

#define SCORE_TO_ADD 10
#define SPEED 4
#define SQUARES 10
#define MAX_LENGTH ((SQUARES-2)*(SQUARES-2))
#define SET 7

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define PAUSE 0


class Segment {
public:
    Segment();
    ~Segment();

    void Init(int direction, int x, int y);
    void Move();
    Segment *AddSnake(int direction, int x, int y);
    void ResetBody();

    bool CheckNext();
    Segment *GetNext();
    int GetDirection();
    int GetX();
    int GetY();

    void SetX(int newx);
    void SetY(int newy);
    void SetDirection(int nextDirection);

private:
    Segment *next;
    
    int direction, nextDirection;
    int x, y;
};

class Fruit{
public:
    Fruit();
    ~Fruit();

    Fruit *GenerateFruit();
    void GenerateFruitCoord(Segment *head, Fruit *fruit);
    void ResetFruits();

    bool CheckNext();

    bool GetMalus();
    int GetX();
    int GetY();
    Fruit *GetNext();

    void SetMalus();

private:
    int x,y;
    bool malus;
    Fruit *next;
};


class Snake {
public:
    Snake();
    ~Snake();

    void Move();
    void Eat();
    void CheckDirection();
    void CheckBorders();
    void CheckCollision();
    void CheckFruit();
    void UpdateCoords();
    void Debug();
    void Reset();

    int GetX();
    int GetY();
    int GetScore();
    int GetLength();
    int GetBallCount();
    int GetTurn();
    Segment *GetHead();
    Fruit *GetFruit();

private:
    Segment *head;
    Segment *startCol;
    Segment *tail;
    Fruit *fruit;

    int length, score, ballCount, turn;
    int direction, newDirection;
    int coordsArray[MAX_LENGTH][2];
};