/*
    Author: Inan Evin (2014061024)
    Date: 23.05.2016
    Author Website: www.inanevin.com
*/

#include "IECategory.h"

IECategory::IECategory()
{
    //ctor
}

IECategory::~IECategory()
{
    //dtor
}

string IECategory::GetCategoryName() const
{
    return s_CategoryName;
}

string IECategory::GetCategoryDescription() const
{
    return s_CategoryDescription;
}
