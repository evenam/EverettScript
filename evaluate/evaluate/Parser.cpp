//
//  Parser.cpp
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "Parser.h"

void parseProgram(TokenStream& ts)
{
    while (!ts.empty())
    {
        if (nextIsFunction(ts))
        {
            Functionary::getRef()->addFunction(parseFunction(ts));
        }
        else if (nextIsVariable(ts))
        {
            Dictionary::getRef()->addVar(parseVariable(ts));
        }
        else
        {
            // fuck everything else
            while (!nextIsFunction(ts) && !nextIsVariable(ts) && !ts.empty())
            {
                std::string g;
                ts >> g;
            }
        }
    }
}

bool nextIsFunction(TokenStream& ts)
{
    std::string dt, id;
    bool ret;
    ts >> dt >> id;
    ret = (ts.peek() == "(");
    ts.put(id);
    ts.put(dt);
    return ret;
}

bool nextIsVariable(TokenStream& ts)
{
    std::string dt, id;
    bool ret;
    ts >> dt >> id;
    ret = (ts.peek() == ";");
    ts.put(id);
    ts.put(dt);
    return ret;
}

Variable* parseVariable(TokenStream& ts)
{
    DataType dt;
    std::string id, g;
    dt = stringToDataType(ts.peek());
    
    ts >> g;
    ts >> id;
    ts >> g;
        
    return new Variable(dt, id);
}

Function* parseFunction(TokenStream& ts)
{
    std::string type, ident, vid, vtype, trash;
    std::vector<Variable*> args;
    DataType dt, vt;
    ts >> type;
    dt = stringToDataType(type);
    ts >> ident;
    ts >> trash; // (
    while (trash != ")" && ts.peek() != ")")
    {
        ts >> vtype >> vid >> trash;
        vt = stringToDataType(vtype);
        args.push_back(new Variable(vt, vid));
    }
    if (ts.peek() == ")")
        ts >> trash;

    return new Function(ident, dt, args, parseStatement(ts));
}

TreeNode* parseStatement(TokenStream& ts)
{
    if (ts.peek() == "num" || ts.peek() == "str" || ts.peek() == "bool")
        return new StatementNode(parseDeclaration(ts), NULL);
    else if (ts.peek() == "while")
        return new StatementNode(parseLoop(ts), NULL);
    else if (ts.peek() == "if")
        return new StatementNode(parseConditional(ts), NULL);
    else if (ts.peek() == "return")
        return new StatementNode(parseReturn(ts), NULL);
    else if (ts.peek() == "{")
    {
        std::string garbage;
        ts >> garbage;
        return parseCodeBlock(ts);
    }
    else
    {
        TreeNode* ret = new StatementNode(parseExpression(ts), NULL);
        std::string garbage;
        ts >> garbage;
        return ret;
    }
}

TreeNode* parseCodeBlock(TokenStream& ts)
{
    if (ts.peek() == "}")
    {
        std::string garbage;
        ts >> garbage;
        return NULL;
    }
    
    return new StatementNode(parseStatement(ts), parseCodeBlock(ts));
}

TreeNode* parseDeclaration(TokenStream& ts)
{
    DataType dt;
    std::string id, g;
    DeclarationNode* ret;
    dt = stringToDataType(ts.peek());
    
    ts >> g;
    ts >> id;
    ts >> g;
    if (g == "=")
    {
        ret = new DeclarationNode(new DataTypeNode(dt), new VariableIdentifierNode(id), parseExpression(ts));
        ts >> g;
    }
    else
        ret = new DeclarationNode(new DataTypeNode(dt), new VariableIdentifierNode(id), NULL);
    
    return ret;
}

TreeNode* parseLoop(TokenStream& ts)
{
    TreeNode *exp, *body;
    std::string garbage;
    ts >> garbage; //while
    ts >> garbage; //(
    exp = parseExpression(ts);
    ts >> garbage; //)
    body = parseStatement(ts);
    return new LoopNode(exp, body);
}

TreeNode* parseConditional(TokenStream& ts)
{
    TreeNode *exp, *body_true, *body_false = NULL;
    std::string garbage;
    ts >> garbage; //if
    ts >> garbage; //(
    exp = parseExpression(ts);
    ts >> garbage; //)
    body_true = parseStatement(ts);
    if (ts.peek() == "else")
    {
        ts >> garbage;
        body_false = parseStatement(ts);
    }
    
    return new ConditionalNode(exp, body_true, body_false);
}

// Parsing Expressions

TreeNode* parseExpression(TokenStream& ts)
{
    return parseAssignments(ts);
}

TreeNode* parseAssignments(TokenStream& ts)
{
    TreeNode* ass = parseRelations(ts);
    if (ass == NULL)
        return NULL;
    
    std::string op;
    BinaryOpNode* binOpNode;
    TreeNode* nextAss;
    while (ts.peek() == "=" || ts.peek() == "+=" || ts.peek() == "-=" || ts.peek() == "*=" ||
           ts.peek() == "/="  || ts.peek() == "&=" || ts.peek() == "^=")
    {
        ts >> op;
        nextAss = parseRelations(ts);
        binOpNode = new BinaryOpNode(op, ass, nextAss);
        ass = binOpNode;
    }
    return ass;
}

