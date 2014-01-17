//
//  LangMisc.h
//  evaluate
//
//  Created by Everett Moser on 12/18/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#ifndef __evaluate__LangMisc__
#define __evaluate__LangMisc__

#include "Errors.h"
#include "DataType.h"
#include <sstream>

std::string dataTypeToString(DataType dt);
DataType stringToDataType(std::string dt);

std::string toLangString(std::string cstr);
std::string toCString(std::string langstr);

bool toBool(std::string val);
std::string fromBool(bool val);

std::string numToString(std::string num);
std::string stringToNum(std::string str);
std::string boolToNum(std::string boo);
std::string numToBool(std::string num);
std::string boolToString(std::string boo);
std::string strToBool(std::string str);

std::string trimNumber(std::string num);

#endif /* defined(__evaluate__LangMisc__) */
