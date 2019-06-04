#include "potd.h"
#include <iostream>
using namespace std;

int main() {
    string a = ("hi");
    a +=" babe";
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
    Node * head2 = new Node;
    Node * head3 = new Node;
    head2->next_ = head3;
    head2->data_=100;
    head3->data_=200;
    head3->next_ = NULL;
    cout <<stringList(head2)<< endl;
    

  // Test 3: A list with more than one node

  return 0;
}
