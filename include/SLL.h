#ifndef INC_1_SINGLE_LINKED_LIST_SLL_H
#define INC_1_SINGLE_LINKED_LIST_SLL_H

// Include the Node header file for Node class definition
#include "Node.h"

// Template class for implementing a Singly Linked List (SLL)
template <typename Ty>
class SLL : public Node<Ty> {
protected:
    // Pointer to the first element of the SLL
    Node<Ty>* head;

public:
    // Default constructor: Initializes an empty list
    SLL() {}

    /*
     * empty()
     * Checks whether the singly linked list is empty.
     * @return true if the list has no elements, otherwise false.
     */
    bool empty() {
        return this->head == nullptr;
    }
};

#endif // INC_1_SINGLE_LINKED_LIST_SLL_H
