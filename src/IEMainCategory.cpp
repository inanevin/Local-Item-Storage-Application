/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IEMainCategory.h"
#include "IEMenu.h"

IEMainCategory::IEMainCategory()
{
    //ctor
}

IEMainCategory::IEMainCategory(string name, string description)
{
    s_CategoryName = name;
    s_CategoryDescription = description;

}

IEMainCategory::~IEMainCategory()
{
    //dtor
}

void IEMainCategory::ShowEditOptions(IEMenu *menu)
{
    cout << "\nPress 1 Key: To edit the name of the category" << endl;
    cout << "Press 2 Key: To edit the description of the category" << endl;

    // Declare variables to store user input.
    string s_CategoryNameC;

    // Read user input and store it.
    cout << "Your choice: ";
    cin >> s_CategoryNameC;

    // Check user input, return to main menu if necessary.
    if(s_CategoryNameC == "0")
    {
        menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 2);
        return;
    }
    else if(s_CategoryNameC == "1")
    {
        EditName(menu);
        return;
    }
    else if(s_CategoryNameC == "1")
    {
        EditDescription(menu);
        return;
    }

}

void IEMainCategory::EditName(IEMenu *menu)
{
    string s_NewName;
    cout << "\nCurrent name: " << s_CategoryName << endl;
    cout << "New name: ";
    cin >> s_NewName;

    // Cancel the operation.
    if(s_NewName == "0")
    {
        menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 2);
        return;
    }
    else
    {
        // Change the name and prompt.
        s_CategoryName = s_NewName;
        cout << "Category name has been changed!" << endl;
        cout << "New category name is: " << s_CategoryName << endl;
        menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Success, 3);    // Return to Main Category Options Menu.
    }
}

void IEMainCategory::EditDescription(IEMenu *menu)
{
    string s_NewDesc;
    cout << "\nCurrent description: " << s_CategoryDescription << endl;
    cout << "New description: ";
    cin >> s_NewDesc;

    // Cancel operation.
    if(s_NewDesc == "0")
    {
        menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 2);
        return;
    }
    else
    {
        // Edit the description and prompt.
        s_CategoryDescription = s_NewDesc;
        cout << "Category description has been changed!" << endl;
        cout << "New category description is: " << s_CategoryDescription << endl;
        menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Success, 3);    // Return to Main Category Options Menu.
    }
}

void IEMainCategory::PrintAssociatedSubCategories()
{
    if(AssociatedSubCategories.size() == 0)
    {
        cout << "No associated sub categories are found!" << endl;
        return;
    }

    cout << "Associated sub categories are:\n";
    int x = 0;

    // Iterate through the list and print the data.
    for(list<IESubCategory>::iterator it = AssociatedSubCategories.begin(); it != AssociatedSubCategories.end(); ++it)
    {
        x++;
        cout << x << "- " << it->GetCategoryName() << endl;
    }
}

void IEMainCategory::AddNewSubCategory(IESubCategory subCategory)
{
    AssociatedSubCategories.push_front(subCategory);    // Push the new sub category object to the list.
}

void IEMainCategory::RemoveSubCategory(string categoryName)
{
    // Find the sub category.
    for(list<IESubCategory>::iterator it = AssociatedSubCategories.begin(); it != AssociatedSubCategories.end(); ++it)
    {
        if(it->GetCategoryName() == categoryName)
        {
            AssociatedSubCategories.erase(it);  // Erase it from the list.
            break;
        }
    }

}


IEMainCategory* IEMainCategory::ReturnSelf()
{
    return this;
}
