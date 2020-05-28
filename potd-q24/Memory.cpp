#include "Memory.h"
#include <iostream>
#include <iomanip>
#include "Node.h"
#include <vector>
#include <utility>

using namespace std;

/**
Frees the given memory address. Returns if the free was successful or not
Be sure to merge adjacent free blocks when possible
*/
bool Memory::free(unsigned address) {
    Node* current = head;
    while (current != NULL) {
        if (current->address == address) {
            // Your code there
            current->inUse = false;
            if(current->next!=NULL && current->next->inUse==false){
                Node* temp = current->next->next;
                temp->previous = current;
                delete (current->next);
                current->next = temp;
            }
            if (current->previous!=NULL && current->previous->inUse==false){
                Node* temp = current->next;
                current->previous->next = temp;
                temp->previous = current->previous;
                delete current;
            }
            return true;
        }
        current = current->next;
    }

    return false;
}


/**
Reorganizes memory structure so that all of the allocated memory is grouped at the bottom (0x0000) and there is one large
chunk of free memory above.

Note: We do not care about the order of the allocated memory chunks
*/
void Memory::defragment() {
    Node* tail = head;
    while (tail->next!=NULL){tail = tail->next;}
    Node* current = head;
    while (current != NULL) {

        if (current->inUse) {
            // Do nothing
        } else {
            // TODO: Find the next chunk of allocated memory and shift it down to current's address
            // We recommend using the helper function `findNextAllocatedMemoryChunk
            // Your code here
            Node* nextone = findNextAllocatedMemoryChunk(current);
            if (nextone==NULL)
                return;
            //swap address
            unsigned curr_addr = current->address;
            current->address = nextone->address;
            nextone->address = curr_addr;
            //swap nodes
            Node* temp_nextone_prev = nextone->previous;
            nextone->previous->next = current;
            if (current->previous!=NULL)
                current->previous->next = nextone;
            Node* temp_curr_next = current->next;
            current->next = nextone->next;
            nextone->next = temp_curr_next;
            temp_curr_next->previous = nextone;
            if (nextone->next!=NULL)
                nextone->next->previous = current;
            else
                current->next = NULL;
            nextone->previous = current->previous;
            current->previous = temp_nextone_prev;
            //merge free
            current = nextone;
        }
        current = current->next;
    }

    // TODO: Finally merge all of the free blocks of memory together
}
