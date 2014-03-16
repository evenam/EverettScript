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
	for (int i = -1; ++i < args.size(); _args[i] = args[i]);
    _body = body;
	_argsSize = args.size();
}

Function::~Function()
{
    for (int i = 0; i < _argsSize; i ++)
    {
        delete _args[i];
    }
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

Variable** Function::getArguments()
{
    return _args;
}

TreeNode* Function::getBody()
{
    return _body;
}

int Function::getNumArgs()
{
	return _argsSize;
}
