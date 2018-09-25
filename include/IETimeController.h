/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IETIMECONTROLLER_H
#define IETIMECONTROLLER_H
#include <time.h>

class IETimeController
{
    public:
        IETimeController();
        virtual ~IETimeController();

        void WaitForSeconds(int);       // Waits for X seconds.

    protected:

    private:
};

#endif // IETIMECONTROLLER_H
