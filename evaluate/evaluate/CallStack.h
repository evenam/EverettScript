#ifndef __evaluate_CallStack__
#define __evaluate_CallStack__

#include "Nodes.h"
#include "Executor.h"

#define DEFAULT_MAX_STACK_SIZE 1048576
class CallStack;

class CSNode
{
private:
	friend class CallStack;
	TreeNode* _node;
};

class CallStack
{
private:
	CSNode* _stack;
	int _size;
	const int _MAX_SIZE;
public:
	CallStack(int size = DEFAULT_MAX_STACK_SIZE);
	~CallStack();

	void push(TreeNode* node);
	TreeNode* pop();
	TreeNode* top();
	
	int size();
	bool empty();
};

#endif
