#include "Nodes.h"

NumberNode::NumberNode(std::string number)
{
    _val = number;
}

NumberNode::~NumberNode()
{
    _val = "";
}

std::string NumberNode::getValue()
{
    return _val;
}

void NumberNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Number Value: " << _val << std::endl;
}

DataType NumberNode::getReturnType()
{
    return DT_NUMBER;
}

StringNode::StringNode(std::string string)
{
    _val = string;
}

StringNode::~StringNode()
{
    _val = "";
}

std::string StringNode::getValue()
{
    return _val;
}

void StringNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "String Value: " << _val << std::endl;
}

DataType StringNode::getReturnType()
{
    return DT_STRING;
}

BooleanNode::BooleanNode(std::string boolean)
{
    _val = boolean;
}

BooleanNode::~BooleanNode()
{
    _val = "";
}

std::string BooleanNode::getValue()
{
  return _val;
}

void BooleanNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Boolean Value: " << _val << std::endl;
}

DataType BooleanNode::getReturnType()
{
    return DT_BOOLEAN;
}

StatementNode::StatementNode(TreeNode* current, TreeNode* next)
{
    _current = current;
    _next = next;
}

StatementNode::~StatementNode()
{
    delete _next;
    delete _current;
}

TreeNode* StatementNode::getCurrent()
{
    return _current;
}

TreeNode* StatementNode::getNext()
{
    return _next;
}

void StatementNode::print(int tabIndex)
{
    if (_current != NULL)
    {
        for (int i = 0; i < tabIndex; i ++)
            std::cout << "\t";
        std::cout << "Statement:" << std::endl;
        _current->print(tabIndex + 1);
    }
    if (_next != NULL)
    {
        _next->print(tabIndex);
    }
}

DataType StatementNode::getReturnType()
{
    if (_current != NULL) _current->getReturnType();
    return DT_VOID;
}

UnaryOpNode::UnaryOpNode(std::string op, TreeNode* expression)
{
    _op = op;
    _operand = expression;
}

UnaryOpNode::~UnaryOpNode()
{
    _op = "";
    delete _operand;
}

std::string UnaryOpNode::getOp()
{
    return _op;
}

TreeNode* UnaryOpNode::getExpression()
{
    return _operand;
}

void UnaryOpNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Unary Op: " << _op << std::endl;
    _operand->print(tabIndex + 1);
}

DataType UnaryOpNode::getReturnType()
{
    if (_op == "+" || _op == "-")
    {
        if (_operand->getReturnType() == DT_NUMBER || _operand->getReturnType() == DT_VAR_NUMBER)
            return DT_NUMBER;
        else
            return DT_UNDEFINED;
    }
    else if (_op == "!")
    {
        if (_operand->getReturnType() != DT_STRING || _operand->getReturnType() != DT_VAR_STRING)
            return DT_BOOLEAN;
        else
            return DT_UNDEFINED;
    }
    else
        return DT_UNDEFINED;
}

BinaryOpNode::BinaryOpNode(std::string op, TreeNode* lhs, TreeNode* rhs)
{
    _op = op;
    _lhs = lhs;
    _rhs = rhs;
}

BinaryOpNode::~BinaryOpNode()
{
    _op = "";
    delete _lhs;
    delete _rhs;
}

std::string BinaryOpNode::getOp()
{
    return _op;
}

TreeNode* BinaryOpNode::getLeftHandExpression()
{
    return _lhs;
}

TreeNode* BinaryOpNode::getRightHandExpression()
{
    return _rhs;
}

void BinaryOpNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Binary Op: " << _op << std::endl;
    if (_lhs != NULL)
        _lhs->print(tabIndex + 1);
    if (_rhs != NULL)
        _rhs->print(tabIndex + 1);
}

