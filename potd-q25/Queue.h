#ifndef _QUEUE_H
#define _QUEUE_H

#include <cstddef>

class Queue {
    public:
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
        ~Queue();
        Queue();
    private:
        int length;
        struct node{
            int value;
            node* next;
        };
        node* head;
        node* tail;
};

#endif
