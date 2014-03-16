//
//  Functionary.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Functionary__
#define __evaluate__Functionary__

#include "Function.h"
#include "Singleton.h"
#include "LangMisc.h"
#include <vector> 

class Functionary : public Singleton<Functionary>
{
private:
    Function* _functions[1024];
	int _numFunc;
    Function* lookup(std::string name);
    Function* lookup(Function* func);
public:
    Functionary();
    ~Functionary();
    
    void addFunction(Function* func);
	void addFunction(std::string name, DataType returnType, std::vector<Variable*> args, TreeNode* body);
    Function* getFunction(std::string name);
    void setFunction(std::string name, Function* new_func);
    void deleteFunction(Function* func);
    void deleteFunction(std::string name);
    
    bool functionExists(std::string name);
    bool functionExists(Function* func);
    DataType getFunctionReturnType(std::string name);
    
    void print();
};

#endif /* defined(__evaluate__Functionary__) */
