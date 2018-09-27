/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IEMenu.h"

IEMenu::IEMenu()
{
    // Point to new objects.
    C_Controller = new IEConsoleController;
    T_Controller = new IETimeController;
    Bank = new IEBank;
    Balancer = new IEBalancer;

    // Initialize Main Menu
    INITMainMenu();
}

IEMenu::~IEMenu()
{
    // Free the memory
    delete C_Controller;
    delete T_Controller;
    delete Bank;
    delete Balancer;
    delete this;
}

void IEMenu::INITMainMenu()
{
    // Prompt the user
    cout << "Welcome! Please select one of the actions below: " << endl;
    cout << "\n";

    // User Action Prompts
    cout << "Press 1 Key: Main Category Options" << endl;
    cout << "Press 2 Key: Sub Category Options" << endl;
    cout << "Press 3 Key: Item Options" << endl;
    cout << "Press 4 Key: Show Balance Statistics" << endl;
    cout << "Press 5 Key: About Author" << endl;
    cout << "Press 0 Key: Exit the Application" << endl;
    cout << "\n" << "Your Choice: ";

    // Receive User Input
    ReceiveUserInput();
}

void IEMenu::ReceiveUserInput()
{
    // Loop it if the user gives wrong input.
    while(true)
    {
        // Declare string variable for user key press and store the value that is read from the user via keyboard.
        string s_UserPreference;
        cin >> s_UserPreference;

        // Check User Preference

        if(s_UserPreference == "1")
        {
            // Clean Console
            C_Controller->CleanConsole();

            // Initialize Main Category Options
            INITCategoryOptions(Main);

            break;
        }
        else if (s_UserPreference == "2")
        {
            // Clean Console
            C_Controller->CleanConsole();

            // Initialize Sub Category Options
            INITCategoryOptions (Sub);
            break;
        }
        else if (s_UserPreference == "3")
        {
            // Clean Console
            C_Controller->CleanConsole();

            // Initialize Item Options
            INITItemOptions ();
            break;
        }
        else if (s_UserPreference == "4")
        {
            // Initialize Balance Statistics
            INITBalanceStatistics();
            break;
        }
        else if(s_UserPreference == "5")
        {
            ShowAuthor();
        }
        else if(s_UserPreference == "0")
        {
            // Exit the application.
        }
    }

}

void IEMenu::ShowAuthor()
{
    cout << "\n -----------------------------\n";
    for(int x = 0; x<3; x++)
    {
        if(x != 0 && x != 1)
             cout << "|                             |\n";

        if(x == 0)
            cout << "|   Author: Inan Evin         |\n";
        else if(x == 1)
            cout << "|   Website: www.inanevin.com |\n";
    }
    cout << " -----------------------------\n\n";

    INITMainMenu();
}

