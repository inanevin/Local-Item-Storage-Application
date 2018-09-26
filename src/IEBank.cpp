/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IEBank.h"
#include "IEMenu.h"
#include "IERamChip.h"
IEBank::IEBank()
{
    //ctor
}

IEBank::~IEBank()
{
    //dtor
}

void IEBank::AddNewMainCategory(string name, string description, IEMenu* menu)
{
    // If the Main Category that we are trying to add wasn't added before.
    if(IsMainCategoryNameClear(name))
    {
        IEMainCategory newCategory(name, description);                                  // Create an object of the Main Category.
        RegisteredMainCategories.push_front(newCategory);                               // Push the object to the list.
        cout << "\nNew Category Registered with the name '" << name << "'" << endl;     // Prompt.
        menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Success, 3);            // Return to Main Category Options Menu.
    }
    else    // If the category with the same name already exists.
    {
        cout << "\nA category with the same name is already registered!" << endl;       // Prompt.
        menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 3);            // Return to Main Category Options Menu.
    }
}

void IEBank::AddNewSubCategory(string name, string description, string* tags, string parent, IEMenu* menu)
{
    if(IsSubCategoryNameClear(name))
    {
        IESubCategory newCategory(name, description, tags, parent);
        RegisteredSubCategories.push_front(newCategory);
        FindMainCategoryAndReturn(parent)->AddNewSubCategory(newCategory);              // Find the Main Category, and add this new Sub Category to it's list.
        cout << "\nNew Sub Category Registered with the name '" << name << "'" << endl;
        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Success, 3);
    }
    else
    {
        cout << "\nA sub category with the same name is already registered!" << endl;
        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 3);
    }
}

bool IEBank::IsMainCategoryNameClear(string name)
{
    // Iterate through the list of Main Categories and check if a category with the input name exists, and return accordingly.
    for(list<IEMainCategory>::iterator iterator = RegisteredMainCategories.begin(); iterator != RegisteredMainCategories.end(); ++ iterator)
    {
        if(iterator->GetCategoryName() == name)
            return false;
    }
    return true;
}

bool IEBank::IsSubCategoryNameClear(string name)
{
    // Iterate through the list of Sub Categories and check if a category with the input name exists, and return accordingly.
    for(list<IESubCategory>::iterator iterator = RegisteredSubCategories.begin(); iterator != RegisteredSubCategories.end(); ++ iterator)
    {
        if(iterator->GetCategoryName() == name)
            return false;
    }
    return true;
}

void IEBank::RemoveExistingMainCategory(string name, IEMenu *menu)
{
    // Iterate through the category list and find the category that we are trying to remove.
    for(list<IEMainCategory>::iterator it = RegisteredMainCategories.begin(); it != RegisteredMainCategories.end(); ++it)
    {
        if(it->GetCategoryName() == name)
        {
            // If the Main Category that we are trying to remove has associated sub categories with it.
            if(it->AssociatedSubCategories.size() != 0)
            {
                // Prompt user and offer choices.
                cout << "The category that you are trying to remove has associated sub categories!" << endl;
                cout << "What would you like to do to them?" << endl;

                cout << "\nPress 1 Key: Remove all sub categories." << endl;
                cout << "Press 2 Key: Re-assign sub categories with new parent." << endl;
                cout << "(Press (0) to return to Main Category Options Menu.)" << endl;

                string s_UserChoice;
                cout << "\nYour Choice: ";
                cin >> s_UserChoice;

                if(s_UserChoice == "0")         // Cancel Operation.
                {
                    menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 3);    // Return to Main Category Options Menu.
                    return;
                }
                else if(s_UserChoice == "1")    // Remove all sub categories associated with this main category.
                {
                    // Iterate through this Main Categories' sub category list.
                    for(list<IESubCategory>::iterator itS = it->AssociatedSubCategories.begin(); itS != it->AssociatedSubCategories.end(); ++itS)
                    {
                        // Remove the sub category.
                        RemoveExistingSubCategory(itS->GetCategoryName(), menu, false);
                    }
                }
                else if(s_UserChoice == "2")    // Reassign all the sub categories associated with this main category with a new parent.
                {
                    while(true)
                    {
                        string s_NewParent;
                        cout << "New Parent: ";
                        cin >> s_NewParent;

                        // Cancel the operation.
                        if(s_NewParent == "0")
                        {
                            menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 3);
                            return;
                        }
                        else
                        {
                            // If the candidate main category exists.
                            if(!IsMainCategoryNameClear(s_NewParent))
                            {
                                // Iterate through the associated sub categories of the main category that we are trying to remove.
                                for(list<IESubCategory>::iterator itS = it->AssociatedSubCategories.begin(); itS != it->AssociatedSubCategories.end(); ++itS)
                                {
                                    IESubCategory copySubCategory(itS->GetCategoryName(), itS->GetCategoryDescription(), itS->s_Tags, s_NewParent); // Create a new Sub Category object with the same values as the one on the list.
                                    FindMainCategoryAndReturn(s_NewParent)->AddNewSubCategory(copySubCategory); // Add the newly created object to the new parent's list.
                                    itS->s_ParentCategory = s_NewParent;    // Change the parent var.
                                    delete itS->ReturnSelf();   // Delete the current one on the list, because we already have created a new object from it and added that to new parent's list.
                                    cout << "The sub category " << itS->GetCategoryName() << " has been re-assigned to it's new parent '" << s_NewParent << "'!" << endl;
                                }
                                break;
                            }
                            else    // If the main category does not exist.
                                cout << "No main category with the name " << s_NewParent << " can be found! Try again or type (0) to return to Main Category Options Menu.\n" << endl;

                        }
                    }
                }
            }

            cout << "The main category '" << it->GetCategoryName() << "' is removed from the category list." << endl;
            RegisteredMainCategories.erase(it); // Remove the main category from the list.
            delete it->ReturnSelf();    // Free the memory.
            menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Success, 3);    // Return to Main Category Menu.
            return;
        }
    }

    cout << "\nCategory with the name '" << name << "' could not be found!" << endl;
    menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 3);    // Return to Main Category Menu.
}

