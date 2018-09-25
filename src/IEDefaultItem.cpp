/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IEDefaultItem.h"

IEDefaultItem::IEDefaultItem(string name, string desc, string parentSub, float buyP, float sellP, int quantity) : IEItem(name, desc, parentSub, buyP, sellP, quantity)
{
    //ctor
}

IEDefaultItem::~IEDefaultItem()
{
    //dtor
}

void IEDefaultItem::ShowItemData()
{
    // No extra item data to show
}

void IEDefaultItem::RegisterItemData()
{
    // No extra item data to register
}
