//
//  Operators.cpp
//  evaluate
//
//  Created by Everett Moser on 1/4/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#include "Operators.h"

std::string absoluteValue(DataType dval, std::string val)
{
    throwErrorIfNecessary(dval);
    if (dval != VT_NUMBER)
        unexpectedType("num", dataTypeToString(dval));
    
    std::stringstream ret;
    ret.setf(std::ios::fixed);
    float _val = atof(val.c_str());
    if (_val < 0)
        _val *= -1;
    ret << _val;
    return trimNumber(ret.str());
}

std::string negateValue(DataType dval, std::string val)
{
    throwErrorIfNecessary(dval);
    if (dval != VT_NUMBER)
        unexpectedType("num", dataTypeToString(dval));
    
    std::stringstream ret;
    ret.setf(std::ios::fixed);
    float _val = atof(val.c_str());
    _val *= -1;
    ret << _val;
    return trimNumber(ret.str());
}

std::string notValue(DataType dval, std::string val)
{
    throwErrorIfNecessary(dval);
    if (dval != VT_NUMBER && dval != VT_BOOLEAN)
        unexpectedType("num or bool", dataTypeToString(dval));
    
    if (dval == VT_BOOLEAN)
    {
        if (val == "true")
            return "false";
        if (val == "false")
            return "true";
    }
    
    if (atof(val.c_str()) != 0)
        return "true";
    return "false";
}

std::string addOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (lhd == VT_STRING && (rhd == VT_STRING || VT_BOOLEAN || VT_NUMBER))
    {
        std::string ret;
        ret = toCString(lhs);
        ret += (rhd == VT_STRING)?toCString(rhs):rhs;
        return toLangString(ret);
    }
    else if (lhd == VT_NUMBER && rhd == VT_NUMBER)
    {
        std::stringstream res;
        res.setf(std::ios::fixed);
        float left = atof(lhs.c_str()), right  = atof(rhs.c_str());
        res << (left + right);
        return trimNumber(res.str());
    }
    else if (lhd == VT_NUMBER && rhd == VT_BOOLEAN)
    {
        std::stringstream res;
        res.setf(std::ios::fixed);
        float left = atof(lhs.c_str()), right  = (toBool(rhs)?1:0);
        res << (left + right);
        return trimNumber(res.str());
    }
    else if (lhd == VT_BOOLEAN && rhd == VT_NUMBER)
    {
        std::stringstream res;
        res.setf(std::ios::fixed);
        float left = (toBool(lhs)?1:0), right  = atof(rhs.c_str());
        res << (left + right);
        return trimNumber(res.str());
    }
    else if (lhd == VT_BOOLEAN && rhd == VT_BOOLEAN)
    {
        std::stringstream res;
        res.setf(std::ios::fixed);
        float left = (toBool(lhs)?1:0), right  = (toBool(rhs)?1:0);
        res << (left + right);
        return trimNumber(res.str());
    }
    else
        unexpectedType("str", dataTypeToString(rhd));
    return "";
}

std::string subOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (!((lhd == VT_NUMBER || lhd == VT_BOOLEAN) && (rhd == VT_NUMBER || rhd == VT_BOOLEAN)))
        unexpectedType("num or bool", "string");
    
    float l, r;
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    if (lhd == VT_BOOLEAN)
        l = atof(boolToNum(lhs).c_str());
    else
        l = atof(lhs.c_str());
    
    if (rhd == VT_BOOLEAN)
        r = atof(boolToNum(rhs).c_str());
    else
        r = atof(rhs.c_str());
    
    ss << (l - r);
    return trimNumber(ss.str());
}

std::string mulOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (!(lhd == VT_NUMBER || lhd == VT_BOOLEAN) && !(rhd == VT_NUMBER || rhd == VT_BOOLEAN))
        unexpectedType("num or bool", "string");
    
    float l, r;
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    if (lhd == VT_BOOLEAN)
        l = atof(boolToNum(lhs).c_str());
    else
        l = atof(lhs.c_str());
    
    if (rhd == VT_BOOLEAN)
        r = atof(boolToNum(rhs).c_str());
    else
        r = atof(rhs.c_str());
    
    ss << (l * r);
    if (lhd == VT_BOOLEAN && rhd == VT_BOOLEAN)
        return numToBool(ss.str());
    return trimNumber(ss.str());
}

