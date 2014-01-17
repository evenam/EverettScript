//
//  ValueNodes.h
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__ValueNodes__
#define __evaluate__ValueNodes__

#include <string>
#include "TreeNode.h"

class NumberNode : public TreeNode
{
private:
    std::string _val;
public:
    NumberNode(std::string number);
    ~NumberNode();
    std::string getValue();
    void print(int tabIndex);
    DataType getReturnType();
};

class StringNode : public TreeNode
{
private:
    std::string _val;
public:
    StringNode(std::string string);
    ~StringNode();
    std::string getValue();
    void print(int tabIndex);
    DataType getReturnType();
};

class BooleanNode : public TreeNode
{
private:
    std::string _val;
public:
    BooleanNode(std::string boolean);
    ~BooleanNode();
    std::string getValue();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__ValueNodes__) */
