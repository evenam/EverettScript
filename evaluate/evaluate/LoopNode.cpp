//
//  LoopNode.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "LoopNode.h"

LoopNode::LoopNode(TreeNode* exp, TreeNode* clause)
{
    _exp = exp;
    _clause = clause;
}

LoopNode::~LoopNode()
{
    delete _clause;
    delete _exp;
}

TreeNode* LoopNode::getExpression()
{
    return _exp;
}

TreeNode* LoopNode::getClause()
{
    return _clause;
}

void LoopNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "While:" << std::endl;
    if (_exp != NULL)
    {
        _exp->print(tabIndex + 1);
    }
    
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Loop Through:" << std::endl;
    if (_clause != NULL)
    {
        _clause->print(tabIndex + 1);
    }
}

DataType LoopNode::getReturnType()
{
    return VT_VOID;
}
