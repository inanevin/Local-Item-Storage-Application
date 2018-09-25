/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IESUBCATEGORY_H
#define IESUBCATEGORY_H

#include "IECategory.h"
#include "IEItem.h"
#include <list>

class IEMenu;
class IESubCategory : public IECategory
{
    public:
        IESubCategory();
        IESubCategory(string name, string description, string* tags, string parent);
        virtual ~IESubCategory();

        string* s_Tags;
        string s_ParentCategory;

        IESubCategory* ReturnSelf();        // Returns self address.
        list<IEItem> AssociatedItems;

        void ShowEditOptions(IEMenu*);      // Shows the edit options.
        void AddNewItem(IEItem,IEMenu*);    // Adds new item to the list of associated items.

    protected:



    private:

        void EditName(IEMenu *menu);        // Edits it's name.
        void EditDescription(IEMenu *menu); // Edits it's description.
        void ChangeParent(IEMenu*);         // Changes it's Main Category parent.
};

#endif // IESUBCATEGORY_H
