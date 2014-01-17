//
//  Functions.h
//  evaluate
//
//  Created by Everett Moser on 1/4/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Functions__
#define __evaluate__Functions__

#include <string>
#include <vector>
#include "DataType.h"
#include "LangMisc.h"
#include <iostream>
#include "Tokenizer.h"

bool isBuiltin(std::string name);
DataType getBuiltinDataType(std::string name);

std::string print(std::string data);
std::string str_fmt(std::string fmt, std::vector<std::string> args);
std::string bool_val(std::string data);
std::string num_val(std::string data);
std::string str_val(std::string data);

#endif /* defined(__evaluate__Functions__) */
