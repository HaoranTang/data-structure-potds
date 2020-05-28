#ifndef BTREENODE_H
#define BTREENODE_H

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct BTreeNode {
    bool is_leaf_=true;
    vector<int> elements_;
    vector<BTreeNode*> children_;
    BTreeNode() {}
    BTreeNode (std::vector<int> v) {
      this->elements_ = v;
    }
};

vector<int> traverse(BTreeNode* root);
vector<int> traverseHelper(BTreeNode*& root, std::vector<int> &v);

#endif
