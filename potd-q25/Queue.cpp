#include "Queue.h"

Queue::Queue() {
    head = NULL;
    tail = NULL;
    length = 0;
}

Queue::~Queue() {
    while (head!=NULL){
        node* temp = head;
        head = head->next;
        delete temp;
    }
}
// `int size()` - returns the number of elements in the stack (0 if empty)
int Queue::size() const {
  return length;
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Queue::isEmpty() const {
    return ((length==0) ? true : false);
}

// `void enqueue(int val)` - enqueue an item to the queue in O(1) time
void Queue::enqueue(int value) {
    if (head==NULL){
        head = new node;
        tail = head;
    }
    else {
        tail->next = new node;
        tail = tail->next;
    }
    tail->value = value;
    tail->next = NULL;
    length++;
}

// `int dequeue()` - removes an item off the queue and returns the value in O(1) time
int Queue::dequeue() {
    if (!isEmpty()){
        node* temp = head;
        int val = temp->value;
        head = head->next;
        delete temp;
        length--;
        return val;
    }
    return -1;
}
