//
//  Nodes.h
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef evaluate_Nodes_h
#define evaluate_Nodes_h

#include <iostream>
#include <string>
#include <vector>

#include "Dictionary.h"
#include "Functionary.h"
#include "Functions.h"
#include "TreeNode.h"

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

#endif
