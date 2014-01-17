//
//  ConditionalNode.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "ConditionalNode.h"

ConditionalNode::ConditionalNode(TreeNode* exp, TreeNode* true_, TreeNode* false_)
{
    _exp = exp;
    _true = true_;
    _false = false_;
}

ConditionalNode::~ConditionalNode()
{
    delete _false;
    delete _true;
    delete _exp;
}

TreeNode* ConditionalNode::getExpression()
{
    return _exp;
}

TreeNode* ConditionalNode::getTrueClause()
{
    return _true;
}

TreeNode* ConditionalNode::getFalseClause()
{
    return _false;
}

void ConditionalNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "If:" << std::endl;
    if (_exp != NULL)
    {
        _exp->print(tabIndex + 1);
    }
    
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Then:" << std::endl;
    if (_true != NULL)
    {
        _true->print(tabIndex + 1);
    }
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Else:" << std::endl;
    if (_false != NULL)
    {
        _false->print(tabIndex + 1);
    }
}

DataType ConditionalNode::getReturnType()
{
    return VT_VOID;
}
