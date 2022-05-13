#include "Solver.h"
#include <iostream>

using namespace std;

Solver::Solver(int x, int y, Screen* _maze)
{
    startX = x;
    startY = y;
    maze = _maze;
    moves = new Stack<int, int>();
}

bool Solver::BeginSolve()
{
    return RecSolve(startX, startY);
}

bool Solver::RecSolve(int x, int y)
{
    maze->Display();
    moves->push(x, y);
    bool found;

    if (maze->GetPixel(x, y) == 'O')
    {
        maze->Draw('X', x, y);
        return true;
    }
    
    if (maze->GetPixel(x, y - 1) != '#' && !found && (y-1) < maze->GetHeight() && (y-1) >= 0 && !moves->Contains(x, y-1))
    {
        found = RecSolve(x, y - 1); 
    }
    if (maze->GetPixel(x + 1, y) != '#' && !found && (x+1) < maze->GetWidth() && (x+1) >= 0 && !moves->Contains(x+1, y))
    {
        found = RecSolve(x + 1, y);
    }
    if (maze->GetPixel(x, y + 1) != '#' && !found && (y+1) < maze->GetHeight() && (y+1) >= 0 && !moves->Contains(x, y+1))
    {
        found = RecSolve(x, y + 1);
    }
    if (maze->GetPixel(x - 1, y) != '#' && !found && (x-1) < maze->GetHeight() && (x-1) >= 0 && !moves->Contains(x-1, y))
    {
        found = RecSolve(x - 1, y);
    }
    maze->Draw('X', x, y);
    if (!found)
    {
        maze->Draw(' ', x, y);
        moves->pop();
    }
    maze->Display();
    return found;
}