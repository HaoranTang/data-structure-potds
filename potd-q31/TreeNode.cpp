#include "TreeNode.h"
#include <map>
#include <iostream>
using namespace std;


bool isHeightBalanced(TreeNode* root) {
  // your code here
    if (root==NULL)
        return true;
    int left = (root->left_)->getHeight();
    int right = (root->right_)->getHeight();
    return abs(left-right)<=1 && isHeightBalanced(root->left_) && isHeightBalanced(root->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

