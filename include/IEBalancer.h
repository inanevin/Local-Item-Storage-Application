/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IEBALANCER_H
#define IEBALANCER_H

class IEMenu;
class IEBalancer
{
    public:
        IEBalancer();
        virtual ~IEBalancer();

        void PrintStatistics(IEMenu*);  // Prints the economy statistics.

    protected:

    private:
};

#endif // IEBALANCER_H
