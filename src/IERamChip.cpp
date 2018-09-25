/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IERamChip.h"

IERamChip::IERamChip(string name, string desc, string parentSub, float buyP, float sellP, int quantity, string DDR, int mem, int speed) : IEItem(name, desc, parentSub, buyP, sellP, quantity)
{
    s_DDRModule = DDR;
    i_Memory = mem;
    i_MHZ = speed;
}

IERamChip::~IERamChip()
{
    //dtor
}
void IERamChip::RegisterItemData()
{
    cout << "DDR Module: ";
    cin >> s_DDRModule;
    cout << "Memory: ";
    cin >> i_Memory;
    cout << "Speed: ";
    cin >> i_MHZ;
}

void IERamChip::ShowItemData()
{
    cout << "DDR Module: " << s_DDRModule << endl;
    cout << "Memory: " << i_Memory << " GB" << endl;
    cout << "Speed: " << i_MHZ << " MHZ" << endl;
}
