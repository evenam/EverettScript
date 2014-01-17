//
//  IdentifierNodes
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__IdentifierNodes__
#define __evaluate__IdentifierNodes__

#include <string>
#include "TreeNode.h"
#include "DataType.h"
#include "Dictionary.h"

class VariableIdentifierNode : public TreeNode
{
private:
    std::string _id;
public:
    VariableIdentifierNode(std::string identifier);
    ~VariableIdentifierNode();
    std::string getIdentifier();
    void print(int tabIndex);
    DataType getReturnType();
};

class DataTypeNode : public TreeNode
{
private:
    DataType _dt;
public:
    DataTypeNode(DataType data_type);
    ~DataTypeNode();
    DataType getDataType();
    void print(int tabIndex);
    DataType getReturnType();
};

#endif /* defined(__evaluate__IdentifierNodes__) */
