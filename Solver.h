#ifndef SOLVER_H
#define SOLVER_H
#include <utility>
#include "Stack.h"
#include "Screen.h"

using namespace std;

class Solver {
    private:
        int startX, startY;
        Stack<int, int>* moves;
        Screen *maze;
    public:
        Solver(int x, int y, Screen* _maze);
        bool BeginSolve();
        bool RecSolve(int x, int y);

};

#endif