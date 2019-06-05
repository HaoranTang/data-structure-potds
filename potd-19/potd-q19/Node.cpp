#include "Node.h"

using namespace std;

Node *listUnion(Node *first, Node *second) {
  // your code here
    if (first==NULL&&second!=NULL){
        Node* result = new Node(*second);
        return result;
    }
    if (second==NULL&&first!=NULL){
        Node* result = new Node(*first);
        return result;
    }
    if (first==NULL&&second==NULL)
        return NULL;
    bool repeat;
    Node* result = new Node();
    result->data_ = first->data_;
    result->next_ = NULL;
    Node* curr = result;
    Node* temp = first;
    while(temp!=NULL){
        Node* check = result;
        repeat = false;
        while (check!=NULL){
            if (check->data_==temp->data_){
                repeat = true;
                break;
            }
            check = check->next_;
        }
        if (!repeat){
            curr->next_ = new Node (*temp);
            curr = curr->next_;
            curr->next_ = NULL;
        }
        temp = temp->next_;
    }
    temp = second;
    while(temp!=NULL){
        Node* check = result;
        repeat = false;
        while (check!=NULL){
            if (check->data_==temp->data_){
                repeat = true;
                break;
            }
            check = check->next_;
        }
        if (!repeat){
            curr->next_ = new Node(*temp);
            curr = curr->next_;
            curr->next_ = NULL;
        }
        temp = temp->next_;
    }
    return result;
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
