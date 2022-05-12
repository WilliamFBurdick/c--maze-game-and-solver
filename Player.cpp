#include "Player.h"

using namespace std;

Player::Player(Screen* _maze, int _startX, int _startY)
{
    maze = _maze;
    maze->Display();
    currentX = _startX;
    currentY = _startY;
    cout<<"Starting X: " + currentX + '\n';
    cout<<"Starting Y: " + currentY + '\n';
    maze->Draw('X', _startX, _startY);
    moves = new Stack<int, int>();
    moves->push(currentX, currentY);
}

bool Player::PlayGame()
{
    locale loc;
    bool gameOver = false;
    bool solved = false;
    string input;
    pair<int, int> moveDirection;
    maze->Display();
    while (!gameOver)
    {
        int xPos, yPos;
        char nextPos;
        cout<<"Select a direction to move or type 'quit' to quit: ";
        cin >> input;
        if (input== "quit")
        {
            gameOver = true;
            break;
        }
        else if (input == "up")
        {
            xPos = 0;
            yPos = -1;
        }
        else if (input == "right")
        {
            xPos = 1;
            yPos = 0;
        }
        else if (input == "down")
        {
            xPos = 0;
            yPos = 1;
        }
        else if (input == "left")
        {
            xPos = -1;
            yPos = 0;
        }
        
        xPos += currentX;
        yPos += currentY;
        cout<<"New position: (" << currentX << ", " << currentY << ")\n";
        nextPos = maze->GetPixel(xPos,yPos);
        cout<<"New char: " << nextPos << '\n';
        switch(nextPos) {
            case 'O':
                currentX = xPos;
                currentY = yPos;
                moves->push(currentX, currentY);
                gameOver = true;
                solved = true;
                break;
            case '#':
                cout<<"Wall hit!  Can't move!\n";
                break;
            default:
                maze->Draw(' ', currentX, currentY);
                currentX = xPos;
                currentY = yPos;
                if (moves->peek1() == currentX && moves->peek2() == currentY)
                {
                    moves->pop();
                }
                moves->push(currentX, currentY);
                maze->Draw('X', currentX, currentY);
                break;
        }
        maze->Display();
    }
    GameOver();
    return solved;
}

void Player::GameOver()
{
    cout<<"GAME OVER";
    maze->Draw(' ', currentX, currentY);
    maze->Display();
    Node<int, int>* temp = moves->GetTop();
    while(temp != nullptr)
    {
        maze->Draw('X', temp->getValue1(), temp->getValue2());
        temp = temp->getNext();
    }
}