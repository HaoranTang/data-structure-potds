#include "potd.h"
#include <iostream>
#include <string>
using namespace std;

string stringList(Node *head) {
    // your code here!
    if (head==NULL)
        return "Empty list";
    string result ="";
    int i = 0;
    while (true){
        if (head==NULL){
            return result;
        }
        if (i>0)
            result += " -> ";
        result +="Node ";
        result += to_string(i);
        result +=": ";
        result += to_string(head->data_);
        i++;
        head = head->next_;
    }
}