void IEMenu::INITCategoryOptions(CategoryType categoryType)
{
    // Store whether we are initialized by Sub Category or Main Category, in order to prompt the user appropriately.
    string categoryTypeText;


    if(categoryType == Main)
        categoryTypeText = "Main";
    else
        categoryTypeText = "Sub";



    // Prompt User
    cout << "Category Options:\n " << endl;
    cout << "Press 1 Key: Add New " << categoryTypeText << " Category" << endl;
    cout << "Press 2 Key: Remove Existing " << categoryTypeText << " Category" << endl;
    cout << "Press 3 Key: Edit Existing " <<categoryTypeText << " Category" << endl;
    cout << "Press 4 Key: View Existing " <<categoryTypeText << " Category List" << endl;
    cout << "Press 0 Key: Return to Main Menu" << endl;

    // Declare variables to store user input.
    string s_UserChoice;

    // Read User Input
    cout << "\nYour Choice: ";
    cin >> s_UserChoice;

    // Check User Input & Act
    if(s_UserChoice == "0")
    {
        // Return to Main Menu.
        ClearAndReturnTo(MainMenu);
    }

    else if(s_UserChoice == "1")
    {
        // Prompt User
        cout << "\nPlease start entering " <<categoryTypeText << " Category Info below." << endl;
        cout << "(type in (0) to cancel and return to the Main Menu." << endl;
        cout << "(type in (1) to cancel and return to the " <<categoryTypeText << " Category Options Menu.)\n" << endl;

        // Start the necessary function to add a new Sub/Main Category
        if(categoryType == Main)
            ReceiveNewMainCategoryData();
        else
            ReceiveNewSubCategoryData();

    }

    else if(s_UserChoice == "2")
    {
        // Prompt user and offer choices.
        cout << "\nPlease type in the name of the category that you want to remove:" << endl;
        cout << "(type in (0) to cancel and return to the Main Menu." << endl;
        cout << "(type in (1) to cancel and return to the " << categoryTypeText << " Category Options Menu.)\n" << endl;

        // Start the necessary function to remove a new Sub/Main Category
        if(categoryType == Main)
            ReceiveRemoveMainCategoryData();
        else
            ReceiveRemoveSubCategoryData();
    }

    else if(s_UserChoice == "3")
    {
        // Prompt user and offer choices.
        cout << "\nPlease type in the name of the category that you want to edit:" << endl;
        cout << "(type in (0) to cancel and return to the Main Menu." << endl;
        cout << "(type in (1) to cancel and return to the " << categoryTypeText << " Category Options Menu.)\n" << endl;

        // Start the necessary function to edit a new Sub/Main Category
        if(categoryType == Main)
            ReceiveEditMainCategoryData();
        else
            ReceiveEditSubCategoryData();
        }

    else if(s_UserChoice == "4")
    {
        // Start the necessary function to show existing new Sub/Main Category
        if(categoryType == Main)
            ShowExistingMainCategories();
        else
            ShowExistingSubCategories();
    }
    else
    {
        // Invalid choice
        cout << "Invalid choice!" << endl;
        ClearAndReturnTo(CategoryOptionsMenu, Failure, 2);
    }

}

void IEMenu::INITItemOptions()
{
    // Prompt the user and offer choices.
    cout << "Item Options Menu\n" << endl;

    cout << "Press 1 Key: Add New Item" << endl;
    cout << "Press 2 Key: Remove Existing Item" << endl;
    cout << "Press 3 Key: View Item List" << endl;
    cout << "Press (-1) Key: Return to Main Menu" << endl;

    // Store user choice.
    string s_UserInput;
    cout << "\nYour Choice: ";
    cin >> s_UserInput;

    // Check user choice and act.
    if(s_UserInput == "-1")
    {
        ClearAndReturnTo(MainMenu);
        return;
    }
    else if(s_UserInput == "1")
    {
        // Declare the vars for a new item.
        string s_Name;
        string s_Desc;
        string s_ParentSubCategory;
        float f_BuyPrice;
        float f_SellPrice;
        int i_Quantity;

        // Check if the user types the data of the item, or wants to cancel the operation.

        cout << "Name: ";
        cin >> s_Name;

        if(s_Name == "-1")
        {
            ClearAndReturnTo(MainMenu);
            return;
        }

        cout << "Description: ";
        cin >> s_Desc;

        if(s_Desc == "-1")
        {
            ClearAndReturnTo(MainMenu);
            return;
        }

        cout << "Parent Sub Category: ";
        cin >> s_ParentSubCategory;

        if(s_ParentSubCategory == "-1")
        {
            ClearAndReturnTo(MainMenu);
            return;
        }

        // Check if the sub category that the user typed as a parent exists.
        bool b_SubCategoryExists = !Bank->IsSubCategoryNameClear(s_ParentSubCategory);

        if(!b_SubCategoryExists)
        {
            cout << "No sub category with the name '" << s_ParentSubCategory << "' can be found!" << endl;
            ClearAndReturnTo(SubCategoryOptionsMenu, Failure, 2);
            return;
        }

        cout << "Buy Price: ";
        cin >> f_BuyPrice;

        if(f_BuyPrice == -1)
        {
            ClearAndReturnTo(MainMenu);
            return;
        }

        cout << "Sell Price: ";
        cin >> f_SellPrice;

        if(f_SellPrice == -1)
        {
            ClearAndReturnTo(MainMenu);
            return;
        }

        cout << "Quantity: ";
        cin >> i_Quantity;

        if(i_Quantity == -1)
        {
            ClearAndReturnTo(MainMenu);
            return;
        }

        cout << "Please select the item type:\n";
        cout << "Press 1 Key: Default Item" << endl;
        cout << "Press 2 Key: Ram Chip" << endl;
        cout << "Your Choice: ";

        string s_Choice;
        cin >> s_Choice;

        if(s_Choice == "-1")
        {
            ClearAndReturnTo(MainMenu);
            return;
        }
        else if(s_Choice == "1")
        {
            // If everything fits, add new item categorized as "DEFAULT"
            Bank->AddNewItem(s_Name, s_Desc, s_ParentSubCategory, f_BuyPrice, f_SellPrice, i_Quantity, this, Bank->Default);
            return;
        }
        else if(s_Choice == "2")
        {
            // If everything fits, add new item categorized as "DEFAULT"
            Bank->AddNewItem(s_Name, s_Desc, s_ParentSubCategory, f_BuyPrice, f_SellPrice, i_Quantity, this, Bank->RamChip);
            return;
        }
        else
        {
            // If everything fits, add new item categorized as "DEFAULT"
            Bank->AddNewItem(s_Name, s_Desc, s_ParentSubCategory, f_BuyPrice, f_SellPrice, i_Quantity, this, Bank->Default);
            return;
        }
    }
    else if(s_UserInput == "2")
    {
        string s_Name;

        cout << "Name: ";
        cin >> s_Name;

        if(s_Name == "-1")
        {
            ClearAndReturnTo(MainMenu);
            return;
        }

        // Remove item.
        Bank->RemoveItem(s_Name, this, true);
        return;
    }
    else if(s_UserInput == "3")
    {
        // Show items.
        ShowExistingItems();
        return;
    }
    else
    {
        // Invalid Choice.
        cout << "Invalid input!" << endl;
        ClearAndReturnTo(ItemOptionsMenu, Failure, 1);
    }


}

