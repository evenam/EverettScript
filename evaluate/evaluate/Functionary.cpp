//
//  Functionary.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "Functionary.h"

// privates

Function* Functionary::lookup(std::string name)
{
    for (int i = 0; i < _numFunc; i ++)
    {
        if (_functions[i]->getIdentifier() == name)
            return (_functions[i]);
    }
    return NULL;
}

Function* Functionary::lookup(Function* func)
{
    for (int i = 0; i < _numFunc; i ++)
    {
        if (_functions[i] == func)
            return (_functions[i]);
    }
    return NULL;
}

// constructor and destructor

Functionary::Functionary()
{
    _numFunc = 0;
}

Functionary::~Functionary()
{
    for (int i = 0; i < _numFunc; i ++)
    {
        delete _functions[i];
    }
}

// mutators :P

void Functionary::addFunction(Function* func)
{
    if (lookup(func) == NULL)
        _functions[_numFunc++] = func;
}

void Functionary::addFunction(std::string name, DataType returnType, std::vector<Variable*> args, TreeNode* body)
{
    if (lookup(name) == NULL)
        _functions[_numFunc++] = new Function(name, returnType, args, body);
}

Function* Functionary::getFunction(std::string name)
{
    return (lookup(name));
}

void Functionary::setFunction(std::string name, Function* new_func)
{
    Function* f = lookup(name);
    delete f;
    f = new_func;
}

void Functionary::deleteFunction(Function* func)
{
    for (int i = 0; i < _numFunc; i ++)
    {
        if (_functions[i] == func)
        {
            delete _functions[i];
			_numFunc--;
			for (int j = i; j < _numFunc; j ++)
			{
				_functions[j] = _functions[j + 1];
			}
            return;
        }
    }
}

void Functionary::deleteFunction(std::string name)
{
    for (int i = 0; i < _numFunc; i ++)
    {
        if (_functions[i]->getIdentifier() == name)
        {
            delete _functions[i];
			_numFunc--;
			for (int j = i; j < _numFunc; j ++)
			{
				_functions[j] = _functions[j + 1];
			}
            return;
        }
    }
}

bool Functionary::functionExists(std::string name)
{
    return (!(lookup(name) == NULL));
}

bool Functionary::functionExists(Function* func)
{
    return (!(lookup(func) == NULL));
}

DataType Functionary::getFunctionReturnType(std::string name)
{
    if (lookup(name) == NULL)
        return VT_VOID;
    else
        return (lookup(name)->getReturnType());
}

void Functionary::print()
{
    std::cout << "Functionary: \n";
    for (int i = 0; i < _numFunc; i ++)
    {
        std::cout << "\t" << dataTypeToString(_functions[i]->getReturnType()) << " " << _functions[i]->getIdentifier() << " ";
        for (int j = 0; j < _functions[i]->getNumArgs(); j ++)
            std::cout << (_functions[i]->getArguments())[j]->getType() << " " << (_functions[i]->getArguments())[j]->getName() << ", ";
        std::cout << " *** \n";
        _functions[i]->getBody()->print(2);
    }
}
