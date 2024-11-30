//
// Created by yousef on 11/30/2024.
//

#ifndef INC_1_SINGLE_LINKED_LIST_NODE_H
#define INC_1_SINGLE_LINKED_LIST_NODE_H

template <typename Ty>

class Node{
public:
    Ty value ;
    Node* next ;

    Node() : value(Ty{}), next(nullptr) {}
    Node(Ty value , Node* next = nullptr) : value(value) , next(next){}
};

#endif //INC_1_SINGLE_LINKED_LIST_NODE_H
