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
    SLL() : head(nullptr) {}

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
    void push_front(Ty value) {
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


    /*
     * pop_front()
     * Removes the element at the front of the singly linked list.
     * This function modifies the head pointer to point to the next node,
     * and deletes the previous head node to free memory.
     */
    void pop_front() {
        // Case 1: List is empty, no element to remove
        if (this->empty()) {
            return; // Return early if the list is empty
        }

        // Case 2: List has elements
        // Temporarily hold the current head node
        Node<Ty>* temp = this->head;

        // Update the head pointer to the next node in the list
        this->head = temp->next;

        // Free the memory used by the old head node
        delete temp;
    }

    /*
     * push_back()
     * Inserts a new element at the end of the singly linked list.
     * @param value: The value to be inserted in the new node.
     */

    void push_back(Ty value) {
        // Check if the singly linked list is empty
        if (this->empty()) {
            this->push_front(value); // If empty, use push_front to add the first element
            return;
        }

        // Pointer to iterate through the list
        Node<Ty>* itr = this->head;

        // Traverse the list until the last node
        while (itr->next != nullptr) {
            itr = itr->next; // Move to the next node
        }

        // Create a new node at the end of the list
        itr->next = new Node<Ty>(value, nullptr);
    }

    void pop_back() {
        // Case 1: The list is empty
        if (this->empty()) {
            return; // Nothing to remove
        }

        // Case 2: The list has only one node
        if (this->head->next == nullptr) {
            this->pop_front();
            return;
        }

        // Case 3: The list has more than one node
        Node<Ty>* itr = this->head;

        // Traverse the list to find the second-to-last node
        while (itr->next->next != nullptr) {
            itr = itr->next;
        }

        // Delete the last node
        delete itr->next;

        // Set the next pointer of the second-to-last node to nullptr
        itr->next = nullptr;
    }


};

#endif // INC_1_SINGLE_LINKED_LIST_SLL_H