std::string divOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (!(lhd == VT_NUMBER || lhd == VT_BOOLEAN) && rhd != VT_NUMBER)
        unexpectedType("num or bool", "string");
    
    float l, r;
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    if (lhd == VT_BOOLEAN)
        l = atof(boolToNum(lhs).c_str());
    else
        l = atof(lhs.c_str());
    
    if (rhd == VT_BOOLEAN)
        r = atof(boolToNum(rhs).c_str());
    else
        r = atof(rhs.c_str());
    
    if (r == 0)
        divisionBy0();
    
    ss << (l / r);
    return trimNumber(ss.str());
}

std::string modOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (!(lhd == VT_NUMBER || lhd == VT_BOOLEAN) && rhd != VT_NUMBER)
        unexpectedType("num or bool", "string");
    
    float l, r;
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    if (lhd == VT_BOOLEAN)
        l = atof(boolToNum(lhs).c_str());
    else
        l = atof(lhs.c_str());
    
    if (rhd == VT_BOOLEAN)
        r = atof(boolToNum(rhs).c_str());
    else
        r = atof(rhs.c_str());
    
    if (r == 0)
        divisionBy0();
    
    ss << ((int)l % (int)r);
    return trimNumber(ss.str());
}

std::string expOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (!(rhd == VT_NUMBER || rhd == VT_BOOLEAN))
        unexpectedType("num or bool", dataTypeToString(rhd));
    if (lhd == VT_STRING && (rhd == VT_NUMBER || rhd == VT_BOOLEAN))
    {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        int lim;
        if (rhd == VT_BOOLEAN)
            lim = atof(boolToNum(rhs).c_str());
        else
            lim = atof(rhs.c_str());
        for (int i = 0; i < lim; i ++)
        {
            ss << toCString(lhs);
        }
        return toLangString(ss.str());
    }
    
    float l, r;
    std::stringstream ss;
    ss.setf(std::ios::fixed);
    if (lhd == VT_BOOLEAN)
        l = atof(boolToNum(lhs).c_str());
    else
        l = atof(lhs.c_str());
    
    if (rhd == VT_BOOLEAN)
        r = atof(boolToNum(rhs).c_str());
    else
        r = atof(rhs.c_str());
    
    ss << (pow(l, r));
    if (lhd == VT_BOOLEAN && rhd == VT_BOOLEAN)
        return numToBool(ss.str());
    return trimNumber(ss.str());
}

std::string greOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (lhd == VT_STRING)
    {
        return ((lhs > rhs)?"true":"false");
    }
    else if (lhd == VT_NUMBER)
    {
        if (rhd == VT_STRING)
        {
            return ((atof(lhs.c_str()) > atof(stringToNum(rhs).c_str()))?"true":"false");
        }
        else if (rhd == VT_NUMBER)
        {
            return ((atof(lhs.c_str()) > atof(rhs.c_str()))?"true":"false");
        }
        else if (rhd == VT_BOOLEAN)
        {
            return ((atof(lhs.c_str()) > atof(boolToNum(rhs).c_str()))?"true":"false");
        }
    }
    else if (lhd == VT_BOOLEAN)
    {
        if (rhd == VT_STRING)
        {
            return ((lhs == "true" && strToBool(rhs) == "false")?"true":"false");
        }
        else if (rhd == VT_NUMBER)
        {
            return ((lhs == "true" && numToBool(rhs) == "false")?"true":"false");
        }
        else if (rhd == VT_BOOLEAN)
        {
            return ((lhs == "true" && rhs == "false")?"true":"false");
        }
    }
    unexpectedType("something", "something else @therealtechn9ne");
    return "";
}

std::string lesOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (lhd == VT_STRING)
    {
        return ((lhs < rhs)?"true":"false");
    }
    else if (lhd == VT_NUMBER)
    {
        if (rhd == VT_STRING)
        {
            return ((atof(lhs.c_str()) < atof(stringToNum(rhs).c_str()))?"true":"false");
        }
        else if (rhd == VT_NUMBER)
        {
            return ((atof(lhs.c_str()) < atof(rhs.c_str()))?"true":"false");
        }
        else if (rhd == VT_BOOLEAN)
        {
            return ((atof(lhs.c_str()) < atof(boolToNum(rhs).c_str()))?"true":"false");
        }
    }
    else if (lhd == VT_BOOLEAN)
    {
        if (rhd == VT_STRING)
        {
            return ((lhs == "false" && strToBool(rhs) == "false")?"true":"false");
        }
        else if (rhd == VT_NUMBER)
        {
            return ((lhs == "false" && numToBool(rhs) == "true")?"true":"false");
        }
        else if (rhd == VT_BOOLEAN)
        {
            return ((lhs == "false" && rhs == "true")?"true":"false");
        }
    }
    unexpectedType("something", "something else @therealtechn9ne");
    return "";
}

