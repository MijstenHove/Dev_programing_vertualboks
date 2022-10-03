#include "ConsoleControl.h"
#include <iostream>

float clamp(float n, float lower, float upper) {
    return std::max(lower, std::min(n, upper));
}

int main()
{
    int boardSize = 20;

    int xPos = 0;
    int yPos = 0;

    bool needExit = false;

    std::cout << "#";

    while (!needExit)
	{
        int key = ConsoleControl::WaithForReadNextKey();
        switch (key)
        {
        case KB_UP: {
            yPos--;
            break;
        }
        case KB_LEFT: {
            xPos--;
            break;
        }
        case KB_RIGHT: {
            xPos++;
            break;
        }
        case KB_DOWN: {
            yPos++;
            break;
        }
        case KB_ESCAPE: {
            needExit = true;
            break;
        }
        default:
            break;
        }

        xPos = clamp(xPos, 0, boardSize);
        yPos = clamp(yPos, 0, boardSize);

        ConsoleControl::Clear();
        ConsoleControl::SetPosition(xPos, yPos);
        std::cout << "#";
    }
    
}