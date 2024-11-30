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


    /*
     * push_front()
     * Inserts a new element at the front of the singly linked list.
     * @param value: The value to be inserted in the new node.
     */
    void push_front(Ty& value) {
        // Case 1: List is empty
        if (this->empty()) {
            this->head = new Node<Ty>(value, nullptr); // Create the first node
            return;
        }

        // Case 2: List already has elements
        // Temporarily store the current head node
        Node<Ty>* temp = this->head;

        // Create a new node and make it the head
        this->head = new Node<Ty>(value, nullptr);

        // Link the new head node to the previously stored node
        this->head->next = temp;
    }

};

#endif // INC_1_SINGLE_LINKED_LIST_SLL_H
