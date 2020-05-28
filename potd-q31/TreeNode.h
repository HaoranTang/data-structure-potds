#ifndef TreeNode_H
#define TreeNode_H

#include <cstddef>
#include <iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
    }
    int getHeight() {
        if (this==NULL)
            return -1;
        int left = (this->left_)->getHeight();
        int right = (this->right_)->getHeight();
        return 1+ max(left, right);
    }
};


bool isHeightBalanced(TreeNode* root);

void deleteTree(TreeNode* root);

#endif
