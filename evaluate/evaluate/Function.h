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
    std::vector<Variable*> _args;
    TreeNode* _body;
public:
    Function(std::string identifier, DataType returnType, std::vector<Variable*> args, TreeNode* body);
    ~Function();
    
    DataType getReturnType();
    std::string getIdentifier();
    std::vector<Variable*> getArguments();
    TreeNode* getBody();
};

#endif /* defined(__evaluate__Function__) */
