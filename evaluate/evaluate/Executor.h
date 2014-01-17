//
//  Executor.h
//  evaluate
//
//  Created by Everett Moser on 1/3/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Executor__
#define __evaluate__Executor__

#include "Nodes.h"
#include "LangMisc.h"
#include "Functionary.h"
#include "Dictionary.h"
#include "Functions.h"
#include "Operators.h"

std::string executeBooleanNode(BooleanNode* node);
std::string executeNumberNode(NumberNode* node);
std::string executeStringNode(StringNode* node);

std::string executeUnaryOperator(UnaryOpNode* node);
std::string executeBinaryOperator(BinaryOpNode* node);

std::string executeConditionalNode(ConditionalNode* node);
std::string executeDeclarationNode(DeclarationNode* node);
std::string executeLoopNode(LoopNode* node);
std::string executeStatementNode(StatementNode* node);
std::string executeFunctionCallNode(FunctionCallNode* node);
std::string executeReturnNode(ReturnNode* node);
std::string executeVariableIdentifierNode(VariableIdentifierNode* node);

std::string evaluate(TreeNode* node);

inline bool checkExpressionNode(TreeNode* obj)
{
    if (checkObjectType<BinaryOpNode>(obj))
        return true;
    if (checkObjectType<UnaryOpNode>(obj))
        return true;
    if (checkObjectType<BooleanNode>(obj))
        return true;
    if (checkObjectType<NumberNode>(obj))
        return true;
    if (checkObjectType<StringNode>(obj))
        return true;
    if (checkObjectType<FunctionCallNode>(obj))
        return true;
    return false;
}

//std::string evaluate(TreeNode* node);

#endif /* defined(__evaluate__Executor__) */
