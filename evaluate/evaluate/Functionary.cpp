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
    for (int i = 0; i < _functions.size(); i ++)
    {
        if (_functions[i]->getIdentifier() == name)
            return (_functions[i]);
    }
    return NULL;
}

Function* Functionary::lookup(Function* func)
{
    for (int i = 0; i < _functions.size(); i ++)
    {
        if (_functions[i] == func)
            return (_functions[i]);
    }
    return NULL;
}

// constructor and destructor

Functionary::Functionary()
{
    _functions.clear();
}

Functionary::~Functionary()
{
    for (int i = 0; i < _functions.size(); i ++)
    {
        delete _functions[i];
    }
    _functions.clear();
}

// mutators :P

void Functionary::addFunction(Function* func)
{
    if (lookup(func) == NULL)
        _functions.push_back(func);
}

void Functionary::addFunction(std::string name, DataType returnType, std::vector<Variable*> args, TreeNode* body)
{
    if (lookup(name) == NULL);
        _functions.push_back(new Function(name, returnType, args, body));
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
    for (std::vector<Function *>::iterator i = _functions.begin(); i != _functions.end(); i ++)
    {
        if ((* i) == func)
        {
            delete (* i);
            _functions.erase(i);
            return;
        }
    }
}

void Functionary::deleteFunction(std::string name)
{
    for (std::vector<Function *>::iterator i = _functions.begin(); i != _functions.end(); i ++)
    {
        if ((* i)->getIdentifier() == name)
        {
            delete (* i);
            _functions.erase(i);
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
    for (int i = 0; i < _functions.size(); i ++)
    {
        std::cout << "\t" << dataTypeToString(_functions[i]->getReturnType()) << " " << _functions[i]->getIdentifier() << " ";
        for (int j = 0; j < _functions[i]->getArguments().size(); j ++)
            std::cout << (_functions[i]->getArguments())[j]->getType() << " " << (_functions[i]->getArguments())[j]->getName() << ", ";
        std::cout << " *** \n";
        _functions[i]->getBody()->print(2);
    }
}