void IEMenu::ShowExistingMainCategories()
{
    cout << "\n---------------------------------" << endl;          // Make the necessary prompt screen adjustments.
    cout << "\nList of the existing categories: " << endl;
    Bank->PrintExistingMainCategories();                            // Print existing main categories.
    cout << "\n";
    INITCategoryOptions(Main);                                      // Return back to Sub/Main Category Options Menu.
}

void IEMenu::ShowExistingSubCategories()
{
    cout << "\n---------------------------------" << endl;          // Make the necessary prompt screen adjustments.
    cout << "\nList of the existing sub categories: " << endl;
    Bank->PrintExistingSubCategories();                             // Print existing sub categories.
    cout << "\n";
    INITCategoryOptions(Sub);                                       // Return back to Sub/Main Category Options Menu.
}

void IEMenu::ShowExistingItems()
{
    cout << "\n---------------------------------" << endl;          // Make the necessary prompt screen adjustments.
    cout << "\nList of the existing sub categories: " << endl;
    Bank->ViewItemList(this);                                       // Print existing items.
    cout << "\n";
    INITItemOptions();                                              // Return back to Item Options Menu.
}

void IEMenu::INITBalanceStatistics()
{
    Balancer->PrintStatistics(this);                                // Print statistics.
    INITMainMenu();                                                 // Return back to Main Menu.
}

void IEMenu::ReceiveNewMainCategoryData()
{
    // Declare variables to store user input.
    string s_CategoryName;
    string s_CategoryDescription;

    // Read user input and store it.
    cout << "Category Name: ";
    cin >> s_CategoryName;

    // Check user input, return to main menu if necessary.
    if(s_CategoryName == "0")
    {
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_CategoryName == "1")
    {
        ClearAndReturnTo(CategoryOptionsMenu, Failure, 2);
        return;
    }

    // Read user input and store it.
    cout << "Category Description: ";
    cin >> s_CategoryDescription;

    // Check user input, return to main menu if necessary.
    if(s_CategoryDescription == "0")
    {
        // Return to Main Menu.
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_CategoryDescription == "1")
    {
        // Return to Main Category Options Menu.
        ClearAndReturnTo(CategoryOptionsMenu, Failure,  2);
        return;
    }

    // Add new Main Category
    Bank->AddNewMainCategory(s_CategoryName, s_CategoryDescription, this);    // Add new Main Category
}

