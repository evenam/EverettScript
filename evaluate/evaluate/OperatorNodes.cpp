//
//  OperatorNodes.cpp
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "OperatorNodes.h"

UnaryOpNode::UnaryOpNode(std::string op, TreeNode* expression)
{
    _op = op;
    _operand = expression;
}

UnaryOpNode::~UnaryOpNode()
{
    _op = "";
    delete _operand;
}

std::string UnaryOpNode::getOp()
{
    return _op;
}

TreeNode* UnaryOpNode::getExpression()
{
    return _operand;
}

void UnaryOpNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Unary Op: " << _op << std::endl;
    _operand->print(tabIndex + 1);
}

DataType UnaryOpNode::getReturnType()
{
    if (_op == "+" || _op == "_")
    {
        if (_operand->getReturnType() == VT_NUMBER)
            return VT_NUMBER;
        else
            return VT_UNDEFINED;
    }
    else if (_op == "!")
    {
        if (_operand->getReturnType() != VT_STRING)
            return VT_BOOLEAN;
        else
            return VT_UNDEFINED;
    }
    else
        return VT_UNDEFINED;
}

BinaryOpNode::BinaryOpNode(std::string op, TreeNode* lhs, TreeNode* rhs)
{
    _op = op;
    _lhs = lhs;
    _rhs = rhs;
}

BinaryOpNode::~BinaryOpNode()
{
    _op = "";
    delete _lhs;
    delete _rhs;
}

std::string BinaryOpNode::getOp()
{
    return _op;
}

TreeNode* BinaryOpNode::getLeftHandExpression()
{
    return _lhs;
}

TreeNode* BinaryOpNode::getRightHandExpression()
{
    return _rhs;
}

void BinaryOpNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Binary Op: " << _op << std::endl;
    if (_lhs != NULL)
        _lhs->print(tabIndex + 1);
    if (_rhs != NULL)
        _rhs->print(tabIndex + 1);
}

DataType BinaryOpNode::getReturnType()
{
    DataType lhs = _lhs->getReturnType(), rhs = _rhs->getReturnType();
    if (lhs == VT_UNDEFINED || lhs == VT_VOID || rhs == VT_UNDEFINED || rhs == VT_VOID)
        return VT_UNDEFINED;
    if (_op == "+")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_NUMBER;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_STRING;
            }
            else if (rhs == VT_STRING)
            {
                return VT_STRING;
            }
            else
            {
                return VT_STRING;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_NUMBER;
            }
        }
    }
    else if (_op == "-")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_NUMBER;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_UNDEFINED;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_NUMBER;
            }
        }
    }
    else if (_op == "*")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_NUMBER;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_UNDEFINED;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_BOOLEAN;
            }
        }
    }
    else if (_op == "%")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_UNDEFINED;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
    }
    else if (_op == "/")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_UNDEFINED;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
    }
    else if (_op == "^")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_NUMBER;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_STRING;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_STRING;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_BOOLEAN;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_BOOLEAN;
            }
        }
    }
    else if (_op == "=" || _op == "+=" || _op == "*=" || _op == "/=" || _op == "&=" || _op == "^=")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_NUMBER;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_NUMBER;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_STRING)
            {
                return VT_STRING;
            }
            else if (rhs == VT_STRING)
            {
                return VT_STRING;
            }
            else
            {
                return VT_STRING;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_BOOLEAN;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_BOOLEAN;
            }
        }
    }
    else if (_op == "^^" || _op == "||" || _op == "&&")
    {
        if (lhs == VT_NUMBER)
        {
            if (rhs == VT_NUMBER)
            {
                return VT_BOOLEAN;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_BOOLEAN;
            }
        }
        else if (lhs == VT_STRING)
        {
            if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == VT_NUMBER)
            {
                return VT_BOOLEAN;
            }
            else if (rhs == VT_STRING)
            {
                return VT_UNDEFINED;
            }
            else
            {
                return VT_BOOLEAN;
            }
        }
    }
    else if (_op == ">" || _op == "<" || _op == "==" || _op == "!=" || _op == ">=" || _op == "<=")
    {
        return VT_BOOLEAN;
    }
    else
        return VT_UNDEFINED;
}