DataType BinaryOpNode::getReturnType()
{
    DataType lhs = _lhs->getReturnType(), rhs = _rhs->getReturnType();
    if (lhs == DT_UNDEFINED || lhs == DT_VOID || rhs == DT_UNDEFINED || rhs == DT_VOID)
        return DT_UNDEFINED;
    if (_op == "+")
    {
        if (lhs == DT_NUMBER || lhs == DT_VAR_NUMBER)
        {
            if (rhs == DT_NUMBER || rhs == DT_VAR_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING || rhs == DT_VAR_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_NUMBER;
            }
        }
        else if (lhs == DT_STRING || lhs == DT_VAR_STRING)
        {
            if (rhs == DT_NUMBER || rhs == DT_VAR_NUMBER)
            {
                return DT_STRING;
            }
            else if (rhs == DT_STRING || rhs == DT_VAR_STRING)
            {
                return DT_STRING;
            }
            else
            {
                return DT_STRING;
            }
        }
        else
        {
            if (rhs == DT_NUMBER || rhs == DT_VAR_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING || rhs == DT_VAR_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_NUMBER;
            }
        }
    }
    else if (_op == "-")
    {
        if (lhs == DT_NUMBER)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_NUMBER;
            }
        }
        else if (lhs == DT_STRING)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_UNDEFINED;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_NUMBER;
            }
        }
    }
    else if (_op == "*")
    {
        if (lhs == DT_NUMBER)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_NUMBER;
            }
        }
        else if (lhs == DT_STRING)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_UNDEFINED;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_BOOLEAN;
            }
        }
    }
    else if (_op == "%")
    {
        if (lhs == DT_NUMBER)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
        else if (lhs == DT_STRING)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_UNDEFINED;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
    }
    else if (_op == "/")
    {
        if (lhs == DT_NUMBER)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
        else if (lhs == DT_STRING)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_UNDEFINED;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
    }
    else if (_op == "^")
    {
        if (lhs == DT_NUMBER)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_NUMBER;
            }
        }
        else if (lhs == DT_STRING)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_STRING;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_STRING;
            }
        }
        else
        {
            if (rhs == DT_NUMBER)
            {
                return DT_BOOLEAN;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_BOOLEAN;
            }
        }
    }
    else if (_op == "=" || _op == "+=" || _op == "*=" || _op == "/=" || _op == "&=" || _op == "^=")
    {
        if (lhs == DT_NUMBER)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_NUMBER;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_NUMBER;
            }
        }
        else if (lhs == DT_STRING)
        {
            if (rhs == DT_STRING)
            {
                return DT_STRING;
            }
            else if (rhs == DT_STRING)
            {
                return DT_STRING;
            }
            else
            {
                return DT_STRING;
            }
        }
        else
        {
            if (rhs == DT_NUMBER)
            {
                return DT_BOOLEAN;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_BOOLEAN;
            }
        }
    }
    else if (_op == "^^" || _op == "||" || _op == "&&")
    {
        if (lhs == DT_NUMBER)
        {
            if (rhs == DT_NUMBER)
            {
                return DT_BOOLEAN;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_BOOLEAN;
            }
        }
        else if (lhs == DT_STRING)
        {
            if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_UNDEFINED;
            }
        }
        else
        {
            if (rhs == DT_NUMBER)
            {
                return DT_BOOLEAN;
            }
            else if (rhs == DT_STRING)
            {
                return DT_UNDEFINED;
            }
            else
            {
                return DT_BOOLEAN;
            }
        }
    }
    else if (_op == ">" || _op == "<" || _op == "==" || _op == "!=" || _op == ">=" || _op == "<=")
    {
        return DT_BOOLEAN;
    }
    else
        return DT_UNDEFINED;
}

LoopNode::LoopNode(TreeNode* exp, TreeNode* clause)
{
    _exp = exp;
    _clause = clause;
}

LoopNode::~LoopNode()
{
    delete _clause;
    delete _exp;
}

TreeNode* LoopNode::getExpression()
{
    return _exp;
}

TreeNode* LoopNode::getClause()
{
    return _clause;
}

void LoopNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "While:" << std::endl;
    if (_exp != NULL)
    {
        _exp->print(tabIndex + 1);
    }
    
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Loop Through:" << std::endl;
    if (_clause != NULL)
    {
        _clause->print(tabIndex + 1);
    }
}

DataType LoopNode::getReturnType()
{
    return DT_VOID;
}

VariableIdentifierNode::VariableIdentifierNode(std::string identifier)
{
    _id = identifier;
}

