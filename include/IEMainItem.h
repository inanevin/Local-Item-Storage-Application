#ifndef IEMAINITEM_H
#define IEMAINITEM_H
#include <iostream>
using namespace std;

class IEMainItem
{
    public:
        IEMainItem();
        virtual ~IEMainItem();

        enum CurrencyType {TL, USD, EUR, PND};      // In which currency is this item being sold?

    protected:

        string s_ItemName;              // Item name.
        string s_Description;           // Item's description.
        CurrencyType _CurrencyType;     // Item's currency.
        float f_BuyPrice;               // What is the cost of the item to the owner?
        float f_SellPrice;              // What is the cost of the item to the buyer?


    private:
};

#endif // IEMAINITEM_H
