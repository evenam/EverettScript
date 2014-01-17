//
//  DeclarationNode.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__DeclarationNode__
#define __evaluate__DeclarationNode__

#include "TreeNode.h"

class DeclarationNode : public TreeNode
{
private:
    TreeNode* _dt;
    TreeNode* _id;
    TreeNode* _exp;
public:
    DeclarationNode(TreeNode* data_type, TreeNode* identifier, TreeNode* expression);
    ~DeclarationNode();
    TreeNode* getDataType();
    TreeNode* getIdentifier();
    TreeNode* getExpression();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__DeclarationNode__) */
