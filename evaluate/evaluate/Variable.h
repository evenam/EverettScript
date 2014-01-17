//
//  Variable.h
//  Variables
//
//  Created by Everett Moser on 12/31/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#ifndef __Variables__Variable__
#define __Variables__Variable__

#include <string>
#include "DataType.h"
class Variable
{
private:
    std::string _val;
    DataType _type;
    std::string _name;
public:
    Variable(DataType type, std::string name);
    Variable(DataType type, std::string name, std::string val);
    ~Variable();
    
    std::string getVal();
    std::string getName();
    void setVal(std::string new_val);
    DataType getType();
};

#endif /* defined(__Variables__Variable__) */
