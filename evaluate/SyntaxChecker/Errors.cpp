//
//  Errors.cpp
//  evaluate
//
//  Created by Everett Moser on 11/30/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#include "Errors.h"

void improperProgramUsage()
{
	std::cout << "ERROR: IMPROPER PROGRAM USAGE\nUSAGE escript <program_name>" << std::endl;
	exit(-1);
}

void unexpectedType(std::string expected, std::string got)
{
    std::cout << "Expected " << expected << ". Got " << got << std::endl;
    exit(-1);
}

void stringParseError(std::string dataType)
{
    std::cout << "Could not parse " << dataType << " from string. " << std::endl;
    exit(-1);
}


void unrecognizedToken(std::string rem)
{
    std::cout << "Could not recognize token -->" << rem << std::endl;
    exit(-1);
}

void impossibleEscapeSequence(char chr)
{
    std::cout << "No esape sequence \\" << chr << " is defined." << std::endl;
    exit(-1);
}

void unidentifiedData(std::string data)
{
    std::cout << "Unidentified data " << data << std::endl;
    exit(-1);
}

void badMemorySegment()
{
    std::cout << "Encountered some bad memory." << std::endl;
    exit(-1);
}

void divisionBy0()
{
    std::cout << "Encountered division by 0." << std::endl;
    exit(-1);
}

void undefinedData()
{
    std::cout << "Resulting data is either void or undefined." << std::endl;
    exit(-1);
}
