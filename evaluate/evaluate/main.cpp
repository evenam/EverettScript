//
//  main.cpp
//  evaluate
//
//  Created by Everett Moser on 11/19/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#include <fstream>
#include "Parser.h"
#include "Executor.h"

int main(int argc, const char * argv[])
{
    std::ifstream infile;
    infile.open("/Users/everettmoser/Documents/devel/evaluate/evaluate/sample.es");
     std::string program, token;
    while (!infile.eof())
    {
        infile >> token;
        program += token;
        program += " ";
    }
    
    //std::cout << "program (regular):\n" << program << std::endl << std::endl;

    //std::getline(std::cin, program);
    
    TokenStream ts;
    ts << program;
    Dictionary* d = Dictionary::getRef();
    Functionary* f = Functionary::getRef();
    
    parseProgram(ts);
    //Functionary::getRef()->print();
    
    std::string ret = evaluate(Functionary::getRef()->getFunction("main")->getBody());
    
    std::cout << std::endl << "program exited returning " << ret << std::endl;
    delete d;
    delete f;
    
    return 0;
};