void IEBank::RemoveExistingSubCategory(string name, IEMenu *menu, bool returnSubMenu)
{
    for(list<IESubCategory>::iterator it = RegisteredSubCategories.begin(); it != RegisteredSubCategories.end(); ++it)
    {
        if(it->GetCategoryName() == name)
        {
            if(it->AssociatedItems.size() != 0)
            {
                cout << "The sub category you are trying to remove has associated items with it." << endl;
                cout << "What would you like to do with the items?\n" << endl;

                cout << "Press 1 Key: Remove all items associated with this sub category" << endl;
                cout << "Press 2 Key: Re-assign all items with new parent sub category" << endl;
                cout << "Press 0 Key: Cancel and return to Sub Category Options Menu" << endl;

                while(true)
                {
                    cout << "\nYour Choice: ";

                    string s_UserInput;
                    cin >> s_UserInput;

                    if(s_UserInput == "0")
                    {
                        menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 2);
                        return;
                    }
                    else if(s_UserInput == "1")
                    {
                        for(list<IEItem>::iterator itI = it->AssociatedItems.begin(); itI != it->AssociatedItems.end(); ++itI)
                        {
                            RemoveItem(itI->GetItemName(), menu, false);
                        }
                        break;
                    }
                    else if(s_UserInput == "2")
                    {
                        while(true)
                        {
                            string s_NewParent;
                            cout << "\nCurrent Parent: " << name << endl;
                            cout << "New Parent: ";
                            cin >> s_NewParent;

                            if(s_NewParent == "0")
                            {
                                menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 2);
                                return;
                            }


                            bool b_CategoryExists = !IsSubCategoryNameClear(s_NewParent);

                            if(b_CategoryExists)
                            {
                                    for(list<IEItem>::iterator itR = RegisteredItems.begin(); itR != RegisteredItems.end(); ++itR)
                                    {
                                            if(itR->GetParentSubCategory() == name)
                                            {
                                                itR->SetParentSubCategory(s_NewParent);
                                                FindSubCategoryAndReturn(s_NewParent)->AddNewItem(*itR->ReturnSelf(), menu);
                                                cout << "The item '" << itR->GetItemName() << "' has been reassigned to it's new parent '" << s_NewParent << "'!" << endl;
                                            }
                                    }

                                break;
                            }
                            else
                                cout << "No sub category with the name '" << s_NewParent << "' exists. Try again!" << endl;
                        }
                        break;
                    }
                }

            }
            cout << "The sub category '" << it->GetCategoryName() << "' is removed from the category list." << endl;
            RegisteredSubCategories.erase(it);
            FindMainCategoryAndReturn(it->s_ParentCategory)->RemoveSubCategory(it->GetCategoryName());
            delete it->ReturnSelf();

            if(returnSubMenu)
                menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Success, 3);

            return;
        }
    }


    cout << "\nSub category with the name '" << name << "' could not be found!" << endl;
    menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 3);
}

