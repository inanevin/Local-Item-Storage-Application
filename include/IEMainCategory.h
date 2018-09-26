/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IEMAINCATEGORY_H
#define IEMAINCATEGORY_H
#include "IESubCategory.h"
#include <list>
#include <iostream>

using namespace std;
class IEMenu;
class IEMainCategory : public IECategory
{
    public:

        IEMainCategory();
        IEMainCategory(string,string);
        virtual ~IEMainCategory();

        list<IESubCategory> AssociatedSubCategories;

        void ShowEditOptions(IEMenu *menu);                     // Shows the edit options of this category.
        void PrintAssociatedSubCategories();                    // Shows the list of associated sub categories.
        void AddNewSubCategory(IESubCategory subCategory);      // Adds new sub category to the associated sub categories list.
        void RemoveSubCategory(string);                         // Removes a sub category from the associated sub categories list.
        IEMainCategory* ReturnSelf();                           // Returns self address.

    protected:


    private:
        void EditName(IEMenu *menu);                            // Edits it's name.
        void EditDescription(IEMenu *menu);                     // Edits it's description.

};

#endif // IEMAINCATEGORY_H
