//
//  Tokenizer.cpp
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "Tokenizer.h"

TokenType getTokenType(std::string tkn)
{
    TokenType t = nextTokenType(tkn);
    if (t != TT_IDENTIFIER)
        return t;
    
    if (tkn == "true" || tkn == "false")
        return TT_BOOLEAN;
    if (tkn == "if"    ||
        tkn == "else"  ||
        tkn == "while" ||
        tkn == "for"   ||
        tkn == "void"  ||
        tkn == "null"  ||
        tkn == "num"   ||
        tkn == "str"   ||
        tkn == "bool"  ||
        tkn == "const")
        return TT_KEYWORD;
    
    return TT_IDENTIFIER;
}

bool isChar(char c)
{
    return ((c <= 'Z' && c >= 'A') || (c >= 'a' && c <= 'z'));
}

bool isNum(char c)
{
    return (c >= '0' && c <= '9');
}

bool isOpSym(char c)
{
    switch (c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
        case '=':
        case '!':
        case '<':
        case '>':
            return true;
        default:
            return false;
    }
}

bool isLangSym(char c)
{
    switch (c)
    {
        case '{':
        case '}':
        case '(':
        case ')':
        case ';':
        case '.':
        case ',':
            return true;
        default:
            return false;
    }
}

bool iswhiteSp(char c)
{
    return ((c == ' ') || (c == '\t'));
}

TokenType nextTokenType(std::string exp)
{
    if (exp.size() == 0)
        return TT_UNDEFINED;
    if (exp[0] == '&')
        return TT_OPERATOR;
    if (exp[0] == '|')
        return TT_OPERATOR;
    if (iswhiteSp(exp[0]))
        return TT_WHITESPACE;
    if (isChar(exp[0]) || exp[0] == '_')
        return TT_IDENTIFIER;
    if (isNum(exp[0]))
        return TT_NUMBER;
    if (exp[0] == '\"')
        return TT_STRING;
    
    if (exp.size() == 1)
    {
        if (isLangSym(exp[0]))
            return TT_LANGSYM;
        if (isOpSym(exp[0]))
            return TT_OPERATOR;
    }
    else
    {
        if (exp[0] == '.' && isNum(exp[1]))
            return TT_NUMBER;
        else if (isLangSym(exp[0]))
            return TT_LANGSYM;
        else if (isOpSym(exp[0]))
            return TT_OPERATOR;
    }
    
    return TT_UNDEFINED;
}

std::string getNumber(std::string &exp)
{
    if (exp.size() == 0)
        return "";
    
    bool hasDot = false;
    std::string token = "";
    if (!isNum(exp[0]) && exp[0] != '.')
        return "";
    
    token += exp[0];
    if (token == ".")
        hasDot = true;
    int i = 1;
    bool done = false;
    while (!done)
    {
        if (i >= exp.size())
            done = true;
        else if (exp[i] == '.' && hasDot)
        {
            done = true;
        }
        else if (exp[i] == '.')
        {
            token += ".";
            hasDot = true;
        }
        else if (!isNum(exp[i]))
        {
            done = true;
        }
        else
        {
            token += exp[i];
        }
        i ++;
    }
    
    if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '.'))
        return "";
    
    if (token[token.size() - 1] == '.')
        token = token.substr(0, token.size() - 1);
    
    exp.erase(0, token.size());
    
    return token;
}

std::string getString(std::string &exp)
{
    std::string token = "";
    bool done = false;
    int i = 1;
    bool esc = false;
    if (exp.size() == 0)
        return "";
    
    if (exp[0] != '\"')
        return "";
    
    token += "\"";
    while (!done)
    {
        if (i >= exp.size())
            break;
        else if (exp[i] == '\\' && !esc)
        {
            esc = true;
            token += '\\';
        }
        else if (exp[i] == '\"' && !esc)
        {
            token += '\"';
            done = true;
        }
        else
        {
            token += exp[i];
            esc = false;
        }
        
        i ++;
    }
    
    if (!done)
        return "";
    else
    {
        exp.erase(0, token.size());
        return token;
    }
}

std::string getWhitespace(std::string &exp)
{
    std::string token = "";
    for (int i = 0; i < exp.size();)
    {
        if (iswhiteSp(exp[0]))
        {
            token += exp[0];
            exp.erase(0,1);
        }
        else
            return token;
    }
    return token;
}

std::string getIdentifier(std::string &exp)
{
    std::string token = "";
    if (exp.size() == 0)
        return token;
    
    bool done = false;
    
    for (int i = 0; !done; i ++)
    {
        if (i == 0)
        {
            if (exp[i] == '_' || isChar(exp[i]))
                token += exp[i];
            else
                done = true;
        }
        else
        {
            if (exp[i] == '_' || isChar(exp[i]) || isNum(exp[i]))
                token += exp[i];
            else
                done = true;
        }
        
        if (i >= exp.size())
            done = true;
    }
    
    exp.erase(0, token.size());
    
    return token;
}


std::string getOperator(std::string &exp)
{
    if (exp.size() == 0)
        return "";
    
    if (exp.size() >= 2)
    {
        if (exp[0] == '&' && exp[1] == '&')
        {
            exp.erase(0, 2);
            return "&&";
        }
        if (exp[0] == '|' && exp[1] == '|')
        {
            exp.erase(0, 2);
            return "||";
        }
    }
    
    if (exp.size() == 1 && isOpSym(exp[0]))
    {
        std::string s;
        s += exp[0];
        exp.erase(0, 1);
        return s;
    }
    if (exp[1] == '=' && isOpSym(exp[0]))
    {
        
        std::string s;
        s += exp[0];
        s += "=";
        exp.erase(0, 2);
        return s;
    }
    if (isOpSym(exp[0]))
    {
        std::string s;
        s += exp[0];
        exp.erase(0, 1);
        return s;
    }
    
    return "";
}

std::string getLangSym(std::string &exp)
{
    if (exp.size() == 0)
        return "";
    if (isLangSym(exp[0]))
    {
        std::string s;
        s += exp[0];
        exp.erase(0, 1);
        return s;
    }
    else
        return "";
}

std::string numToString(std::string num)
{
    std::string ret = "\"";
    ret += num;
    ret += "\"";
    return ret;
}

std::string stringToNum(std::string str)
{
    if (nextTokenType(toCString(str)) != TT_NUMBER)
        stringParseError("num");
    std::string ret = toCString(str);
    return getNumber(ret);
}

std::string boolToNum(std::string boo)
{
    if (boo == "false")
        return "0";
    return "1";
}

std::string numToBool(std::string num)
{
    if (atof(num.c_str()) == 0)
        return "false";
    return "true";
}

std::string boolToString(std::string boo)
{
    std::string ret = "\"";
    ret += boo;
    ret += "\"";
    return ret;
}

std::string strToBool(std::string str)
{
    std::string getT, getF;
    getT = toCString(str).substr(0, 4);
    getF = toCString(str).substr(0, 5);
    
    if (getT != "true" || getF != "false")
        stringParseError("bool");
    
    if (getT == "true")
        return getT;
    return getF;
}

DataType getDataType(std::string data)
{
    TokenType tt = getTokenType(data);
    if (tt == TT_NUMBER)
        return DT_NUMBER;
    if (tt == TT_STRING)
        return DT_STRING;
    if (tt == TT_BOOLEAN)
        return DT_BOOLEAN;
    unidentifiedData(data);
    return DT_UNDEFINED;
}