TreeNode* parseBooleanOps(TokenStream& ts)
{
    TreeNode* bop = parseRelations(ts);
    if (bop == NULL)
        return NULL;
    
    std::string op;
    BinaryOpNode* binOpNode;
    TreeNode* nextBop;
    while (ts.peek() == "&&" || ts.peek() == "||" || ts.peek() == "^^")
    {
        ts >> op;
        nextBop = parseRelations(ts);
        binOpNode = new BinaryOpNode(op, bop, nextBop);
        bop = binOpNode;
    }
    return bop;
}

TreeNode* parseRelations(TokenStream& ts)
{
    TreeNode* rel = parseSummation(ts);
    if (rel == NULL)
        return NULL;
    
    std::string op;
    BinaryOpNode* binOpNode;
    TreeNode* nextRel;
    while (ts.peek() == "<=" || ts.peek() == ">=" || ts.peek() == "==" ||
           ts.peek() == ">"  || ts.peek() == "<"  || ts.peek() == "!=")
    {
        ts >> op;
        nextRel = parseSummation(ts);
        binOpNode = new BinaryOpNode(op, rel, nextRel);
        rel = binOpNode;
    }
    return rel;
}

TreeNode* parseSummation(TokenStream& ts)
{
    TreeNode* sum, *binOpNode, *nextSum;
    std::string op;
    sum = parseTerm(ts);
    if (sum == NULL)
        return NULL;
    
    while (ts.peek() == "+" || ts.peek() == "-")
    {
        ts >> op;
        nextSum = parseTerm(ts);
        binOpNode = new BinaryOpNode(op, sum, nextSum);
        sum = binOpNode;
    }
    return sum;
}

TreeNode* parseTerm(TokenStream& ts)
{
    TreeNode* term = parseFactor(ts);
    if (term == NULL)
        return NULL;
    
    std::string op;
    BinaryOpNode* binOpNode;
    TreeNode* nextTerm;
    while (ts.peek() == "/" || ts.peek() == "*" || ts.peek() == "%")
    {
        ts >> op;
        nextTerm = parseFactor(ts);
        binOpNode = new BinaryOpNode(op, term, nextTerm);
        term = binOpNode;
    }
    return term;
}

TreeNode* parseFactor(TokenStream& ts)
{
    TreeNode* exponent = parseExponent(ts);
    if (exponent == NULL)
        return NULL;
    
    std::string op;
    BinaryOpNode* binOpNode;
    TreeNode* next;
    while (ts.peek() == "^")
    {
        ts >> op;
        next = parseExponent(ts);
        binOpNode = new BinaryOpNode("^", exponent, next);
        exponent = binOpNode;
    }
    return exponent;
}

TreeNode* parseExponent(TokenStream& ts)
{
    if (ts.peek() == "+" || ts.peek() == "-" || ts.peek() == "!")
    {
        std::string op;
        ts >> op;
        return new UnaryOpNode(op, parseExponent(ts));
    }
    else
    {
        return parseThingy(ts);
    }
}

TreeNode* parseThingy(TokenStream& ts)
{
    TreeNode* sub;
    if (getTokenType(ts.peek()) == TT_IDENTIFIER)
    {
        std::string id;
        ts >> id;
        if (ts.peek() == "(")
            sub = (new FunctionCallNode(id, parseArgumentList(ts)));
        else
            sub = (new VariableIdentifierNode(id));
    }
    else if (getTokenType(ts.peek()) == TT_NUMBER)
    {
        std::string num;
        ts >> num;
        sub = (new NumberNode(num));
    }
    else if (getTokenType(ts.peek()) == TT_STRING)
    {
        std::string str;
        ts >> str;
        sub = (new StringNode(str));
    }
    else if (getTokenType(ts.peek()) == TT_STRING)
    {
        std::string boo;
        ts >> boo;
        sub = (new BooleanNode(boo));
    }
    else if (getTokenType(ts.peek()) == TT_BOOLEAN)
    {
        std::string str;
        ts >> str;
        sub = (new StringNode(str));
    }
    else if (ts.peek() == "(")
    {
        std::string garbage;
        ts >> garbage;
        sub = parseExpression(ts);
        ts >> garbage;
    }
    else
        sub = NULL;
    return sub;
}

std::vector<TreeNode*> parseArgumentList(TokenStream& ts)
{
    std::vector<TreeNode*> ret;
    std::string garbage;
    ts >> garbage;
    while (garbage != ")")
    {
        ret.push_back(parseExpression(ts));
        ts >> garbage;
    }
    return ret;
}

TreeNode* parseReturn(TokenStream& ts)
{
    TreeNode* exp;
    std::string g;
    ts >> g; // return
    exp = parseExpression(ts);
    ts >> g; // ;
    return new ReturnNode(exp);
}
