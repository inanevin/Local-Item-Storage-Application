/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IEDEFAULTITEM_H
#define IEDEFAULTITEM_H

#include <IEItem.h>


class IEDefaultItem : public IEItem
{
    public:
        IEDefaultItem();
        IEDefaultItem(string, string, string, float, float, int);
        virtual ~IEDefaultItem();

        virtual void ShowItemData();        // Shows item data.
        virtual void RegisterItemData();    // Registers item data.

    protected:

    private:
};

#endif // IEDEFAULTITEM_H
