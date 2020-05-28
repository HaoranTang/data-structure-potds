#include "Node.h"
#include <iostream>
using namespace std;

void sortList(Node **head) {
  // your code here!
    if (*head!=NULL){
        Node* curr = *head;
        Node* prev = NULL;
        Node* tempnode = NULL;
        bool change = false;
        for (int i=0;i<Node::getNumNodes();i++){
            while (curr->next_!=NULL){
                tempnode = curr->next_;
                if (curr->data_>tempnode->data_){
                    change = true;
                    curr->next_ = tempnode->next_;
                    tempnode->next_ = curr;
                    if (prev!=NULL)
                        prev->next_ = tempnode;
                    if (*head==curr)
                        *head = tempnode;
                }
                else{
                    prev = curr;
                    curr = curr->next_;
                }
            }
            if (change == false)
                break;
            else{
                prev = NULL;
                curr = *head;
                change = false;
            }
        }
    }
//    if (Node::getNumNodes()==2){
//        Node* first = *head;
//        if (first->data_>(first->next_)->data_){
//            Node* temp = first;
//            first = first->next_;
//            first->next_ = temp;
//            first->next_->next_ = NULL;
//            *head = first;
//
//        }
//    }
//    else{
//        for (int i=0;i<Node::getNumNodes();i++){
//            Node* temphead = *head;
//            Node* tempnode = NULL;
//            Node* prev = *head;
//            while (temphead->next_!=NULL){
//                if (temphead->data_>temphead->next_->data_){
//                    if(temphead==*head){
//                        tempnode = temphead->next_->next_;
//                        temphead->next_->next_ = temphead;
//                        *head = temphead->next_;
//                        temphead->next_ = tempnode;
//                        prev = *head;
//                    }
//                    tempnode = temphead->next_->next_;
//                    prev->next_ = temphead->next_;
//                    temphead->next_->next_ = temphead;
//                    temphead->next_ = tempnode;
//                    prev = prev->next_;
//                }
//                else{
//                    prev = temphead;
//                    temphead = temphead->next_;
//                }
//            }
//        }
//    }
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