void IEBank::EditExistingMainCategory(string name, IEMenu *menu)
{
    // Iterate through the list and find the category.
    for(list<IEMainCategory>::iterator it = RegisteredMainCategories.begin(); it != RegisteredMainCategories.end(); ++it)
    {
        if(it->GetCategoryName() == name)
        {
            it->ShowEditOptions(menu);  // Edit the category.
            return;
        }
    }

    cout << "\nThe main category with the name '" << name << "' could not be found!" << endl;
    menu->ClearAndReturnTo(menu->CategoryOptionsMenu, menu->Failure, 3);
}


void IEBank::EditExistingSubCategory(string name, IEMenu *menu)
{
    for(list<IESubCategory>::iterator it = RegisteredSubCategories.begin(); it != RegisteredSubCategories.end(); ++it)
    {
        if(it->GetCategoryName() == name)
        {
            it->ShowEditOptions(menu);
            return;
        }
    }

    cout << "\nThe sub category with the name '" << name << "' could not be found!" << endl;
    menu->ClearAndReturnTo(menu->SubCategoryOptionsMenu, menu->Failure, 3);
}

void IEBank::PrintExistingMainCategories()
{
    if(RegisteredMainCategories.size() == 0)
    {
        cout << "No categories are registered!" << endl;
        cout << "\n---------------------------------\n" << endl;
        return;
    }

    for(list<IEMainCategory>::iterator it = RegisteredMainCategories.begin(); it != RegisteredMainCategories.end(); ++it)
    {
        // Print the data.
        cout << "-> " << endl << "Name: " << it->GetCategoryName() << endl << "Description: " << it->GetCategoryDescription() << endl;
        it->PrintAssociatedSubCategories();
    }

    cout << "\nTotal category count: " << RegisteredMainCategories.size() << endl;
    cout << "\n---------------------------------\n" << endl;
}


void IEBank::PrintExistingSubCategories()
{
    if(RegisteredSubCategories.size() == 0)
    {
        cout << "No categories are registered!" << endl;
        cout << "\n---------------------------------\n" << endl;
        return;
    }

    for(list<IESubCategory>::iterator it = RegisteredSubCategories.begin(); it != RegisteredSubCategories.end(); ++it)
    {
        // Print the data.
        cout << "-> " << endl << "Name: " << it->GetCategoryName() << endl << "Description: " << it->GetCategoryDescription() << endl << "Parent: " << it->s_ParentCategory <<  endl;

        if(it->AssociatedItems.size() == 0)
            cout << "No associated items are found!" << endl;
        else
        {
            cout << "Associated items are:" << endl;
            for(list<IEItem>::iterator itI = it->AssociatedItems.begin(); itI != it->AssociatedItems.end(); ++itI)
            {
                cout << "-- " << itI->GetItemName() << endl;
            }
        }
    }
    cout << "\nTotal sub category count: " << RegisteredSubCategories.size() << endl;
    cout << "\n---------------------------------\n" << endl;

}


IEMainCategory* IEBank::FindMainCategoryAndReturn(string name)
{
    // Iterate list, find Category and return it.
    for(list<IEMainCategory>::iterator it = RegisteredMainCategories.begin(); it != RegisteredMainCategories.end(); ++it)
    {
        if(it->GetCategoryName() == name)
        {
            return it->ReturnSelf();
        }
    }
}

IESubCategory* IEBank::FindSubCategoryAndReturn(string name)
{
    // Iterate list, find Category and return it.
    for(list<IESubCategory>::iterator it = RegisteredSubCategories.begin(); it != RegisteredSubCategories.end(); ++it)
    {
        if(it->GetCategoryName() == name)
        {
            return it->ReturnSelf();
        }
    }
}


