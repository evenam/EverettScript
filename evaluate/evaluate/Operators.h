//
//  Operators.h
//  evaluate
//
//  Created by Everett Moser on 1/4/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Operators__
#define __evaluate__Operators__

#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include "Functionary.h"
#include "Dictionary.h"
#include "Tokenizer.h"
#include "Errors.h"
#include "LangMisc.h"

std::string absoluteValue(DataType dval, std::string val);
std::string negateValue(DataType dval, std::string val);
std::string notValue(DataType dval, std::string val);

std::string addOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string subOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string mulOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string divOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string modOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string expOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string greOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string lesOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string equOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string geqOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string leqOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string neqOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string andOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string rorOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string xorOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);

std::string assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string add_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string sub_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string mul_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string div_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string mod_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);
std::string exp_assOp(DataType lhd, std::string lhs, DataType rhd, std::string rhs);

void throwErrorIfNecessary(DataType d1);

#endif /* defined(__evaluate__Operators__) */
