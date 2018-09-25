/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#ifndef IECATEGORY_H
#define IECATEGORY_H
#include <iostream>

using namespace std;

class IECategory
{
    public:
        IECategory();
        virtual ~IECategory();


        string GetCategoryName() const;         // Returns the category name.
        string GetCategoryDescription() const;  // Returns the category description.

    protected:

        string s_CategoryName;
        string s_CategoryDescription;

};

#endif // IECATEGORY_H
