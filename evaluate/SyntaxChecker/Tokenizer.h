//
//  Tokenizer.h
//  evaluate
//
//  Created by Everett Moser on 1/1/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Tokenizer__
#define __evaluate__Tokenizer__

#include <string>
#include "Errors.h"
#include "DataType.h"
#include "LangMisc.h"

enum TokenType
{
    TT_NUMBER,
    TT_STRING,
    TT_BOOLEAN,
    TT_KEYWORD,
    TT_IDENTIFIER,
    TT_OPERATOR,
    TT_LANGSYM,
    TT_WHITESPACE,
    TT_UNDEFINED
};

TokenType getTokenType(std::string tkn);

bool isChar(char c);
bool isNum(char c);
bool isOpSym(char c);
bool isLangSym(char c);
bool iswhiteSp(char c);

std::string getIdentifier(std::string &exp);
std::string getNumber(std::string &exp);
std::string getWhitespace(std::string &exp);
std::string getString(std::string &exp);
std::string getOperator(std::string &exp);
std::string getLangSym(std::string &exp);
TokenType nextTokenType(std::string exp);

std::string numToString(std::string num);
std::string stringToNum(std::string str);
std::string boolToNum(std::string boo);
std::string numToBool(std::string num);
std::string boolToString(std::string boo);
std::string strToBool(std::string str);

DataType getDataType(std::string data);

#endif /* defined(__evaluate__Tokenizer__) */
