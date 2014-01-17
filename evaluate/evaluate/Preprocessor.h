//
//  Preprocessor.h
//  evaluate
//
//  Created by Everett Moser on 1/4/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Preprocessor__
#define __evaluate__Preprocessor__

#include <string>
#include <fstream>
#include <vector>
#include "TokenStream.h"

// removes comments, makes defines, imports additional files

class Preprocessor
{
private:
    std::vector<std::string> _incs;
    std::string _mainfile;
    bool _contains(std::string fname);
    void _removeComments(std::string& program);
public:
    Preprocessor(std::string mainfile);
    ~Preprocessor();
    
    void process(TokenStream& ts);
};

#endif /* defined(__evaluate__Preprocessor__) */
