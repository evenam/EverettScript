//
//  Variable.cpp
//  Variables
//
//  Created by Everett Moser on 12/31/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#include "Variable.h"

// constructors and destructor

Variable::Variable(DataType type, std::string name)
{
    _type = type;
    if (type == VT_BOOLEAN)
        _val = "false";
    else if (type == VT_NUMBER)
        _val = "0";
    else if (type == VT_STRING)
        _val = "\"\"";
    else
        _val = "null";
    _name = name;
}

Variable::Variable(DataType type, std::string name, std::string val)
{
    _val = val;
    _type = type;
    _name = name;
}

Variable::~Variable()
{
    _val.clear();
    _name.clear();
}

// getters and setters :P

std::string Variable::getVal()
{
    return _val;
}

std::string Variable::getName()
{
    return _name;
}

void Variable::setVal(std::string new_val)
{
    _val = new_val;
}

DataType Variable::getType()
{
    return _type;
}
