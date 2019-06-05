#include "Node.h"

using namespace std;

void mergeList(Node *first, Node *second) {
  // your code here!
    if (first==NULL || second==NULL)
        return;
    Node* temp1 = first->next_;
    Node* temp2 = second->next_;
    first->next_ = second;
    if (temp1==NULL)
        second->next_=temp2;
    else
        second->next_ = temp1;
    mergeList(temp1,temp2);
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;

