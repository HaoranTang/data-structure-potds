#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

class Stack {
public:
    int size() const;
    bool isEmpty() const;
    void push(int value);
    int pop();
    Stack();
    ~Stack();
private:
    struct node{
        int value;
        node* next;
        node() {value=0; next = NULL;}
        node(int newval){value = newval; next = NULL;}
    };
    node* head;
    node* tail;
    int length;
};

#endif
