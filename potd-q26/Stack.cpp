#include "Stack.h"
Stack::Stack(){
    head = new node();
    tail = head;
    length = 0;
}
Stack::~Stack(){
    while (head!=NULL){
        node* temp = head->next;
        delete head;
        head = temp;
    }
}
// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return length;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  return (length==0);
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
    if (head==NULL){
        head = new node(value);
        tail = head;
    }
    else{
        node* newNode = new node(value);
        tail->next = newNode;
        tail = tail->next;
    }
    length++;
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
    if (!isEmpty()){
        node* current = head;
        while (current->next!=tail){current = current->next;}
        int ret = tail->value;
        node* temp = tail;
        tail = current;
        tail->next = NULL;
        delete temp;
        length--;
        return ret;
    }
    return -1;
}
