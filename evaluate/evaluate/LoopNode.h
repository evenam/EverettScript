//
//  LoopNode.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__LoopNode__
#define __evaluate__LoopNode__

#include "TreeNode.h"

class LoopNode : public TreeNode
{
private:
    TreeNode* _exp;
    TreeNode* _clause;
public:
    LoopNode(TreeNode* exp, TreeNode* clause);
    ~LoopNode();
    TreeNode* getExpression();
    TreeNode* getClause();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__LoopNode__) */
