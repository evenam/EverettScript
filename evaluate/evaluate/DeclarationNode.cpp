//
//  DeclarationNode.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "DeclarationNode.h"

DeclarationNode::DeclarationNode(TreeNode* data_type, TreeNode* identifier, TreeNode* expression)
{
    _dt = data_type;
    _id = identifier;
    _exp = expression;
}

DeclarationNode::~DeclarationNode()
{
    delete _exp;
    delete _id;
    delete _dt;
}

TreeNode* DeclarationNode::getDataType()
{
    return _dt;
}

TreeNode* DeclarationNode::getIdentifier()
{
    return _id;
}

TreeNode* DeclarationNode::getExpression()
{
    return _exp;
}

void DeclarationNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Data Type:" << std::endl;
    if (_dt != NULL)
    {
        _dt->print(tabIndex + 1);
    }
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "New Variable:" << std::endl;
    if (_id != NULL)
    {
        _id->print(tabIndex + 1);
    }
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Expression:" << std::endl;
    if (_exp != NULL)
    {
        _exp->print(tabIndex + 1);
    }
}

DataType DeclarationNode::getReturnType()
{
    return VT_VOID;
}
