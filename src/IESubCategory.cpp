/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IESubCategory.h"
#include "IEMenu.h"

IESubCategory::IESubCategory()
{
    //ctor
}

IESubCategory::IESubCategory(string name, string description, string* tags, string parent)
{
   s_CategoryName = name;
   s_CategoryDescription = description;
   s_Tags = tags;
   s_ParentCategory = parent;
}



IESubCategory::~IESubCategory()
{
    //dtor
}

IESubCategory* IESubCategory::ReturnSelf()
{
    return this;
}

void IESubCategory::ShowEditOptions(IEMenu *menu)
{
    // Prompt
    cout << "\nPress 1 Key: To edit the name of the sub category." << endl;
    cout << "Press 2 Key: To edit the description of the sub category." << endl;
    cout << "Press 3 Key: To change the parent of the sub category." << endl;

    // Declare variables to store user input.
    string s_UserInput;

    while(true)
    {
        // Read user input and store it.
        cout << "Your choice: ";
        cin >> s_UserInput;

        // Check user input, return to main menu if necessary or call the corresponding function.
        if(s_UserInput == "0")
        {
            menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 2);
            return;
        }
        else if(s_UserInput == "1")
        {
            EditName(menu);
            return;
        }
        else if(s_UserInput == "2")
        {
            EditDescription(menu);
            return;
        }
        else if(s_UserInput == "3")
        {
            ChangeParent(menu);
            return;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }
    }

}


void IESubCategory::EditName(IEMenu *menu)
{
    string s_NewName;
    cout << "\nCurrent name: " << s_CategoryName << endl;
    cout << "New name: ";
    cin >> s_NewName;

    // Cancel the operation.
    if(s_NewName == "0")
    {
        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 2);
        return;
    }
    else
    {
        // Change the name of the sub category that is registered to the list of associated sub categories of the main category that this sub category is associated to.
        for(list<IEMainCategory>::iterator it = menu->Bank->RegisteredMainCategories.begin(); it != menu->Bank->RegisteredMainCategories.end(); ++it)
        {
            if(it->GetCategoryName() == s_ParentCategory)
            {
                for(list<IESubCategory>::iterator itS = it->AssociatedSubCategories.begin(); itS != it->AssociatedSubCategories.end(); ++itS)
                {
                    if(itS->GetCategoryName() == this->s_CategoryName)
                    {
                        itS->s_CategoryName = s_NewName;
                        break;
                    }
                }
                break;
            }
        }

        // Change the var.
        s_CategoryName = s_NewName;

        cout << "Sub category name has been changed!" << endl;
        cout << "New sub category name is: " << s_CategoryName << endl;
        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Success, 3);
    }
}

void IESubCategory::EditDescription(IEMenu *menu)
{
    string s_NewDesc;
    cout << "\nCurrent description: " << s_CategoryDescription << endl;
    cout << "New description: ";
    cin >> s_NewDesc;

    // Cancel operation.
    if(s_NewDesc == "0")
    {
        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 2);
        return;
    }
    else
    {
        // Edit the description.
        s_CategoryDescription = s_NewDesc;
        cout << "Sub category description has been changed!" << endl;
        cout << "New sub category description is: " << s_CategoryDescription << endl;
        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Success, 3);
    }
}

void IESubCategory::ChangeParent(IEMenu* menu)
{
    string s_NewParent;
    cout << "\nCurrent Parent: " << s_ParentCategory << endl;
    cout << "New Parent: ";
    cin >> s_NewParent;

    // Cancel the operation.
    if(s_NewParent == "0")
    {
        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 2);
        return;
    }
    else
    {
        // Check if the new parent main category exists.
        bool doesCategoryExist = !menu->Bank->IsMainCategoryNameClear(s_NewParent);
        if(doesCategoryExist)
        {
            // Remove the sub category from the list of it's current main category parent.
            for(list<IEMainCategory>::iterator it = menu->Bank->RegisteredMainCategories.begin(); it != menu->Bank->RegisteredMainCategories.end(); ++it)
            {
                if(it->GetCategoryName() == s_ParentCategory)
                {
                    it->RemoveSubCategory(this->s_CategoryName);
                    break;
                }
            }

            // Add the sub category to the list of it's new parent.
            for(list<IEMainCategory>::iterator it = menu->Bank->RegisteredMainCategories.begin(); it != menu->Bank->RegisteredMainCategories.end(); ++it)
            {
                if(it->GetCategoryName() == s_NewParent)
                {
                    it->AddNewSubCategory(*this);
                    break;
                }
            }
            // Change the var.
            s_ParentCategory = s_NewParent;
        }
        else
        {
            cout << "A main category with the name '" << s_NewParent << "' could not be found!" << endl;
            menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 2);
        }
    }
    menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Success, 3);
}

void IESubCategory::AddNewItem(IEItem item, IEMenu* menu)
{
    AssociatedItems.push_front(item);       // Push the new item to the list.
}
