//
//  Parser.h
//  evaluate
//
//  Created by Everett Moser on 1/2/14.
//  Copyright (c) 2014 Everett Moser. All rights reserved.
//

#ifndef __evaluate__Parser__
#define __evaluate__Parser__

#include "TokenStream.h"
#include "Nodes.h"
#include "LangMisc.h"
#include "Functionary.h"
#include "Dictionary.h"

// thank you ronald mak, no need for postfix --> stack --> tree, I can do it all from here :P
// and here comes the stack (lol biting some words...)

void parseProgram(TokenStream& ts);

bool nextIsFunction(TokenStream& ts);
bool nextIsVariable(TokenStream& ts);

Function* parseFunction(TokenStream& ts);
Variable* parseVariable(TokenStream& ts);

TreeNode* parseStatement(TokenStream& ts);
TreeNode* parseCodeBlock(TokenStream& ts);

TreeNode* parseDeclaration(TokenStream& ts);
TreeNode* parseLoop(TokenStream& ts);
TreeNode* parseConditional(TokenStream& ts);
TreeNode* parseExpression(TokenStream& ts);
TreeNode* parseReturn(TokenStream& ts);

TreeNode* parseExpression(TokenStream& ts);
TreeNode* parseAssignments(TokenStream& ts);
TreeNode* parseBooleanOps(TokenStream& ts);
TreeNode* parseRelations(TokenStream& ts);
TreeNode* parseSummation(TokenStream& ts);
TreeNode* parseTerm(TokenStream& ts);
TreeNode* parseFactor(TokenStream& ts);
TreeNode* parseExponent(TokenStream& ts);
TreeNode* parseThingy(TokenStream& ts);

std::vector<TreeNode*> parseArgumentList(TokenStream& ts);

#endif /* defined(__evaluate__Parser__) */
