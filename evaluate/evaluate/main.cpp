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
	if (argc != 2)
		improperProgramUsage();
    std::ifstream infile;
    infile.open(argv[1]);
    std::string program, token;
    while (!infile.eof())
    {
        infile >> token;
        program += token;
        program += " ";
    }
    
    TokenStream ts;
    ts << program;
    
    Dictionary* d = Dictionary::getRef();
    Functionary* f = Functionary::getRef();
    
    parseProgram(ts);

	//Dictionary::getRef()->print();
	//Functionary::getRef()->print();
    
    std::string ret = evaluate(Functionary::getRef()->getFunction("main")->getBody());
    
    std::cout << std::endl << "program exited returning " << ret << std::endl;
	Dictionary::deleteRef();
	Functionary::deleteRef();

	system("PAUSE>nul");
    
    return 0;
};

