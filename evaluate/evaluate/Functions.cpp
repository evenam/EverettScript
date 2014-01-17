//
//  Functions.cpp
//  evaluate
//
//  Created by Everett Moser on 1/4/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "Functions.h"

bool isBuiltin(std::string name)
{
    if (name == "print")
        return true;
    if (name == "str_fmt")
        return true;
    if (name == "bool_val")
        return true;
    if (name == "str_val")
        return true;
    if (name == "num_val")
        return true;
    
    return false;
}

DataType getBuiltinDataType(std::string name)
{
    if (name == "print")
        return VT_VOID;
    if (name == "str_fmt")
        return VT_STRING;
    if (name == "bool_val")
        return VT_BOOLEAN;
    if (name == "str_val")
        return VT_STRING;
    if (name == "num_val")
        return VT_NUMBER;
    
    return VT_UNDEFINED;
}

std::string print(std::string data)
{
    if (nextTokenType(data) == TT_STRING)
        std::cout << toCString(data);
    else
        std::cout << data;
    
    return "void";
}

std::string str_fmt(std::string fmt, std::vector<std::string> args)
{
    return "";
}

std::string bool_val(std::string data)
{
    if (nextTokenType(data) == TT_STRING)
        return strToBool(data);
    else if (nextTokenType(data) == TT_NUMBER)
        return numToBool(data);
    else if (nextTokenType(data) == TT_BOOLEAN)
        return data;
    return "false";
}

std::string num_val(std::string data)
{
    if (nextTokenType(data) == TT_STRING)
        return stringToNum(data);
    else if (nextTokenType(data) == TT_NUMBER)
        return (data);
    else if (nextTokenType(data) == TT_BOOLEAN)
        return boolToNum(data);
    return "0";
}

std::string str_val(std::string data)
{
    if (nextTokenType(data) == TT_STRING)
        return data;
    else if (nextTokenType(data) == TT_NUMBER)
        return numToString(data);
    else if (nextTokenType(data) == TT_BOOLEAN)
        return boolToString(data);
    return "";
}
