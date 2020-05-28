#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
    if (this==NULL)
        return -1;
    int left = (this->left_)->getHeight();
    int right = (this->right_)->getHeight();
    return 1+ max(left, right);
}
