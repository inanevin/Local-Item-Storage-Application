/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IEMENU_H
#define IEMENU_H
#define MAXTAGCOUNT 15
#include "IEConsoleController.h"
#include "IETimeController.h"
#include "IEBank.h"
#include "IEBalancer.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

#define SLEEPSECONDMULTIPLIER 1000000
using namespace std;

class IEMenu
{
    public:
        IEMenu();
        virtual ~IEMenu();

        IEConsoleController *C_Controller;
        IETimeController *T_Controller;
        IEBank *Bank;
        IEBalancer *Balancer;

        enum ReturnMenuType {MainMenu, CategoryOptionsMenu, SubCategoryOptionsMenu, ItemOptionsMenu};   // Enum for selecting which menu to return when needed.
        enum OperationCompletionType {Failure, Success};    // Completion type, affects return to menu texts.
        enum CategoryType {Main, Sub};  // Category type to initialize functions of on the menu.

        void INITMainMenu();                        // Initializes the Main Menu.
        void INITCategoryOptions(CategoryType);     // Initializes the Category Options Menu.
        void INITItemOptions();                     // Initializes the Item Options Menu.
        void INITBalanceStatistics();               // Initializes the Balance Statistics Menu.
        void ReceiveUserInput();                    // Waits user key, checks it and executes the necessary action.

        void ReceiveNewMainCategoryData();          // Receives Main Category Data to add.
        void ReceiveRemoveMainCategoryData();       // Receives Main Category Data to remove.
        void ReceiveEditMainCategoryData();         // Receives Main Category Data to edit.
        void ShowExistingMainCategories();          // Shows existing Main Categories.

        void ReceiveNewSubCategoryData();           // Receives Sub Category Data to add.
        void ReceiveRemoveSubCategoryData();        // Receives Sub Category Data to remove.
        void ReceiveEditSubCategoryData();          // Receives Sub Category Data to edit.
        void ShowExistingSubCategories();           // Shows existing Sub Categories.

        void ShowExistingItems();                   // Shows existing items.
        void ShowAuthor();

        void ClearAndReturnTo(ReturnMenuType returnMenuType, OperationCompletionType completionType, int seconds, int iterateAmount);   // Returns to a specified sub menu.
        void ClearAndReturnTo(ReturnMenuType returnMenuType, OperationCompletionType completionType, int seconds);   // Returns to a specified sub menu.
        void ClearAndReturnTo(ReturnMenuType returnMenuType);   // Returns to a specified sub menu.

        int CheckTagCountAndAct(string);  // Checks the tag count input and turns it into an integer.

};

#endif // IEMENU_H