void IEMenu::ReceiveNewSubCategoryData()
{
    // Declare variables to store user input.
    string s_SubCategoryName;
    string s_SubCategoryDescription;
    string* s_SubTags;
    string s_TagCount;

    // Read user input and store it.
    cout << "Sub Category Name: ";
    cin >> s_SubCategoryName;

    // Check user input, return to main menu if necessary.
    if(s_SubCategoryName == "0")
    {
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_SubCategoryName == "1")
    {
        ClearAndReturnTo(SubCategoryOptionsMenu, Failure, 2);
        return;
    }

    // Read user input and store it.
    cout << "Sub Category Description: ";
    cin >> s_SubCategoryDescription;

    // Check user input, return to main menu if necessary.
    if(s_SubCategoryDescription == "0")
    {
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_SubCategoryDescription == "1")
    {
        ClearAndReturnTo(SubCategoryOptionsMenu, Failure,  2);
        return;
    }

    // Declare & store the parent category of this sub category.
    string s_ParentCategory;
    cout << "Parent Category: ";
    cin >> s_ParentCategory;
    bool b_DoesNameExist;

    // Does the main category exist?
    b_DoesNameExist = !Bank->IsMainCategoryNameClear(s_ParentCategory);

    if(!b_DoesNameExist)
    {
        cout << "No Main Category with the name " << s_ParentCategory << "!" << endl;
        ClearAndReturnTo(SubCategoryOptionsMenu, Failure, 3);
        return;
    }

    cout << "Tag Count: ";
    cin >> s_TagCount;

    int i_TagCount = CheckTagCountAndAct(s_TagCount);

    if(i_TagCount > MAXTAGCOUNT)
    {
        cout << "\nInvalid tag count! Maximum allowed tag count is " << MAXTAGCOUNT << endl;
        ClearAndReturnTo(SubCategoryOptionsMenu, Failure, 3);
    }

    // Point to new array of strings.
    s_SubTags = new string[i_TagCount];

    // Prompt the user to type each tag.
    for(int x = 0; x < i_TagCount; x++)
    {
        cout << "Enter the " << x + 1 << ". tag: ";
        cin >> s_SubTags [x];
    }

    // Add new Sub Category.
    Bank->AddNewSubCategory(s_SubCategoryName, s_SubCategoryDescription, s_SubTags, s_ParentCategory, this);    // Add new Main Category

}

void IEMenu::ReceiveRemoveMainCategoryData()
{
    // Declare variables to store user input.
    string s_CategoryName;

    // Read user input and store it.
    cout << "Category Name: ";
    cin >> s_CategoryName;

    // Check user input, return to main menu if necessary.
    if(s_CategoryName == "0")
    {
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_CategoryName == "1")
    {
        ClearAndReturnTo(CategoryOptionsMenu, Failure, 2);
        return;
    }

    // Remove Main Category.
    Bank->RemoveExistingMainCategory(s_CategoryName, this);

}

void IEMenu::ReceiveRemoveSubCategoryData()
{
    // Declare variables to store user input.
    string s_CategoryName;

    // Read user input and store it.
    cout << "Category Name: ";
    cin >> s_CategoryName;

    // Check user input, return to main menu if necessary.
    if(s_CategoryName == "0")
    {
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_CategoryName == "1")
    {
        ClearAndReturnTo(SubCategoryOptionsMenu, Failure, 2);
        return;
    }

    // Remove Sub Category
    Bank->RemoveExistingSubCategory(s_CategoryName, this, true);

}


void IEMenu::ReceiveEditMainCategoryData()
{
    // Declare variables to store user input.
    string s_CategoryName;

    // Read user input and store it.
    cout << "Category Name: ";
    cin >> s_CategoryName;

    // Check user input, return to main menu if necessary.
    if(s_CategoryName == "0")
    {
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_CategoryName == "1")
    {
        ClearAndReturnTo(CategoryOptionsMenu, Failure, 2);
        return;
    }

    // Edit Main Category.
    Bank->EditExistingMainCategory(s_CategoryName, this);

}

void IEMenu::ReceiveEditSubCategoryData()
{
    // Declare variables to store user input.
    string s_CategoryName;

    // Read user input and store it.
    cout << "Category Name: ";
    cin >> s_CategoryName;

    // Check user input, return to main menu if necessary.
    if(s_CategoryName == "0")
    {
        ClearAndReturnTo(MainMenu, Failure, 2);
        return;
    }
    else if(s_CategoryName == "1")
    {
        ClearAndReturnTo(CategoryOptionsMenu, Failure, 2);
        return;
    }

    // Edit Sub Category.
    Bank->EditExistingSubCategory(s_CategoryName, this);

}


