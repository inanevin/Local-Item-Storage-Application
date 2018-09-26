/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IEBalancer.h"
#include "IEMenu.h"

IEBalancer::IEBalancer()
{
    //ctor
}

IEBalancer::~IEBalancer()
{
    //dtor
}

void IEBalancer::PrintStatistics(IEMenu* menu)
{
    // Prompt
    cout << "\n---------------------------------" << endl;
    cout << "Economy Statistics: \n";

    // Declare the necessary vars.
    float f_TotalBuyPrice = 0.0f;
    float f_TotalSellPrice = 0.0f;
    float f_NetIncome = 0.0f;
    float f_AverageNetPerItem = 0.0f;
    int i_TotalItemsOnTheMarket = 0;

    // Pull the data from the items and make the calculations.
    for(list<IEItem>::iterator it = menu->Bank->RegisteredItems.begin(); it != menu->Bank->RegisteredItems.end(); ++it)
    {
        f_TotalBuyPrice += it->GetItemBuyPrice() * it->GetItemQuantity();
        f_TotalSellPrice += it->GetItemSellPrice() * it->GetItemQuantity();
        i_TotalItemsOnTheMarket += it->GetItemQuantity();
    }

    // If we are to have some items of the market, calculate the average net income per item.
    if(menu->Bank->RegisteredItems.size() != 0)
        f_AverageNetPerItem = (f_TotalSellPrice - f_TotalBuyPrice) / (i_TotalItemsOnTheMarket);

    // Print the data.
    cout << "Total Buy Price: " << f_TotalBuyPrice << endl;
    cout << "Total Sell Price: " << f_TotalSellPrice << endl;
    cout << "Estimated Net Income: " << f_TotalSellPrice - f_TotalBuyPrice << endl;
    cout << "Total Item Count On The Market: " << i_TotalItemsOnTheMarket << endl;
    cout << "Average Net Income Per Item: " << f_AverageNetPerItem << "\n" << endl;
    cout << "---------------------------------" << endl;
}
