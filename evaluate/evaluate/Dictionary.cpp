//
//  Dictionary.cpp
//  Variables
//
//  Created by Everett Moser on 12/31/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#include "Dictionary.h"

// Constructor and destructor

Dictionary::Dictionary()
{
    // initialize a base scope
    _scope.push_back(new std::vector<Variable *>);
}

Dictionary::~Dictionary()
{
    if (_scope.empty())
        return;
    for (std::vector<std::vector<Variable *> *>::iterator i = _scope.begin(); i != _scope.end();)
    {
        if (!(* i)->empty())
        {
            for (std::vector<Variable *>::iterator j = (* i)->begin(); j != (* i)->end();)
            {
                delete (* j);
                (* i)->erase(j);
            }
        }
        delete (* i);
        _scope.erase(i);
    }
}

// scope manipulators

void Dictionary::increaseScope()
{
    _scope.push_back(new std::vector<Variable *>);
}

void Dictionary::decreaseScope()
{
    std::vector<Variable *> *old = _scope[_scope.size() - 1];
    _scope.pop_back();
    if (!old->empty())
    {
        for (std::vector<Variable *>::iterator i = old->begin(); i != old->end();)
        {
            delete (* i);
            old->erase(i);
        }
    }
    delete old;
}

int Dictionary::scope()
{
    return ((int)_scope.size() - 1);
}

// low-level variable access

Variable* Dictionary::getVar(std::string name)
{
    return lookup(name);
}

void Dictionary::setVar(std::string name, Variable* new_var)
{
    Variable* v = lookup(name);
    delete v;
    v = new_var;
}

void Dictionary::addVar(Variable *var)
{
    if (lookupInScope(var) == NULL)
        (_scope[_scope.size() - 1])->push_back(var);
}

void Dictionary::deleteVar(Variable *var)
{
    if (_scope.empty())
        return;
    for (std::vector<std::vector<Variable *> *>::iterator i = _scope.begin(); i != _scope.end(); i ++)
    {
        if ((* i)->empty())
            continue;
        for (std::vector<Variable *>::iterator j = (* i)->begin(); j != (* i)->end(); j ++)
        {
            if ((* j) == var)
            {
                delete (* j);
                (* i)->erase(j);
                return;
            }
        }
    }
}

void Dictionary::addVar(std::string name, DataType type, std::string val = "")
{
    if (lookupInScope(name) == NULL)
        (_scope[_scope.size() - 1])->push_back(new Variable(type, name, val));
}

void Dictionary::deleteVar(std::string name)
{
    if (_scope.empty())
        return;
    
    if (_scope[_scope.size() - 1]->empty())
        return;
    for (std::vector<Variable *>::iterator j = _scope[_scope.size() - 1]->begin(); j != _scope[_scope.size() - 1]->end(); j ++)
    {
        if ((* j)->getName() == name)
        {
            delete (* j);
            _scope[_scope.size() - 1]->erase(j);
            return;
        }
    }
}

// variable descriptors

bool Dictionary::varExists(std::string name)
{
    return (!(lookup(name) == NULL));
}

bool Dictionary::varExists(Variable* var)
{
    return (!(lookup(var) == NULL));
}


bool Dictionary::varExistsInScope(std::string name)
{
    return (!(lookupInScope(name) == NULL));
}

bool Dictionary::varExistsInScope(Variable* var)
{
    return (!(lookupInScope(var) == NULL));
}

DataType Dictionary::getVarType(std::string name)
{
    return lookupInScope(name)->getType();
}

// high-level variable access

void Dictionary::setVarVal(std::string name, std::string value)
{
    lookupInScope(name)->setVal(value);
}

std::string Dictionary::getVarVal(std::string name)
{
    return lookupInScope(name)->getVal();
}

// private helpers

Variable* Dictionary::lookup(std::string name)
{
    if (_scope.empty())
        return NULL;
    for (std::vector<std::vector<Variable *> *>::reverse_iterator i = _scope.rbegin(); i != _scope.rend(); i ++)
    {
        if ((* i)->empty())
            continue;
        for (std::vector<Variable *>::iterator j = (* i)->begin(); j != (* i)->end(); j ++)
        {
            if ((* j)->getName() == name)
                return (* j);
        }
    }
    return NULL;
}

Variable* Dictionary::lookupInScope(std::string name)
{
    if (_scope.empty())
        return NULL;
    if ((* (_scope.end() - 1))->empty())
        return NULL;
    for (std::vector<Variable *>::iterator i = (_scope[_scope.size() - 1])->begin(); i != (_scope[_scope.size() - 1])->end(); i ++)
    {
        if ((* i)->getName() == name)
            return (* i);
    }
    return NULL;
}

Variable* Dictionary::lookup(Variable* var)
{
    if (_scope.empty())
        return NULL;
    for (std::vector<std::vector<Variable *> *>::reverse_iterator i = _scope.rbegin(); i != _scope.rend(); i ++)
    {
        if ((* i)->empty())
            continue;
        for (std::vector<Variable *>::iterator j = (* i)->begin() - 1; j != (* i)->end(); j ++)
        {
            if ((* j) == var)
                return (* j);
        }
    }
    return NULL;
}

Variable* Dictionary::lookupInScope(Variable* var)
{
    if (_scope.empty())
        return NULL;
    if ((* (_scope.end() - 1))->empty())
        return NULL;
    for (std::vector<Variable *>::iterator i = (_scope[_scope.size() - 1])->begin(); i != (_scope[_scope.size() - 1])->end(); i ++)
    {
        if ((* i) == var)
            return (* i);
    }
    return NULL;
}

void Dictionary::print()
{
    std::cout << "Dictionary: \n";
    for (int i = 0; i < _scope.size(); i ++)
    {
        std::cout << "\tScope level: " << i << std::endl;
        for (int j = 0; j < _scope[i]->size(); j ++)
        {
            std::cout << dataTypeToString(_scope.at(i)->at(j)->getType()) << " " << _scope.at(i)->at(j)->getName() << " " << _scope.at(i)->at(j)->getVal() << std::endl;
        }
    }
}
