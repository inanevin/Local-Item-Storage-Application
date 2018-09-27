/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IECONSOLECONTROLLER_H
#define IECONSOLECONTROLLER_H
#include <iostream>
using namespace std;

class IEConsoleController
{
    public:
        IEConsoleController();
        virtual ~IEConsoleController();

        void IterateConsole(int);   // Iterates the console for X amount of lines.
        void CleanConsole(void);    // Cleans the console.
    protected:

    private:
};

#endif // IECONSOLECONTROLLER_H
