//
//  LangMisc.cpp
//  evaluate
//
//  Created by Everett Moser on 12/18/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#include "LangMisc.h"
#include "Dictionary.h"

std::string dataTypeToString(DataType dt)
{
    if (dt == DT_NUMBER)
        return "num";
    if (dt == DT_STRING)
        return "str";
    if (dt == DT_BOOLEAN)
        return "bool";
    if (dt == DT_VOID)
        return "void";
    if (dt == DT_VAR_NUMBER)
        return "num";
    if (dt == DT_VAR_STRING)
        return "str";
    if (dt == DT_VAR_BOOLEAN)
        return "bool";
    
    return "undefined";
}

DataType stringToDataType(std::string dt)
{
    if (dt == "num")
        return DT_NUMBER;
    if (dt == "str")
        return DT_STRING;
    if (dt == "bool")
        return DT_BOOLEAN;
    if (dt == "void")
        return DT_VOID;
    
    return DT_UNDEFINED;
}

std::string toLangString(std::string cstr)
{
    std::string res = "\"";
    for (int i = 0; i < cstr.size(); i ++)
    {
        switch (cstr[i])
        {
            case '\a':
                res += "\\a";
                break;
            case '\b':
                res += "\\b";
                break;
            case '\f':
                res += "\\f";
                break;
            case '\n':
                res += "\\n";
                break;
            case '\r':
                res += "\\r";
                break;
            case '\t':
                res += "\\t";
                break;
            case '\v':
                res += "\\v";
                break;
            case '\'':
                res += "\\\'";
                break;
            case '\"':
                res += "\\\"";
                break;
            case '\\':
                res += "\\\\";
                break;
            default:
                res += cstr[i];
        }
    }
    res += "\"";
    return res;
}

std::string toCString(std::string langstr)
{
    std::string res = "";
    for (std::string::iterator i = langstr.begin() + 1; i != langstr.end() - 1; i++)
    {
        if ((*i) == '\\')
        {
            i ++;
            switch (*i)
            {
                case 'a':
                    res += "\a";
                    break;
                case 'b':
                    res += "\b";
                    break;
                case 'f':
                    res += "\f";
                    break;
                case 'n':
                    res += "\n";
                    break;
                case 'r':
                    res += "\r";
                    break;
                case 't':
                    res += "\t";
                    break;
                case 'v':
                    res += "\v";
                    break;
                case '\'':
                    res += "\'";
                    break;
                case '\"':
                    res += "\"";
                    break;
                case '\\':
                    res += "\\";
                    break;
                default:
                    impossibleEscapeSequence(*i);
            }
        }
        else
            res += (*i);
    }
    return res;
}

bool toBool(std::string val)
{
    if (val == "true")
        return true;
    else if (val == "false")
        return false;
    return true;
}

std::string fromBool(bool val)
{
    if (val)
        return "true";
    else
        return "false";
}

std::string trimNumber(std::string num)
{
    std::string ret = num;
    while (ret[0] == '0' && ret.size() > 1)
        ret = ret.substr(1);
    
    while (ret[ret.size() - 1] == '0' && ret.size() > 1 && ret.find('.') != std::string::npos)
        ret = ret.substr(0, ret.size() - 1);
    
    if (ret[ret.size() - 1] == '.')
        ret = ret.substr(0, ret.size() - 1);
        
    return ret;
}
