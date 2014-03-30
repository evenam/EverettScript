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
    if (name == "get_line")
        return true;
    if (name == "scan")
        return true;
    if (name == "getc")
        return true;
    
    return false;
}

DataType getBuiltinDataType(std::string name)
{
    if (name == "print")
        return DT_VOID;
    if (name == "str_fmt")
        return DT_STRING;
    if (name == "bool_val")
        return DT_BOOLEAN;
    if (name == "str_val")
        return DT_STRING;
    if (name == "num_val")
        return DT_NUMBER;
    if (name == "get_line")
        return DT_STRING;
    if (name == "scan")
        return DT_STRING;
    if (name == "getc")
        return DT_STRING;
    
    return DT_UNDEFINED;
}

std::string builtIn(std::string name, std::vector<std::string> args)
{
    if (name == "print")
        return print(args[0]);
    if (name == "str_fmt")
    {
        std::string fmt = args[0];
        args.erase(args.begin());
        return str_fmt(fmt, args);
    }
    if (name == "bool_val")
        return bool_val(args[0]);
    if (name == "num_val")
        return num_val(args[0]);
    if (name == "str_val")
        return str_val(args[0]);
    if (name == "scan")
        return scan();
    if (name == "get_line")
        return get_line();
    if (name == "getc")
        return getc();
    return "void";
}

std::string print(std::string data)
{
    if (nextTokenType(data) == TT_STRING)
        std::cout << toCString(data);
    else
        std::cout << data;
    
    return "void";
}

std::string str_fmt(std::string fmt /* lang_str */, std::vector<std::string> args)
{
    std::string res = "";
    int j = 0;
    for (std::string::iterator i = fmt.begin(); i != fmt.end(); i++)
    {
        if ((*i) == '\\')
        {
            i ++;
            if ((*i) == '@')
            {
                if (getTokenType(args[j]) == TT_STRING)
                    args[j] = toCString(args[j]);
                res += args[j++];
            }
            else
            {
                res += "\\";
                res += (* i);
            }
        }
        else
            res += (*i);
    }
    return res;
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

std::string scan()
{
    std::string tkn;
    std::cin >> tkn;
    return tkn;
}

std::string get_line()
{
    std::string ret;
    std::getline(std::cin, ret);
    return ret;
}

std::string getc()
{
    std::string ret;
    ret += (char)getchar();
    return ret;
}
