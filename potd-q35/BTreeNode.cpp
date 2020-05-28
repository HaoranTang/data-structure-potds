#include <vector>
#include "BTreeNode.h"


BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    unsigned locate;
    for (locate=0; locate<root->elements_.size() && key > root->elements_[locate]; locate++){}
    if (locate < root->elements_.size() && key==root->elements_[locate])
        return root;
    if (root->is_leaf_)
        return NULL;
    else{
        BTreeNode* temp = root->children_[locate];
        return find(temp,key);
    }
}
