//
//  Function.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Function__
#define __evaluate__Function__

#include "TreeNode.h"
#include "Variable.h"
#include <vector>

class Function
{
private:
    std::string _id;
    DataType _return;
    Variable* _args[64];
    TreeNode* _body;
	int _argsSize;
public:
	Function(std::string identifier, DataType returnType, std::vector<Variable*> args, TreeNode* body);
    ~Function();
    
    DataType getReturnType();
    std::string getIdentifier();
    Variable** getArguments();
    TreeNode* getBody();
	int getNumArgs();
};

#endif /* defined(__evaluate__Function__) */
