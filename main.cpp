#include <iostream>
#include <fstream>
#include <string>
#include "Player.h"
#include "Solver.h"
#include "Screen.h"
//#include "MazeSolver.cpp"

using namespace std;

int main()
{
    string selection, line, mazeChars;
    ifstream iFile;
    int rows, cols;
    int startX, startY;
    iFile.open("input.txt");
    if (!iFile.is_open())
    {
        cout<<"Could not open file!\n";
        return 0;
    }
    while (getline(iFile, line))
    {
        int length = line.length();
        mazeChars.append(line);
        rows++;
        cols = length;
    }
    cout<<'\n';
    Screen maze(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (mazeChars[i*cols + j] == 'X')
            {
                startX = j;
                startY = i;
            }
            maze.Draw(mazeChars[i*cols + j], j, i);
        }
    }
    maze.Display();
    bool done = false;
    while (selection != "quit" && !done)
    {
        cout<<"Would you like to play this maze or solve it? ('play'/'solve'/'quit'): ";
        cin>>selection;
        if (selection == "play")
        {
            Player player(&maze, startX, startY);
            player.PlayGame();
            done = true;
        }
        else if (selection == "solve")
        {
            Solver solver(startX, startY, &maze);
            if (solver.BeginSolve())
            {
                cout<<"Solved!\n";
            }
            else
            {
                cout<<"Could not solve!\n";
            }
            done = true;
        }
    }
    return 0;
}