std::string equOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (lhd == VT_STRING)
    {
        return ((lhs == rhs)?"true":"false");
    }
    else if (lhd == VT_NUMBER)
    {
        if (rhd == VT_STRING)
        {
            return ((atof(lhs.c_str()) == atof(stringToNum(rhs).c_str()))?"true":"false");
        }
        else if (rhd == VT_NUMBER)
        {
            return ((atof(lhs.c_str()) == atof(rhs.c_str()))?"true":"false");
        }
        else if (rhd == VT_BOOLEAN)
        {
            return ((atof(lhs.c_str()) == atof(boolToNum(rhs).c_str()))?"true":"false");
        }
    }
    else if (lhd == VT_BOOLEAN)
    {
        if (rhd == VT_STRING)
        {
            return ((lhs == strToBool(rhs))?"true":"false");
        }
        else if (rhd == VT_NUMBER)
        {
            return ((lhs == numToBool(rhs))?"true":"false");
        }
        else if (rhd == VT_BOOLEAN)
        {
            return ((lhs == rhs)?"true":"false");
        }
    }
    unexpectedType("something", "something else @therealtechn9ne");
    return "";
}

std::string geqOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string ret1, ret2;
    ret1 = equOp(lhd, lhs, rhd, rhs);
    ret2 = greOp(lhd, lhs, rhd, rhs);
    
    if (ret1 == "true" || ret2 == "true")
        return "true";
    else if (ret1 == "false" && ret2 == "false")
        return "false";
    
    unexpectedType("something", "something else @therealtechn9ne");
    return "";
}

std::string leqOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string ret1, ret2;
    ret1 = equOp(lhd, lhs, rhd, rhs);
    ret2 = lesOp(lhd, lhs, rhd, rhs);
    
    if (ret1 == "true" || ret2 == "true")
        return "true";
    else if (ret1 == "false" && ret2 == "false")
        return "false";
    unexpectedType("something", "something else @therealtechn9ne");
    return "";
}

std::string neqOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    return notValue(VT_BOOLEAN, equOp(lhd, lhs, rhd, rhs));
}

std::string andOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string s1, s2;
    if (lhd == VT_NUMBER)
    {
        s1 = numToBool(lhs);
    }
    else if (lhd == VT_STRING)
    {
        s1 = strToBool(lhs);
    }
    else
    {
        s1 = lhs;
    }
    
    if (rhd == VT_NUMBER)
    {
        s2 = numToBool(rhs);
    }
    else if (rhd == VT_STRING)
    {
        s2 = strToBool(rhs);
    }
    else
    {
        s2 = rhs;
    }
    
    if (s1 == "true" && s2 == "true")
        return "true";
    return "false";
}

std::string rorOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string s1, s2;
    if (lhd == VT_NUMBER)
    {
        s1 = numToBool(lhs);
    }
    else if (lhd == VT_STRING)
    {
        s1 = strToBool(lhs);
    }
    else
    {
        s1 = lhs;
    }
    
    if (rhd == VT_NUMBER)
    {
        s2 = numToBool(rhs);
    }
    else if (rhd == VT_STRING)
    {
        s2 = strToBool(rhs);
    }
    else
    {
        s2 = rhs;
    }
    
    if (s1 == "true" || s2 == "true")
        return "true";
    return "false";
}

std::string xorOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string s1, s2;
    if (lhd == VT_NUMBER)
    {
        s1 = numToBool(lhs);
    }
    else if (lhd == VT_STRING)
    {
        s1 = strToBool(lhs);
    }
    else
    {
        s1 = lhs;
    }
    
    if (rhd == VT_NUMBER)
    {
        s2 = numToBool(rhs);
    }
    else if (rhd == VT_STRING)
    {
        s2 = strToBool(rhs);
    }
    else
    {
        s2 = rhs;
    }
    
    if (s1 == "false" && s2 == "true")
        return "true";
    if (s1 == "true" && s2 == "false")
        return "true";
    return "false";
}


