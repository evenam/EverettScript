//
//  StatementNode.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "StatementNode.h"
#include "FunctionCallNode.h"

StatementNode::StatementNode(TreeNode* current, TreeNode* next)
{
    _current = current;
    _next = next;
}

StatementNode::~StatementNode()
{
    delete _next;
    delete _current;
}

TreeNode* StatementNode::getCurrent()
{
    return _current;
}

TreeNode* StatementNode::getNext()
{
    return _next;
}

void StatementNode::print(int tabIndex)
{
    if (_current != NULL)
    {
        for (int i = 0; i < tabIndex; i ++)
            std::cout << "\t";
        std::cout << "Statement:" << std::endl;
        _current->print(tabIndex + 1);
    }
    if (_next != NULL)
    {
        _next->print(tabIndex);
    }
}

DataType StatementNode::getReturnType()
{
    if (checkObjectType<ReturnNode*>(_current))
        return _current->getReturnType();
    return  VT_VOID;
}
