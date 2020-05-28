#include "Node.h"

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
    if (first==NULL||second==NULL)
        return NULL;
    Node* cpyhead = new Node (*first);
    cpyhead->next_ = NULL;
    Node* curr = cpyhead;
    Node* temp = NULL;
    Node* cpy1st = first;
    while (cpy1st!=NULL){
        temp = second;
        while (temp!=NULL){
            if (cpy1st->data_==temp->data_){
                curr->next_ = new Node(*cpy1st);
                if (cpy1st->next_!=NULL)
                    curr->next_->next_ = NULL;
                curr = curr->next_;
                break;
            }
            else
                temp = temp->next_;
        }
        cpy1st = cpy1st->next_;
    }
    if (cpyhead->next_!=NULL){
        Node* temphead = cpyhead->next_;
        while (temphead->next_!=NULL){
            if (temphead->data_==temphead->next_->data_){
                Node* tempnext = temphead->next_;
                temphead->next_ = temphead->next_->next_;
                delete tempnext;
            }
            else
                temphead = temphead->next_;
        }
    }
    Node* result = cpyhead->next_;
    delete cpyhead;
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
