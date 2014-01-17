//
//  ConditionalNode.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__ConditionalNode__
#define __evaluate__ConditionalNode__

#include "TreeNode.h"

class ConditionalNode : public TreeNode
{
private:
    TreeNode* _exp;
    TreeNode* _true;
    TreeNode* _false;
public:
    ConditionalNode(TreeNode* exp, TreeNode* true_, TreeNode* false_);
    ~ConditionalNode();
    TreeNode* getExpression();
    TreeNode* getTrueClause();
    TreeNode* getFalseClause();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__ConditionalNode__) */
