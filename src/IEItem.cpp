#include "IEItem.h"
/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/


IEItem::IEItem()
{
    //ctor
}

IEItem::IEItem(string name, string desc, string parentSub, float buyPrice, float sellPrice, int quantity)
{
    s_ItemName = name;
    s_ItemDescription = desc;
    s_ParentSubCategory = parentSub;
    f_BuyPrice = buyPrice;
    f_SellPrice = sellPrice;
    i_Quantity = quantity;
}


IEItem::~IEItem()
{
    //dtor
}

string IEItem::GetItemName() const
{
    return s_ItemName;
}

string IEItem::GetItemDescription() const
{
    return s_ItemDescription;
}

string IEItem::GetParentSubCategory() const
{
    return s_ParentSubCategory;
}


float IEItem::GetItemBuyPrice() const
{
    return f_BuyPrice;
}

float IEItem::GetItemSellPrice() const
{
    return f_SellPrice;
}

int IEItem::GetItemQuantity() const
{
    return i_Quantity;
}

string IEItem::SetItemName(string name)
{
    s_ItemName = name;
}

string IEItem::SetItemDescription(string desc)
{
    s_ItemDescription = desc;
}

string IEItem::SetParentSubCategory(string category)
{
    s_ParentSubCategory = category;
}

float IEItem::SetItemBuyPrice(float buyPrice)
{
    f_BuyPrice = buyPrice;
}

float IEItem::SetItemSellPrice(float sellPrice)
{
    f_SellPrice = sellPrice;
}

int IEItem::SetItemQuantity(int quantity)
{
    i_Quantity = quantity;
}

IEItem* IEItem::ReturnSelf()
{
    return this;
}
