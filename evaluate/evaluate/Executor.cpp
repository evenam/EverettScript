//
//  Executor.cpp
//  evaluate
//
//  Created by Everett Moser on 1/3/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "Executor.h"

std::string executeBooleanNode(BooleanNode* node)
{
    return (node->getValue());
}

std::string executeStringNode(StringNode* node)
{
    return (node->getValue());
}

std::string executeNumberNode(NumberNode* node)
{
    return trimNumber(node->getValue());
}

std::string executeUnaryOperator(UnaryOpNode* node)
{
    std::string op = node->getOp();
    std::string val = evaluate(node->getExpression());
    if (op == "+")
    {
        return absoluteValue(getDataType(val), val);
    }
    else if (op == "-")
    {
        return negateValue(getDataType(val), val);
    }
    else if (op == "!")
    {
        return notValue(getDataType(val), val);
    }
    else
        unidentifiedData(op);
    return "";
}

std::string executeBinaryOperator(BinaryOpNode* node)
{
    std::string op = node->getOp();
    std::string lhs = evaluate(node->getLeftHandExpression());
    std::string rhs = evaluate(node->getRightHandExpression());
    if (op == "+")
    {
        return addOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "-")
    {
        return subOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "*")
    {
        return mulOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "/")
    {
        return divOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "%")
    {
        return modOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "^")
    {
        return expOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "&&")
    {
        return andOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "^^")
    {
        return xorOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "||")
    {
        return rorOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "<")
    {
        return lesOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == ">")
    {
        return greOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "<=")
    {
        return leqOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == ">=")
    {
        return geqOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "==")
    {
        return equOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "!=")
    {
        return neqOp(getDataType(lhs), lhs, getDataType(rhs), rhs);
    }
    else if (op == "=")
    {
        lhs = (dynamic_cast<VariableIdentifierNode*>(node->getLeftHandExpression()))->getIdentifier();
        return assOp(Dictionary::getRef()->getVar(lhs)->getType(), lhs, getDataType(rhs), rhs);
    }
    else if (op == "+=")
    {
        lhs = (dynamic_cast<VariableIdentifierNode*>(node->getLeftHandExpression()))->getIdentifier();
        return add_assOp(Dictionary::getRef()->getVar(lhs)->getType(), lhs, getDataType(rhs), rhs);
    }
    else if (op == "-=")
    {
        lhs = (dynamic_cast<VariableIdentifierNode*>(node->getLeftHandExpression()))->getIdentifier();
        return sub_assOp(Dictionary::getRef()->getVar(lhs)->getType(), lhs, getDataType(rhs), rhs);
    }
    else if (op == "*=")
    {
        lhs = (dynamic_cast<VariableIdentifierNode*>(node->getLeftHandExpression()))->getIdentifier();
        return mul_assOp(Dictionary::getRef()->getVar(lhs)->getType(), lhs, getDataType(rhs), rhs);
    }
    else if (op == "/=")
    {
        lhs = (dynamic_cast<VariableIdentifierNode*>(node->getLeftHandExpression()))->getIdentifier();
        return div_assOp(Dictionary::getRef()->getVar(lhs)->getType(), lhs, getDataType(rhs), rhs);
    }
    else if (op == "%=")
    {
        lhs = (dynamic_cast<VariableIdentifierNode*>(node->getLeftHandExpression()))->getIdentifier();
        return mod_assOp(Dictionary::getRef()->getVar(lhs)->getType(), lhs, getDataType(rhs), rhs);
    }
    else if (op == "^=")
    {
        lhs = (dynamic_cast<VariableIdentifierNode*>(node->getLeftHandExpression()))->getIdentifier();
        return exp_assOp(Dictionary::getRef()->getVar(lhs)->getType(), lhs, getDataType(rhs), rhs);
    }
    else
        unidentifiedData(op);
    return "";
}

std::string evaluate(TreeNode* node)
{
    if (checkObjectType<BinaryOpNode>(node))
        return executeBinaryOperator(dynamic_cast<BinaryOpNode*>(node));
    if (checkObjectType<UnaryOpNode>(node))
        return executeUnaryOperator(dynamic_cast<UnaryOpNode*>(node));
    if (checkObjectType<BooleanNode>(node))
        return executeBooleanNode(dynamic_cast<BooleanNode*>(node));
    if (checkObjectType<StringNode>(node))
        return executeStringNode(dynamic_cast<StringNode*>(node));
    if (checkObjectType<NumberNode>(node))
        return executeNumberNode(dynamic_cast<NumberNode*>(node));
    if (checkObjectType<ConditionalNode>(node))
        return executeConditionalNode(dynamic_cast<ConditionalNode*>(node));
    if (checkObjectType<DeclarationNode>(node))
        return executeDeclarationNode(dynamic_cast<DeclarationNode*>(node));
    if (checkObjectType<LoopNode>(node))
        return executeLoopNode(dynamic_cast<LoopNode*>(node));
    if (checkObjectType<StatementNode>(node))
        return executeStatementNode(dynamic_cast<StatementNode*>(node));
    if (checkObjectType<ReturnNode>(node))
        return executeReturnNode(dynamic_cast<ReturnNode*>(node));
    if (checkObjectType<FunctionCallNode>(node))
        return executeFunctionCallNode(dynamic_cast<FunctionCallNode*>(node));
    if (checkObjectType<VariableIdentifierNode>(node))
        return executeVariableIdentifierNode(dynamic_cast<VariableIdentifierNode*>(node));
    
    badMemorySegment();
    return "";
}

