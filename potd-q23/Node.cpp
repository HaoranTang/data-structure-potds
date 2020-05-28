#include "Node.h"
#include <iostream>
using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here
    if (first==NULL&&second==NULL)
        return NULL;
    Node* newHead = new Node();
    if (first!=NULL)
        newHead->data_ = first->data_;
    else
        newHead->data_ = second->data_;
    newHead->next_ = NULL;
    Node* curr = newHead;
    if (first==NULL){
        while (second!=NULL){
            curr->next_ = new Node (*second);
            curr = curr->next_;
            curr->next_ = NULL;
            second = second->next_;
        }
        Node* out = newHead->next_;
        newHead->next_ = NULL;
        delete newHead;
        return out;
    }
    if (second==NULL){
        while (first!=NULL){
            curr->next_ = new Node (*first);
            curr = curr->next_;
            curr->next_ = NULL;
            first = first->next_;
        }
        Node* out = newHead->next_;
        newHead->next_ = NULL;
        delete newHead;
        return out;
    }
    Node* cpy1st = first;
    Node* cpy2nd = second;
    while (cpy1st!=NULL){
        bool check = false;
        Node* temp = second;
        while (temp!=NULL){
            if (temp->data_==cpy1st->data_)
                check = true;
            temp = temp->next_;
        }
        if (!check){
            curr->next_ = new Node (*cpy1st);
            curr = curr->next_;
            curr->next_ = NULL;
        }
        cpy1st = cpy1st->next_;
    }
    while (cpy2nd!=NULL){
        bool check = false;
        Node* temp = first;
        while (temp!=NULL){
            if (temp->data_==cpy2nd->data_)
                check = true;
            temp = temp->next_;
        }
        if (!check){
            curr->next_ = new Node (*cpy2nd);
            curr = curr->next_;
            curr->next_ = NULL;
        }
        cpy2nd = cpy2nd->next_;
    }
    Node* pt = newHead->next_;
    while (pt!=NULL){
//        cout<<pt->data_<<'\n';
        pt = pt->next_;
    }
    Node* dedup = newHead->next_;
    Node* prev = newHead;
    curr = newHead->next_;
    int count = 0;
    while (dedup!=NULL){
        count = 0;
        while (curr!=NULL){
            if (curr->data_==dedup->data_)
                count++;
            if (count>1){
                prev->next_ = curr->next_;
                curr->next_ = NULL;
                delete curr;
                curr = prev->next_;
                count--;
                continue;
            }
            else{
                prev = curr;
                curr = curr->next_;
            }
        }
        dedup = dedup->next_;
        prev = newHead;
        curr = newHead->next_;
    }
    Node* pt2 = newHead->next_;
    while (pt2!=NULL){
//        cout<<pt2->data_<<'\n';
        pt2 = pt2->next_;
    }
    Node* out = newHead->next_;
    newHead->next_ = NULL;
    delete newHead;
    return out;
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
