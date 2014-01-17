//
//  ValueNodes.cpp
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "ValueNodes.h"

NumberNode::NumberNode(std::string number)
{
    _val = number;
}

NumberNode::~NumberNode()
{
    _val = "";
}

std::string NumberNode::getValue()
{
    return _val;
}

void NumberNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Number Value: " << _val << std::endl;
}

DataType NumberNode::getReturnType()
{
    return VT_NUMBER;
}

StringNode::StringNode(std::string string)
{
    _val = string;
}

StringNode::~StringNode()
{
    _val = "";
}

std::string StringNode::getValue()
{
    return _val;
}

void StringNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "String Value: " << _val << std::endl;
}

DataType StringNode::getReturnType()
{
    return VT_STRING;
}

BooleanNode::BooleanNode(std::string boolean)
{
    _val = boolean;
}

BooleanNode::~BooleanNode()
{
    _val = "";
}

std::string BooleanNode::getValue()
{
  return _val;
}

void BooleanNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Boolean Value: " << _val << std::endl;
}

DataType BooleanNode::getReturnType()
{
    return VT_BOOLEAN;
}
