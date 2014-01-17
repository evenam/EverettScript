//
//  Function.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "Function.h"

// constructor and destructor

Function::Function(std::string identifier, DataType returnType, std::vector<Variable*> args, TreeNode* body)
{
    _id = identifier;
    _return = returnType;
    _args = args;
    _body = body;
}

Function::~Function()
{
    for (int i = 0; i < _args.size(); i ++)
    {
        delete _args[i];
    }
    _args.clear();
    delete _body;
}

// mutators :P

DataType Function::getReturnType()
{
    return _return;
}

std::string Function::getIdentifier()
{
    return _id;
}

std::vector<Variable*> Function::getArguments()
{
    return _args;
}

TreeNode* Function::getBody()
{
    return _body;
}
