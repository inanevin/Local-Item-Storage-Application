/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IEITEM_H
#define IEITEM_H
#include <iostream>

using namespace std;

class IEItem
{
    public:
        IEItem();
        IEItem(string, string, string, float, float, int);
        virtual ~IEItem();

        virtual void ShowItemData(){};      // Shows the item data.
        virtual void RegisterItemData(){};  // Registers the item data.

        // Get methods for vars.
        string GetItemName() const;
        string GetItemDescription() const;
        string GetParentSubCategory() const;
        float GetItemBuyPrice() const;
        float GetItemSellPrice() const;
        int GetItemQuantity() const;

        // Set methods for vars.
        string SetItemName(string);
        string SetItemDescription(string);
        string SetParentSubCategory(string);
        float SetItemBuyPrice(float);
        float SetItemSellPrice(float);
        int SetItemQuantity(int);

        IEItem* ReturnSelf();               // Returns self address.

    private:

        string s_ItemName;
        string s_ItemDescription;
        string s_ParentSubCategory;
        float f_BuyPrice;
        float f_SellPrice;
        int i_Quantity;
};

#endif // IEITEM_H
