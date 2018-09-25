/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IETimeController.h"

IETimeController::IETimeController()
{
    //ctor
}

IETimeController::~IETimeController()
{
    //dtor
}

void IETimeController::WaitForSeconds(int seconds)
{
    // Wait for input amount of seconds.
    clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}