void IEBank::AddNewItem(string name, string desc, string parentSub, float buyP, float sellP, int quantity, IEMenu* menu, ItemType itemType)
{
    // Iterate the list and check if the item already exists.
    for(list<IEItem>::iterator it = RegisteredItems.begin(); it != RegisteredItems.end(); ++it)
    {
        if(it->GetItemName() == name)
        {
            cout << "An Item with the name !" << name << "' is already registered!" << endl;
            menu->ClearAndReturnTo(menu->ItemOptionsMenu, menu->Failure, 3);    // Return to Item Options Menu.
            return;
        }
    }

    if(itemType == Default)
    {
        IEDefaultItem item(name, desc, parentSub, buyP, sellP, quantity);       // Create an object of the item.
        RegisteredItems.push_front(item);                                       // Push the object to the list.
        item.RegisterItemData();                                                // Call the virtual method of the item to register extra data.
        cout << "\nNew item Registered with the name '" << name << "'" << endl;

        // Find the corresponding parent Sub Category of this item and add the item to it's list.
        for(list<IESubCategory>::iterator itS = RegisteredSubCategories.begin(); itS != RegisteredSubCategories.end(); ++itS)
        {
            if(itS->GetCategoryName() == parentSub)
            {
                FindSubCategoryAndReturn(parentSub)->AssociatedItems.push_front(item);
                break;
            }
        }

        menu->ClearAndReturnTo(menu->ItemOptionsMenu, menu->Success, 3);
        return;
    }
    else if(itemType == RamChip)
    {
        IERamChip item(name, desc, parentSub, buyP, sellP, quantity, "", 0, 0);       // Create an object of the item.
        item.RegisterItemData();
        RegisteredRamChips.push_front(item);                                       // Call the virtual method of the item to register extra data.
        RegisteredItems.push_front(item);                                       // Push the object to the list.
        cout << "\nNew item Registered with the name '" << name << "'" << endl;

        // Find the corresponding parent Sub Category of this item and add the item to it's list.
        for(list<IESubCategory>::iterator itS = RegisteredSubCategories.begin(); itS != RegisteredSubCategories.end(); ++itS)
        {
            if(itS->GetCategoryName() == parentSub)
            {
                FindSubCategoryAndReturn(parentSub)->AssociatedItems.push_front(item);
                break;
            }
        }

        menu->ClearAndReturnTo(menu->ItemOptionsMenu, menu->Success, 3);
        return;
    }
}

void IEBank::RemoveItem(string name, IEMenu* menu, bool returnMenu)
{
    // Find the item.
    for(list<IEItem>::iterator it = RegisteredItems.begin(); it != RegisteredItems.end(); ++it)
    {
        if(it->GetItemName() == name)
        {
            // Remove the item.
            RegisteredItems.erase(it);
            delete it->ReturnSelf();
            cout << "The item '" << it->GetItemName() << "' is removed from the item list." << endl;

            // Remove the item from it's sub category's list.
            for(list<IESubCategory>::iterator itS = RegisteredSubCategories.begin(); itS != RegisteredSubCategories.end(); ++itS)
            {
                if(itS->GetCategoryName() == it->GetParentSubCategory())
                {
                    for(list<IEItem>::iterator itR = itS->AssociatedItems.begin(); itR != itS->AssociatedItems.end(); ++itR)
                    {
                        if(itR->GetItemName() == name)
                        {
                            // Remove the item.
                            itS->AssociatedItems.erase(itR);
                            delete itR->ReturnSelf();
                            break;
                        }
                    }
                    break;
                }
            }
            if(returnMenu)
                menu->ClearAndReturnTo(menu->ItemOptionsMenu, menu->Success, 3);
            return;
        }
    }

    cout << "\nAn item with the name '" << name << "' could not be found!" << endl;
    menu->ClearAndReturnTo(menu->ItemOptionsMenu, menu->Failure, 3);
}


void IEBank::ViewItemList(IEMenu* menu)
{
    if(RegisteredItems.size() == 0)
    {
        cout << "No items are registered!" << endl;
        cout << "\n---------------------------------\n" << endl;
        menu->ClearAndReturnTo(menu->ItemOptionsMenu, menu->Failure, 3);
        return;
    }

    for(list<IEItem>::iterator it = RegisteredItems.begin(); it != RegisteredItems.end(); ++it)
    {
        // Print item data.
        cout << "->\n" << "Name: " << it->GetItemName() << "\nDescription: " << it->GetItemDescription() << "\nBuy Price: " << it->GetItemBuyPrice() << "\nSell Price: " << it->GetItemSellPrice() << endl;
        cout << "Quantity: " << it->GetItemQuantity() << "\nParent Sub Category: " << it->GetParentSubCategory() <<  endl;

        // If there exists a ram chip amongs the items, find it and print it's data.
        for(list<IERamChip>::iterator itR = RegisteredRamChips.begin(); itR != RegisteredRamChips.end(); ++itR)
        {
            if(it->GetItemName() == itR->GetItemName())
            {
                itR->ShowItemData();
                break;
            }
        }
    }

    cout << "\n---------------------------------\n" << endl;
}













