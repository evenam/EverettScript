//
//  TokenStream.h
//  evaluate
//
//  Created by Everett Moser on 11/28/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Lexer__
#define __evaluate__Lexer__

#include <string>
#include <stack>
#include <vector>
#include "Errors.h"
#include "Tokenizer.h"

class TokenStream
{
private:
    std::vector<std::string> _exp;
    std::string getToken(std::string &exp);
    
public:
    TokenStream();
    TokenStream(std::string exp);
    TokenStream(const TokenStream& ts);
    ~TokenStream();
    
    std::string get();
    std::string peek();
    
    void add(std::string exp);
    void put(std::string exp);
    
    void clear();
    bool empty();
    int size();
    std::string exp() const;
};

TokenStream& operator >> (TokenStream& ts, std::string& out);
TokenStream& operator << (TokenStream& ts, std::string in);

#endif /* defined(__evaluate__Lexer__) */
