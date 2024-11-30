//
// Created by yousef on 11/30/2024.
//

#ifndef INC_1_SINGLE_LINKED_LIST_NODE_H
#define INC_1_SINGLE_LINKED_LIST_NODE_H

template <typename Ty>

class Node{
protected:
    Ty value ;
    Ty* next ;
public:
    Node(Ty value) : value(value) , next(nullptr){}
    Node(Ty value , Ty* next) : value(value) , next(next) {}
};

#endif //INC_1_SINGLE_LINKED_LIST_NODE_H
