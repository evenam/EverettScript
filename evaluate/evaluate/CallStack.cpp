#include "CallStack.h"

CallStack::CallStack(int size) : _MAX_SIZE(size)
{
	_size = 0;
	_stack = new CSNode[_MAX_SIZE];
}

CallStack::~CallStack()
{
	delete[] _stack;
}

void CallStack::push(TreeNode* node)
{
	if (_size < _MAX_SIZE)
		_stack[_size++]._node = node;
}

TreeNode* CallStack::pop()
{
	if (_size > 0)
		return (_stack[--_size]._node);
	return NULL;
}

TreeNode* CallStack::top()
{
	if (_size > 0)
		return (_stack[_size - 1]._node);
	return NULL;
}

int CallStack::size()
{
	return _size;
}

bool CallStack::empty()
{
	return (_size == 0);
}
