//
//  TokenStream.cpp
//  evaluate
//
//  Created by Everett Moser on 11/28/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#include "TokenStream.h"

/////////////////
// TokenStream //
/////////////////

// Constructors and Destructors

TokenStream::TokenStream()
{
    _exp.clear();
}

TokenStream::TokenStream(std::string exp)
{
    _exp.clear();
    std::string mex = exp, tkn;
    while (mex.size() > 0)
    {
        tkn = getToken(mex);
        _exp.push_back(tkn);
    }
}

TokenStream::TokenStream(const TokenStream& ts)
{
    _exp.clear();
    std::string mex = ts.exp(), tkn;
    while (mex.size() > 0)
    {
        tkn = getToken(mex);
        _exp.push_back(tkn);
    }
}

TokenStream::~TokenStream()
{
    _exp.clear();
}

// Utilities

std::string TokenStream::get()
{
    if (_exp.size() == 0)
        return "";
    std::string res = _exp[0];
    _exp.erase(_exp.begin());
    return res;
}

std::string TokenStream::peek()
{
    if (_exp.size() > 0)
        return _exp[0];
    else
        return "";
}

void TokenStream::add(std::string exp)
{
    std::string mex = exp, tkn;
    while (mex.size() > 0)
    {
        tkn = getToken(mex);
        _exp.push_back(tkn);
    }
}

void TokenStream::put(std::string exp)
{
    std::stack<std::string> tokens;
    std::string mex = exp, tkn;
    while (mex.size() > 0)
    {
        tkn = getToken(mex);
        tokens.push(tkn);
    }
    while (tokens.size() > 0)
    {
        _exp.insert(_exp.begin(), tokens.top());
        tokens.pop();
    }
}

void TokenStream::clear()
{
    _exp.clear();
}

bool TokenStream::empty()
{
    return (_exp.size() == 0);
}

std::string TokenStream::exp() const
{
    if (_exp.size() == 0)
        return "";
    std::string result = _exp[0];
    for (int i = 1; i < _exp.size(); i ++)
    {
        result += " ";
        result += _exp[i];
    }
    return result;
}

// privates

std::string TokenStream::getToken(std::string& exp)
{
    if (exp.size() <= 0)
        return "";
    
    if (nextTokenType(exp) == TT_NUMBER)
        return getNumber(exp);
    else if (nextTokenType(exp) == TT_IDENTIFIER)
        return getIdentifier(exp);
    else if (nextTokenType(exp) == TT_STRING)
        return getString(exp);
    else if (nextTokenType(exp) == TT_WHITESPACE)
    {
        getWhitespace(exp);
        return getToken(exp);
    }
    else if (nextTokenType(exp) == TT_LANGSYM)
        return getLangSym(exp);
    else if (nextTokenType(exp) == TT_OPERATOR)
        return getOperator(exp);
    else
        return "";
}

// operator overloads

TokenStream& operator >> (TokenStream& ts, std::string& out)
{
    out = ts.get();
    return ts;
}

TokenStream& operator << (TokenStream& ts, std::string in)
{
    ts.add(in);
    return ts;
}

