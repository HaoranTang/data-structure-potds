#include "TreeNode.h"
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

//TreeNode* findLastUnbalanced(TreeNode*& root);
bool isHeightBalanced(TreeNode* root);

queue<TreeNode*> q;
stack<TreeNode*> s;

TreeNode* findLastUnbalanced(TreeNode* root) {
    if(root == NULL)
        return root;
    q.push(root);
    if (!isHeightBalanced(root))
        s.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        
        if(node->left_ != NULL){
            q.push(node->left_);
            if(!isHeightBalanced(node->left_)){
                s.push(node->left_);
            }
        }
        if(node->right_ != NULL){
            q.push(node->right_);
            if(!isHeightBalanced(node->right_)){
                s.push(node->right_);
            }
        }
    }
    if(s.empty()){
        return NULL;
    }
    else{
        return s.top();
    }
}
bool isHeightBalanced(TreeNode* root) {
    if (root==NULL)
        return true;
    int left = getHeight(root -> left_);
    int right = getHeight(root -> right_);
    return abs(left-right)<=1 && isHeightBalanced(root->left_) && isHeightBalanced(root->right_);
}

TreeNode::RotationType balanceTree(TreeNode*& subroot) {
	// Your code here
    TreeNode* last = findLastUnbalanced(subroot);
    int balance = getHeight(last->right_)-getHeight(last->left_);
    if (balance==-2){
        int lb = getHeight(last->left_->right_)-getHeight(last->left_->left_);
        if (lb==-1)
            return TreeNode::right;
        else
            return TreeNode::leftRight;
    }
    else if (balance==2){
        int rb = getHeight(last->right_->right_)-getHeight(last->right_->left_);
        if (rb==1)
            return TreeNode::left;
        else
            return TreeNode::rightLeft;
    }
}
