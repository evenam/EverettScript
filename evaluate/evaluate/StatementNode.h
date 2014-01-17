//
//  StatementNode.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__StatementNode__
#define __evaluate__StatementNode__

#include "TreeNode.h"


class StatementNode : public TreeNode
{
private:
    TreeNode *_current, *_next;
public:
    StatementNode(TreeNode* current, TreeNode* next);
    ~StatementNode();
    TreeNode* getCurrent();
    TreeNode* getNext();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__StatementNode__) */
