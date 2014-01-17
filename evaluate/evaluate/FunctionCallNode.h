//
//  FunctionCallNode.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__FunctionCallNode__
#define __evaluate__FunctionCallNode__

#include "TreeNode.h"
#include <vector>
#include "Functionary.h"
#include "Functions.h"

class FunctionCallNode : public TreeNode
{
private:
    std::string _id;
    std::vector<TreeNode*> _args;
public:
    FunctionCallNode(std::string identifier, std::vector<TreeNode*> args);
    ~FunctionCallNode();
    std::string getIdentifier();
    std::vector<TreeNode*> getArguments();
    void print(int tabIndex);
    DataType getReturnType();
};

class ReturnNode : public TreeNode
{
private:
    TreeNode* _exp;
public:
    ReturnNode(TreeNode* exp);
    ~ReturnNode();
    TreeNode* getExpression();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__FunctionCallNode__) */