std::string assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    if (lhd == rhd)
    {
        Dictionary::getRef()->getVar(lhs)->setVal(rhs);
        return rhs;
    }
    
    if (lhd == VT_NUMBER)
    {
        if (rhd == VT_STRING)
        {
            Dictionary::getRef()->setVarVal(lhs, trimNumber(stringToNum(rhs)));
        }
        else if (rhd == VT_BOOLEAN)
        {
            Dictionary::getRef()->setVarVal(lhs, trimNumber(boolToNum(rhs)));
        }
    }
    else if (lhd == VT_BOOLEAN)
    {
        if (rhd == VT_STRING)
        {
            Dictionary::getRef()->setVarVal(lhs, strToBool(rhs));
        }
        else if (rhd == VT_NUMBER)
        {
            Dictionary::getRef()->setVarVal(lhs, numToBool(rhs));
        }
    }
    else if (lhd == VT_STRING)
    {
        if (rhd == VT_NUMBER)
        {
            Dictionary::getRef()->setVarVal(lhs, numToString(rhs));
        }
        else if (rhd == VT_BOOLEAN)
        {
            Dictionary::getRef()->setVarVal(lhs, boolToString(rhs));
        }
    }
    unexpectedType("not void or undefined", dataTypeToString(lhd));
    return "";
}

std::string add_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string res1 = addOp(lhd, Dictionary::getRef()->getVar(lhs)->getVal(), rhd, rhs);
    TokenType tt = getTokenType(res1);
    if (tt == TT_NUMBER)
        return assOp(lhd, lhs, VT_NUMBER, res1);
    else if (tt == TT_BOOLEAN)
        return assOp(lhd, lhs, VT_BOOLEAN, res1);
    else if (tt == TT_STRING)
        return assOp(lhd, lhs, VT_STRING, res1);
    
    unexpectedType("num or str or bool", "void or undefined");
    return "";
}

std::string sub_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string res1 = subOp(lhd, Dictionary::getRef()->getVar(lhs)->getVal(), rhd, rhs);
    TokenType tt = getTokenType(res1);
    if (tt == TT_NUMBER)
        return assOp(lhd, lhs, VT_NUMBER, res1);
    else if (tt == TT_BOOLEAN)
        return assOp(lhd, lhs, VT_BOOLEAN, res1);
    else if (tt == TT_STRING)
        return assOp(lhd, lhs, VT_STRING, res1);
    
    unexpectedType("num or str or bool", "void or undefined");
    return "";
}

std::string mul_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string res1 = mulOp(lhd, Dictionary::getRef()->getVar(lhs)->getVal(), rhd, rhs);
    TokenType tt = getTokenType(res1);
    if (tt == TT_NUMBER)
        return assOp(lhd, lhs, VT_NUMBER, res1);
    else if (tt == TT_BOOLEAN)
        return assOp(lhd, lhs, VT_BOOLEAN, res1);
    else if (tt == TT_STRING)
        return assOp(lhd, lhs, VT_STRING, res1);
    
    unexpectedType("num or str or bool", "void or undefined");
    return "";
}

std::string div_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string res1 = divOp(lhd, Dictionary::getRef()->getVar(lhs)->getVal(), rhd, rhs);
    TokenType tt = getTokenType(res1);
    if (tt == TT_NUMBER)
        return assOp(lhd, lhs, VT_NUMBER, res1);
    else if (tt == TT_BOOLEAN)
        return assOp(lhd, lhs, VT_BOOLEAN, res1);
    else if (tt == TT_STRING)
        return assOp(lhd, lhs, VT_STRING, res1);
    
    unexpectedType("num or str or bool", "void or undefined");
    return "";
}

std::string mod_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string res1 = modOp(lhd, Dictionary::getRef()->getVar(lhs)->getVal(), rhd, rhs);
    TokenType tt = getTokenType(res1);
    if (tt == TT_NUMBER)
        return assOp(lhd, lhs, VT_NUMBER, res1);
    else if (tt == TT_BOOLEAN)
        return assOp(lhd, lhs, VT_BOOLEAN, res1);
    else if (tt == TT_STRING)
        return assOp(lhd, lhs, VT_STRING, res1);
    
    unexpectedType("num or str or bool", "void or undefined");
    return "";
}

std::string exp_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs)
{
    throwErrorIfNecessary(lhd);
    throwErrorIfNecessary(rhd);
    std::string res1 = expOp(lhd, Dictionary::getRef()->getVar(lhs)->getVal(), rhd, rhs);
    TokenType tt = getTokenType(res1);
    if (tt == TT_NUMBER)
        return assOp(lhd, lhs, VT_NUMBER, res1);
    else if (tt == TT_BOOLEAN)
        return assOp(lhd, lhs, VT_BOOLEAN, res1);
    else if (tt == TT_STRING)
        return assOp(lhd, lhs, VT_STRING, res1);
    
    unexpectedType("num or str or bool", "void or undefined");
    return "";
}

void throwErrorIfNecessary(DataType d1)
{
    if (d1 == VT_VOID || d1 == VT_UNDEFINED)
        undefinedData();
}
