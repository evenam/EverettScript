//
//  Dictionary.h
//  Variables
//
//  Created by Everett Moser on 12/31/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#ifndef __Variables__Dictionary__
#define __Variables__Dictionary__

#include <vector>
#include <string>
#include <iostream>
#include "LangMisc.h"
#include "Variable.h"
#include "Singleton.h"

class Dictionary : public Singleton<Dictionary>
{
private:
    std::vector<std::vector<Variable *> *> _scope;
    Variable* lookup(std::string name);
    Variable* lookupInScope(std::string name);
    Variable* lookup(Variable* var);
    Variable* lookupInScope(Variable* var);
public:
    Dictionary();
    ~Dictionary();
    
    void increaseScope();
    void decreaseScope();
    int scope();
    
    void addVar(Variable* var);
    void addVar(std::string name, DataType type, std::string val);
    Variable* getVar(std::string name);
    void setVar(std::string name, Variable* new_var);
    void deleteVar(Variable* var);
    void deleteVar(std::string name);
    
    bool varExists(std::string name);
    bool varExists(Variable* var);
    bool varExistsInScope(std::string name);
    bool varExistsInScope(Variable* var);
    DataType getVarType(std::string name);
    
    void setVarVal(std::string name, std::string value);
    std::string getVarVal(std::string name);
    
    void print();
};

#endif /* defined(__Variables__Dictionary__) */
