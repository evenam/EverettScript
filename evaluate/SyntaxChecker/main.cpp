#include <iostream>
#include <fstream>
#include "TokenStream.h"

void printProgram(TokenStream& ts, int indent = 0);
void printExpression(TokenStream& ts);

int main(int argc, char** argv)
{
	std::ifstream infile;
    infile.open("sample.es");
    
    TokenStream ts;
    std::string program, token;
    while (!infile.eof())
    {
        infile >> token;
        program += token;
        program += " ";
    }
	infile.close();
	ts << program;

	
	std::cin.get();
}
void printProgram(TokenStream& ts)
{
	std::string g;
	int indent = 0;
	int extraIndent = 0;
	while (!ts.empty())
	{
		if (extraIndent > 0)
		if (ts.peek() == "{";
		{
			for (int i = -1; ++i < indent; std::cout << "  ");
			std::cout << "{\n";
			indent ++;
			ts >> g;
		}
		else if (ts.peek() == "}")
		{
			for (int i = 0; ++i < indent; std::cout << "  ");
			std::cout << "}\n";
			indent --;
			ts >> g;
		}
		else if (ts.peek() == "if" || ts.peek() == "while")
		{
			ts >> g >> g;
			std::cout << "if (";
			printExpression(ts);
			std::cout << ")\n";
			ts >> g; 
			if (ts.peek() != "{")
			{
				extraIndent += 2;
				indent += 2;
			}
		}
	}
}

void printExpression(TokenStream& ts, char delim)
{
	int depth = 0;
	std::string tkn;
	bool needSpace = false;
	while (depth > 0 || ts.peek() != ";" || ts.peek() != ")")
	{
		ts >> tkn;
		if (tkn == ")") 
		{
			depth --;
			std::cout << ")";
			needSpace = true;
		}
		else if (tkn == "(")
		{
			depth ++;
			std::cout " (";
			needSpace = false;
		}
		else
		{
			std::cout << (needSpace?" ":"") << tkn;
			needSpace = true;
		}
	}
}