std::string executeConditionalNode(ConditionalNode* node)
{
    DataType edt = node->getExpression()->getReturnType();
    std::string exp_res, res;
    throwErrorIfNecessary(edt);
    if (edt == VT_BOOLEAN)
        exp_res = evaluate(node->getExpression());
    else if (edt == VT_NUMBER)
        exp_res = numToBool(evaluate(node->getExpression()));
    else if (edt == VT_STRING)
        exp_res = strToBool(evaluate(node->getExpression()));
    
    if (exp_res == "true" && node->getTrueClause() != NULL)
    {
        Dictionary::getRef()->increaseScope();
        res = evaluate(node->getTrueClause());
        Dictionary::getRef()->decreaseScope();
        if (res != "void")
            return res;
    }
    else if  (node->getFalseClause() != NULL)
    {
        
        Dictionary::getRef()->increaseScope();
        res = evaluate(node->getFalseClause());
        Dictionary::getRef()->decreaseScope();
        if (res != "void")
            return res;
    }
        
    return "void";
}

std::string executeDeclarationNode(DeclarationNode* node)
{
    if (node->getExpression() == NULL)
    {
        Dictionary::getRef()->addVar(dynamic_cast<VariableIdentifierNode*>(node->getIdentifier())->getIdentifier(), dynamic_cast<DataTypeNode*>(node->getDataType())->getDataType(), "");
        return dynamic_cast<VariableIdentifierNode*>(node->getIdentifier())->getIdentifier();
    }
    else
    {
        std::string ret = evaluate(node->getExpression());
        Dictionary::getRef()->addVar(dynamic_cast<VariableIdentifierNode*>(node->getIdentifier())->getIdentifier(), dynamic_cast<DataTypeNode*>(node->getDataType())->getDataType(), ret);
        return "void";
    }
}

std::string executeLoopNode(LoopNode* node)
{
    DataType edt = node->getExpression()->getReturnType();
    std::string exp_res, res;
    throwErrorIfNecessary(edt);
    if (edt == VT_BOOLEAN)
        exp_res = evaluate(node->getExpression());
    else if (edt == VT_NUMBER)
        exp_res = numToBool(evaluate(node->getExpression()));
    else if (edt == VT_STRING)
        exp_res = strToBool(evaluate(node->getExpression()));
    
    while (exp_res == "true")
    {
        Dictionary::getRef()->increaseScope();
        res = evaluate(node->getClause());
        Dictionary::getRef()->decreaseScope();
        
        if (res != "void")
            return res;
        
        
        if (edt == VT_BOOLEAN)
            exp_res = evaluate(node->getExpression());
        else if (edt == VT_NUMBER)
            exp_res = numToBool(evaluate(node->getExpression()));
        else if (edt == VT_STRING)
            exp_res = strToBool(evaluate(node->getExpression()));
        
    }
    return res;
}

std::string executeStatementNode(StatementNode* node)
{
    std::string ret;
    if (node->getCurrent() != NULL)
        ret = evaluate(node->getCurrent());
    if (ret != "void" && !checkExpressionNode(node->getCurrent()))
        return ret;
    if (node->getNext() == NULL)
        return "void";
    return evaluate(node->getNext());
}

std::string executeFunctionCallNode(FunctionCallNode* node)
{
    if (isBuiltin(node->getIdentifier()))
    {
        if (node->getIdentifier() == "print")
            return print(evaluate(node->getArguments().at(0)));
        if (node->getIdentifier() == "str_fmt")
            return "void";
        if (node->getIdentifier() == "bool_val")
            return bool_val(evaluate(node->getArguments().at(0)));
        if (node->getIdentifier() == "num_val")
            return num_val(evaluate(node->getArguments().at(0)));
        if (node->getIdentifier() == "str_val")
            return str_val(evaluate(node->getArguments().at(0)));
    }
    std::string ret;
    Dictionary::getRef()->increaseScope();
    for (int i = 0; i < node->getArguments().size(); i ++)
    {
        Function* f = Functionary::getRef()->getFunction(node->getIdentifier());
        Dictionary::getRef()->addVar(f->getArguments()[i]->getName(), f->getArguments()[i]->getType(), evaluate(node->getArguments()[i]));
    }
    //Dictionary::getRef()->print();
    //Functionary::getRef()->print();
    ret = evaluate(Functionary::getRef()->getFunction(node->getIdentifier())->getBody());
    Dictionary::getRef()->decreaseScope();
    return ret;
}

std::string executeReturnNode(ReturnNode* node)
{
    std::string x = evaluate(node->getExpression());
    return x;
}

std::string executeVariableIdentifierNode(VariableIdentifierNode* node)
{
    return Dictionary::getRef()->getVar(node->getIdentifier())->getVal();
}
