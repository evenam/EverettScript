//
//  FunctionCallNode.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "FunctionCallNode.h"

FunctionCallNode::FunctionCallNode(std::string identifier, std::vector<TreeNode*> args)
{
    _id = identifier;
    _args = args;
}

FunctionCallNode::~FunctionCallNode()
{
    for (int i = 0; i < _args.size(); i ++)
    {
        if (_args[i] != NULL)
            delete _args[i];
    }
    _args.clear();
    _id = "";
}

std::string FunctionCallNode::getIdentifier()
{
    return _id;
}

std::vector<TreeNode*> FunctionCallNode::getArguments()
{
    return _args;
}

void FunctionCallNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Function Call: " << _id << std::endl;
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Arguments:" << std::endl;
    for (int i = 0; i < _args.size(); i ++)
    {
        if (_args[i] != NULL)
            _args[i]->print(tabIndex + 1);
    }
}

DataType FunctionCallNode::getReturnType()
{
    if (isBuiltin(_id))
        return getBuiltinDataType(_id);
    return Functionary::getRef()->getFunctionReturnType(_id);
}

ReturnNode::ReturnNode(TreeNode* exp)
{
    _exp = exp;
}

ReturnNode::~ReturnNode()
{
    delete _exp;
}

TreeNode* ReturnNode::getExpression()
{
    return _exp;
}

void ReturnNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Return: \n";
    if (_exp != NULL)
        _exp->print(tabIndex + 1);
}

DataType ReturnNode::getReturnType()
{
    return _exp->getReturnType();
}
