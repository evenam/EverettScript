//
//  Errors.h
//  evaluate
//
//  Created by Everett Moser on 11/30/13.
//  Copyright (c) 2013 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Errors__
#define __evaluate__Errors__

#include <iostream>
#include <string>

// Keep adding more specific error codes and such

void improperProgramUsage();
void unexpectedType(std::string expected, std::string got);
void stringParseError(std::string dataType);
void unrecognizedToken(std::string rem);
void impossibleEscapeSequence(char chr);
void unidentifiedData(std::string data);
void badMemorySegment();
void divisionBy0();
void undefinedData();

#endif /* defined(__evaluate__Errors__) */
