#include "Solver.h"

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
    moves->push(x, y);
    bool found;

    if (maze->GetPixel(x, y) == 'O')
    {
        maze->Draw('X', x, y);
        return true;
    }

    if (maze->GetPixel(x, y - 1) != '#' && !found)
    {
        found = RecSolve(x, y - 1); 
    }
    if (maze->GetPixel(x + 1, y) != '#' && !found)
    {
        found = RecSolve(x + 1, y);
    }
    if (maze->GetPixel(x, y + 1) != '#' && !found)
    {
        found = RecSolve(x, y + 1);
    }
    if (maze->GetPixel(x - 1, y) != '#' && !found)
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