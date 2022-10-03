#include "ConsoleControl.h"
#include "Inputmaneger"
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

            //lock// this lock is not ifficienr 
        case KB_1: {
            
            //lock
            inputsread->push_back('1');
            //unlock
            break;
        }
        case KB_2: {
            inputsread->push_back('1');
            break;
        }
        case KB_3: {
            inputsread->push_back('1');
            break;
        }
        case KB_4: {
            inputsread->push_back('1');
            break;
        }
        case KB_5: {
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