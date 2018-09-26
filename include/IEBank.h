#ifndef IEBANK_H
#define IEBANK_H
#include "IEMainCategory.h"
#include "IESubCategory.h"
#include "IEItem.h"
#include "IEDefaultItem.h"
#include <list>
/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include <iostream>
#include <stdio.h>
#include "IERamChip.h"
using namespace std;
class IEMenu;
class IEBank
{
    public:
        IEBank();
        virtual ~IEBank();

        enum ItemType {Default, RamChip};

        list<IEMainCategory> RegisteredMainCategories;
        list<IESubCategory> RegisteredSubCategories;
        list<IEItem> RegisteredItems;
        list<IERamChip> RegisteredRamChips;

        void AddNewMainCategory(string name, string description, IEMenu* menu);     // Adds new Main Category.
        void RemoveExistingMainCategory(string name, IEMenu *menu);                 // Removes existing Main Category.
        void EditExistingMainCategory(string name, IEMenu *menu);                   // Edit existing Main Category.
        void PrintExistingMainCategories();                                         // Shows the Main Category list.
        bool IsMainCategoryNameClear(string name);                                  // Checks if the Main Category with the input name exists or not.


        void AddNewSubCategory(string name, string description, string* tags, string parent,  IEMenu* menu);     // Adds new Sub Category.
        void RemoveExistingSubCategory(string name, IEMenu *menu, bool returnSubMenu);                           // Removes existing Sub Category.
        void EditExistingSubCategory(string name, IEMenu *menu);                                                 // Edit existing Sub Category.
        void PrintExistingSubCategories();                                                                       // Shows the Sub Category list.
        bool IsSubCategoryNameClear(string name);                                                                // Checks if the Sub Category with the input name exists or not.

        IEMainCategory* FindMainCategoryAndReturn(string name);
        IESubCategory* FindSubCategoryAndReturn(string name);

        void AddNewItem(string, string, string, float, float, int, IEMenu*, ItemType);                          // Adds new Item.
        void RemoveItem(string, IEMenu*, bool);                                                                 // Removes an existing Item.
        void ViewItemList(IEMenu*);                                                                             // Shows the Item list.

};

#endif // IEBANK_H
