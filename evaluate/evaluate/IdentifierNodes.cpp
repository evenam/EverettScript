//
//  IdentifierNodes
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "IdentifierNodes.h"

VariableIdentifierNode::VariableIdentifierNode(std::string identifier)
{
    _id = identifier;
}

VariableIdentifierNode::~VariableIdentifierNode()
{
    _id = "";
}

std::string VariableIdentifierNode::getIdentifier()
{
    return _id;
}

void VariableIdentifierNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Variable Identifier: " << _id << std::endl;
}

DataType VariableIdentifierNode::getReturnType()
{
    return Dictionary::getRef()->getVar(_id)->getType();
}

DataTypeNode::DataTypeNode(DataType data_type)
{
    _dt = data_type;
}

DataTypeNode::~DataTypeNode()
{
    _dt = VT_VOID;
}

DataType DataTypeNode::getDataType()
{
    return _dt;
}

void DataTypeNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Data Type: " << _dt << std::endl;
}

DataType DataTypeNode::getReturnType()
{
    return VT_VOID;
}
