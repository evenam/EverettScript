//
//  TreeNode.h
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef evaluate_TreeNode_h
#define evaluate_TreeNode_h

#include <typeinfo>
#include <string>
#include <iostream>
#include "DataType.h"

class TreeNode
{
public:
    virtual ~TreeNode() {};
    virtual DataType getReturnType() { return VT_UNDEFINED; };
    virtual void print(int tabIndex) {};
};

template <class type>
inline bool checkObjectType(TreeNode* obj)
{
    // std::cout << (typeid(*obj)).name() << (typeid(type)).name() << std::endl;
    if (obj == NULL)
        return false;
    return ((typeid(*obj)) == (typeid(type)));
}

#endif
