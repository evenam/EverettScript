#ifndef __Evaluate_TreeNode__
#define __Evaluate_TreeNode__

#include <typeinfo>
#include "DataType.h"

class TreeNode
{
public:
    virtual ~TreeNode() {};
    virtual DataType getReturnType() { return VT_UNDEFINED; };
    virtual void print(int tabIndex) {};
};

template <class type>
inline bool checkObjectType(TreeNode* obj)
{
    std::cout << (typeid(*obj)).name() << " " << (typeid(type)).name() << std::endl;
    if (obj == NULL)
        return false;
    return ((typeid(*obj)) == (typeid(type)));
}

#endif
