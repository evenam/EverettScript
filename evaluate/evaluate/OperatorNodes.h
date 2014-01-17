//
//  OperatorNodes.h
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__OperatorNodes__
#define __evaluate__OperatorNodes__

#include <string>
#include "TreeNode.h"

class BinaryOpNode : public TreeNode
{
private:
    std::string _op;
    TreeNode *_lhs, *_rhs;
public:
    BinaryOpNode(std::string op, TreeNode* lhs, TreeNode* rhs);
    ~BinaryOpNode();
    std::string getOp();
    TreeNode* getLeftHandExpression();
    TreeNode* getRightHandExpression();
    void print(int tabIndex);
    DataType getReturnType();
};

class UnaryOpNode : public TreeNode
{
private:
    std::string _op;
    TreeNode* _operand;
public:
    UnaryOpNode(std::string op, TreeNode* expression);
    ~UnaryOpNode();
    std::string getOp();
    TreeNode* getExpression();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__OperatorNodes__) */