VariableIdentifierNode::~VariableIdentifierNode()
{
    _id = "";
}

std::string VariableIdentifierNode::getIdentifier()
{
    return _id;
}

void VariableIdentifierNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Variable Identifier: " << _id << std::endl;
}

DataType VariableIdentifierNode::getReturnType()
{
    return Dictionary::getRef()->getVar(_id)->getType();
}

FunctionCallNode::FunctionCallNode(std::string identifier, std::vector<TreeNode*> args)
{
    _id = identifier;
    _args = args;
}

FunctionCallNode::~FunctionCallNode()
{
    for (int i = 0; i < _args.size(); i ++)
    {
        if (_args[i] != NULL)
            delete _args[i];
    }
    _args.clear();
    _id = "";
}

std::string FunctionCallNode::getIdentifier()
{
    return _id;
}

std::vector<TreeNode*> FunctionCallNode::getArguments()
{
    return _args;
}

void FunctionCallNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Function Call: " << _id << "\t";
    std::cout << "Returning: " << dataTypeToString((isBuiltin(_id)?getBuiltinDataType(_id):Functionary::getRef()->getFunction(_id)->getReturnType())) << std::endl;
    for (int i = 0; i < tabIndex + 1; i ++)
        std::cout << "\t";
    std::cout << "Arguments:" << std::endl;
    for (int i = 0; i < _args.size(); i ++)
    {
        if (_args[i] != NULL)
            _args[i]->print(tabIndex + 2);
    }
}

DataType FunctionCallNode::getReturnType()
{
    if (isBuiltin(_id))
        return getBuiltinDataType(_id);
    return Functionary::getRef()->getFunctionReturnType(_id);
}

ReturnNode::ReturnNode(TreeNode* exp)
{
    _exp = exp;
}

ReturnNode::~ReturnNode()
{
    delete _exp;
}

TreeNode* ReturnNode::getExpression()
{
    return _exp;
}

void ReturnNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Return: \n";
    if (_exp != NULL)
        _exp->print(tabIndex + 1);
}

DataType ReturnNode::getReturnType()
{
    return _exp->getReturnType();
}

DeclarationNode::DeclarationNode(DataType data_type, TreeNode* identifier, TreeNode* expression)
{
    _dt = data_type;
    _id = identifier;
    _exp = expression;
}

DeclarationNode::~DeclarationNode()
{
    delete _exp;
    delete _id;
}

DataType DeclarationNode::getDataType()
{
    return _dt;
}

TreeNode* DeclarationNode::getIdentifier()
{
    return _id;
}

TreeNode* DeclarationNode::getExpression()
{
    return _exp;
}

void DeclarationNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Data Type: " << dataTypeToString(_dt) << std::endl;
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "New Variable:" << std::endl;
    if (_id != NULL)
    {
        _id->print(tabIndex + 1);
    }
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Expression:" << std::endl;
    if (_exp != NULL)
    {
        _exp->print(tabIndex + 1);
    }
}

DataType DeclarationNode::getReturnType()
{
    return DT_VOID;
}

ConditionalNode::ConditionalNode(TreeNode* exp, TreeNode* true_, TreeNode* false_)
{
    _exp = exp;
    _true = true_;
    _false = false_;
}

ConditionalNode::~ConditionalNode()
{
    delete _false;
    delete _true;
    delete _exp;
}

TreeNode* ConditionalNode::getExpression()
{
    return _exp;
}

TreeNode* ConditionalNode::getTrueClause()
{
    return _true;
}

TreeNode* ConditionalNode::getFalseClause()
{
    return _false;
}

void ConditionalNode::print(int tabIndex)
{
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "If:" << std::endl;
    if (_exp != NULL)
    {
        _exp->print(tabIndex + 1);
    }
    
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Then:" << std::endl;
    if (_true != NULL)
    {
        _true->print(tabIndex + 1);
    }
    for (int i = 0; i < tabIndex; i ++)
        std::cout << "\t";
    std::cout << "Else:" << std::endl;
    if (_false != NULL)
    {
        _false->print(tabIndex + 1);
    }
}

DataType ConditionalNode::getReturnType()
{
    return DT_VOID;
}
