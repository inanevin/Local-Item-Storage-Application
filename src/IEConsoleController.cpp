/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IEConsoleController.h"
#include <cstdlib>

IEConsoleController::IEConsoleController()
{
    //ctor
}

IEConsoleController::~IEConsoleController()
{
    //dtor
}

void IEConsoleController::IterateConsole(int iterateAmount)
{
    // Iterate console for input.
    for(int x = 0; x < iterateAmount; x++)
    {
        cout << "\n" << endl;
    }
}

void IEConsoleController::CleanConsole(void)
{
     system("CLS");     // Clean console.
}
