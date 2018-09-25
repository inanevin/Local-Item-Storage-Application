/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IERAMCHIP_H
#define IERAMCHIP_H

#include <IEItem.h>


class IERamChip : public IEItem
{
    public:
        IERamChip(string, string, string, float, float, int, string, int, int);
        virtual ~IERamChip();

        virtual void ShowItemData();      // Shows the item data.
        virtual void RegisterItemData();  // Registers the item data.

    protected:

    private:

        string s_DDRModule;
        int i_Memory;
        int i_MHZ;
};

#endif // IERAMCHIP_H
