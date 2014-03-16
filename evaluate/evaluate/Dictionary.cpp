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
	// _scope[SCOPE][VAR]
	_scopeNum = 1;
	for (int i = 0; i < 1024; i ++)
	{
		_varNum[i] = 0;
		for (int j = 0; j < 1024; j ++)
		{
			_scope[i][j] = NULL;
		}
	}
}

Dictionary::~Dictionary()
{
    if (_scopeNum == 0)
        return;
    for (int i = 0; i < _scopeNum; i ++)
    {
        if (_varNum[i] != 0)
        {
            for (int j = 0; j < _varNum[i]; j ++)
            {
                delete _scope[i][j];
            }
        }
    }
}

// scope manipulators

void Dictionary::increaseScope()
{
    _scopeNum++;
}

void Dictionary::decreaseScope()
{
    if (_varNum[_scopeNum - 1] != 0)
    {
        for (int j = 0; j < _varNum[_scopeNum - 1]; j ++)
        {
            delete _scope[_scopeNum - 1][j];
        }
    }
    _varNum[--_scopeNum] = 0;
}

int Dictionary::scope()
{
    return _scopeNum;
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
    if (lookupInScope(var) == NULL && _scopeNum > 0) // crazy array stuff from 3102
		_scope[_scopeNum - 1][_varNum[_scopeNum - 1]++] = var;
}

void Dictionary::deleteVar(Variable *var)
{
    if (_scopeNum == 0)
        return;
    for (int i = 0; i < _scopeNum; i ++)
    {
        if (_varNum[i] == 0)
            continue;
        for (int j = 0; i < _varNum[i]; j ++)
        {
            if (_scope[i][j] == var)
            {
                delete _scope[i][j];
				_varNum[i]--;
				for (int k = j; k < _varNum[i]; k ++)
					_scope[i][k] = _scope[i][k + 1];
                return;
            }
        }
    }
}

void Dictionary::addVar(std::string name, DataType type, std::string val = "")
{
    if (lookupInScope(name) == NULL)
        _scope[_scopeNum - 1][_varNum[_scopeNum - 1]++] = new Variable(type, name, val);
}

void Dictionary::deleteVar(std::string name)
{
    if (_scopeNum == 0)
        return;
    
    if (_scope[_scopeNum - 1]== 0)
        return;
	for (int j = 0; j < _varNum[_scopeNum - 1]; j ++)
	{
        if (_scope[_scopeNum - 1][j]->getName() == name)
        {
            delete _scope[_scopeNum - 1][j];
			_varNum[_scopeNum - 1]--;
			for (int i = j; i < _varNum[_scopeNum - 1]; i ++)
				_scope[_scopeNum - 1][i] = _scope[_scopeNum - 1][i + 1];
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
    if (_scopeNum == 0)
        return NULL;
    for (int i = _scopeNum - 1; i >= 0; i --)
    {
        if (_varNum[i] == 0)
            continue;
        for (int j = 0; j < _varNum[i]; j ++)
        {
            if (_scope[i][j]->getName() == name)
                return _scope[i][j];
        }
    }
    return NULL;
}

Variable* Dictionary::lookupInScope(std::string name)
{
    if (_scopeNum == 0)
        return NULL;
    if (_varNum[_scopeNum - 1] == 0)
        return NULL;
    for (int j = 0; j < _varNum[_scopeNum - 1]; j ++)
	{
        if (_scope[_scopeNum - 1][j]->getName() == name)
            return _scope[_scopeNum - 1][j];
    }
    return NULL;
}

Variable* Dictionary::lookup(Variable* var)
{
    if (_scopeNum == 0)
        return NULL;
    for (int i = _scopeNum - 1; i >= 0; i --)
    {
        if (_varNum[i] == 0)
            continue;
        for (int j = 0; j < _varNum[i]; j ++)
        {
            if (_scope[i][j] == var)
                return _scope[i][j];
        }
    }
    return NULL;
}

Variable* Dictionary::lookupInScope(Variable* var)
{
    if (_scopeNum == 0)
        return NULL;
    if (_varNum[_scopeNum - 1] == 0)
        return NULL;
    for (int j = 0; j < _varNum[_scopeNum - 1]; j ++)
	{
        if (_scope[_scopeNum - 1][j] == var)
            return _scope[_scopeNum - 1][j];
    }
    return NULL;
}

void Dictionary::print()
{
    std::cout << "Dictionary: \n";
    for (int i = 0; i < _scopeNum; i ++)
    {
        std::cout << "\tScope level: " << i << std::endl;
        for (int j = 0; j < _varNum[i]; j ++)
        {
            std::cout << dataTypeToString(_scope[i][j]->getType()) << " " << _scope[i][j]->getName() << " " << _scope[i][j]->getVal() << std::endl;
        }
    }
}
