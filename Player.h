#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include "Stack.h"
#include "Screen.h"
#include "Node.h"

using namespace std;

class Player {
    private:
        int currentX, currentY;
        Stack<int, int>* moves;
        Screen *maze;
    public:
        Player(Screen* _maze, int _startX, int _startY);
        bool PlayGame();
        void GameOver();
};

#endif