void IEMenu::ClearAndReturnTo(ReturnMenuType returnMenuType, OperationCompletionType completionType, int seconds, int iterateAmount)
{
    string operationCompletionText;

    // Adjust the prompt text parts.

    if(completionType == Failure)
        operationCompletionText = "\nOperation canceled, returning to ";

    else if(completionType == Success)
        operationCompletionText = "\nOperation successful, returning to ";

    // If we are to return to the main menu.
    if(returnMenuType == MainMenu)
    {
        cout << operationCompletionText<<  "Main Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->IterateConsole(iterateAmount);    // Clean the command console.
        INITMainMenu();     // Initiate the Main Menu
    }
    else if(returnMenuType == CategoryOptionsMenu)
    {
        cout << operationCompletionText <<  "Category Options Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->IterateConsole(iterateAmount);    // Clean the command console.
        INITCategoryOptions(Main);
    }
    else if(returnMenuType == SubCategoryOptionsMenu)
    {
        cout << operationCompletionText <<  "Sub Category Options Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->IterateConsole(iterateAmount);    // Clean the command console.
        INITCategoryOptions(Sub);
    }
    else if(returnMenuType == ItemOptionsMenu)
    {
        cout << operationCompletionText <<  "Item Options Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->IterateConsole(iterateAmount);    // Clean the command console.
        INITItemOptions();
    }

}

void IEMenu::ClearAndReturnTo(ReturnMenuType returnMenuType, OperationCompletionType completionType, int seconds)
{
    string operationCompletionText;

    // Adjust the prompt text parts.

    if(completionType == Failure)
        operationCompletionText = "\nOperation canceled, returning to ";

    else if(completionType == Success)
        operationCompletionText = "\nOperation successful, returning to ";

    // If we are to return to the main menu.
    if(returnMenuType == MainMenu)
    {
        cout << operationCompletionText<<  "Main Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->CleanConsole();    // Clean the command console.
        INITMainMenu();     // Initiate the Main Menu
    }
    else if(returnMenuType == CategoryOptionsMenu)
    {
        cout << operationCompletionText <<  "Category Options Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->CleanConsole();    // Clean the command console.
        INITCategoryOptions(Main);
    }
     else if(returnMenuType == SubCategoryOptionsMenu)
    {
        cout << operationCompletionText <<  "Sub Category Options Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->CleanConsole();    // Clean the command console.
        INITCategoryOptions(Sub);
    }
    else if(returnMenuType == ItemOptionsMenu)
    {
        cout << operationCompletionText <<  "Item Options Menu in "<< seconds << " seconds." << endl; // Prompt User
        T_Controller->WaitForSeconds(seconds);    // Wait for 2 seconds
        C_Controller->CleanConsole();    // Clean the command console.
        INITItemOptions();
    }

}

void IEMenu::ClearAndReturnTo(ReturnMenuType returnMenuType)
{
    // If we are to return to the main menu.
    if(returnMenuType == MainMenu)
    {
        C_Controller->CleanConsole();    // Clean the command console.
        INITMainMenu();     // Initiate the Main Menu
    }
    else if(returnMenuType == CategoryOptionsMenu)
    {
        C_Controller->CleanConsole();    // Clean the command console.
        INITCategoryOptions(Main);
    }
    else if(returnMenuType == SubCategoryOptionsMenu)
    {
        C_Controller->CleanConsole();    // Clean the command console.
        INITCategoryOptions(Sub);
    }
    else if(returnMenuType == ItemOptionsMenu)
    {
        C_Controller->CleanConsole();    // Clean the command console.
        INITItemOptions();
    }

}

int IEMenu::CheckTagCountAndAct(string tagCount)
{
    if(tagCount == "0")
        return 0;
    else if(tagCount == "1")
        return 1;
    else if(tagCount == "2")
        return 2;
    else if(tagCount == "3")
        return 3;
    else if(tagCount == "4")
        return 4;
    else if(tagCount == "5")
        return 5;
    else if(tagCount == "6")
        return 6;
    else if(tagCount == "7")
        return 7;
    else if(tagCount == "8")
        return 8;
    else if(tagCount == "9")
        return 9;
    else
        return 1;
}
