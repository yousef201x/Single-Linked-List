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
    int _size{};

public:
    // Default constructor: Initializes an empty list
    SLL() : head(nullptr) , _size(0) {}

    // Copy constructor
    SLL(const SLL& right) {
        // Check if the list is empty
        if (right.head == nullptr) {
            this->head = nullptr;
            return;
        }

        // Create the head node
        this->head = new Node<Ty>(right.head->value);
        Node<Ty>* itr = this->head; // Pointer to traverse the new list

        // Traverse the original list and copy each node
        Node<Ty>* rhs_itr = right.head->next; // Pointer to traverse the original list
        while (rhs_itr != nullptr) {
            itr->next = new Node<Ty>(rhs_itr->value);  // Create a new node for each value
            itr = itr->next;  // Move to the next node
            rhs_itr = rhs_itr->next;  // Move to the next node in the original list
        }
    }

    // [] operator overloading
    Ty& operator[] (int index) {
        // Check if index is valid
        if (index < 0) {
            throw std::out_of_range("Index cannot be negative");
        }

        Node<Ty>* itr = head;
        for (int i = 0; i < index; ++i) {
            if (itr == nullptr) {
                throw std::out_of_range("Index is out of bounds");
            }
            itr = itr->next;
        }

        return itr->value;
    }

    // Assignment operator overloading
    SLL& operator=(SLL right) {
        // Step 1: Swap the contents of the current object with the right-hand side copy
        std::swap(this->head, right.head);

        // Step 2: Return *this to allow chaining
        return *this;
    }

    /*
     * empty()
     * Checks whether the singly linked list is empty.
     * @return true if the list has no elements, otherwise false.
     */
    bool empty() {
        return this->head == nullptr;
    }

    /*
     * size()
     * @return the size of the singly linked list.
     */

    int size(){
        return this->_size;
    }

    /*
     * push_front()
     * Inserts a new element at the front of the singly linked list.
     * @param value: The value to be inserted in the new node.
     */
    void push_front(Ty value) {
        // Case 1: List is empty
        if (this->empty()) {
            // Create the first node
            this->head = new Node<Ty>(value, nullptr);

            // increase the size by one
            this->_size += 1;
            return;
        }

        // Case 2: List already has elements
        // Temporarily store the current head node
        Node<Ty>* temp = this->head;

        // Create a new node and make it the head
        this->head = new Node<Ty>(value, nullptr);

        // Link the new head node to the previously stored node
        this->head->next = temp;

        // increase the size by one
        this->_size += 1;

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

        // decrease the size by one
        this->_size -= 1;
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
            // increase the size by one
            this->_size += 1;
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

        // increase the size by one
        this->_size += 1;
    }

    /*
     * pop_back()
     * Removes the element at the end of the singly linked list.
     */

    void pop_back() {
        // Case 1: The list is empty
        if (this->empty()) {
            return; // Nothing to remove
        }

        // Case 2: The list has only one node
        if (this->head->next == nullptr) {
            this->pop_front();
            // decrease the size by one
            this->_size -= 1;
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

        // decrease the size by one
        this->_size -= 1;
    }

    void push_at(Ty value , int index){
        // Case 1: Invalid index
        if (index < 0) {
            throw std::out_of_range("Index cannot be negative value.");
        }

        // Case 2: Handle empty list
        if (this->empty() && index != 0) {
            throw std::out_of_range("Index is out of bounds for an empty list");
        }

        // Case 3: If the index is 0, insert at the front
        if (index == 0) {
            this->push_front(value);
            return;
        }

        Node<Ty>* itr = head;
        for(int i = 0 ; i < index - 1  ; i++){
            if (itr->next == nullptr) {
                throw std::out_of_range("Index is out of bounds");
            }
            itr = itr->next;
        }

        // Insert at the specified position
        Node<Ty>* new_node = new Node<Ty>(value, itr->next);
        itr->next = new_node;

        this->_size += 1;
    }

    void pop_at(int index) {
        // Case 1: Invalid index (out of bounds)
        if (index < 0 || index >= this->size()) {
            throw std::out_of_range("Index is out of bounds");
        }

        // Case 2: List is empty, nothing to remove
        if (this->empty()) {
            return;
        }

        // Case 3: Removing the first element
        if (index == 0) {
            pop_front();
            return;
        }

        // Case 4: Removing the last element
        if (index == this->size() - 1) {
            pop_back();
            return;
        }

        // Case 5: Removing an element from the middle
        Node<Ty>* itr = this->head;

        // Iterate to the node before the one we want to remove
        for (int i = 0; i < index - 1; ++i) {
            itr = itr->next;  // move to the next node
        }

        // itr is now the node before the one to remove
        Node<Ty>* temp = itr->next;  // the node to remove
        itr->next = itr->next->next;  // bypass the node to remove

        delete temp;  // deallocate the memory for the node

        this->_size -= 1; // decrease the size by one
    }

    ~SLL() {
        // Start from the head and traverse the list
        Node<Ty>* itr = this->head;
        while (itr != nullptr) {
            Node<Ty>* temp = itr; // Save the current node
            itr = itr->next; // Move to the next node
            delete temp; // Delete the current node
        }
    }

};

#endif // INC_1_SINGLE_LINKED_LIST_SLL_H
