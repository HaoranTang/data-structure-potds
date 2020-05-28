#include <vector>
#include "BTreeNode.h"
using namespace std;

vector<int> traverse(BTreeNode* root) {
    // your code here
    vector<int> v;
    traverseHelper(root, v);
    return v;
}

vector<int> traverseHelper(BTreeNode*& root, vector<int> &v){
    unsigned i;
    for (i=0; i<root->elements_.size(); i++){//for [0],[1]
        if (!root->is_leaf_)
            traverseHelper(root->children_[i],v);
        int j = root->elements_[i];
        v.push_back(j);
    }
    if (!root->is_leaf_)//for [2]
        traverseHelper(root->children_[i],v);
    return v;
}
