#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T>
struct Node
{
    T value;    // value
    Node *prev; // pointer to the previous node
    Node *next; // pointer to the next node

    Node(const T &val, Node *prev, Node *next)
    {
        value = val;
        this->prev = prev;
        this->next = next;
    }
    Node()
    {
        std::cout << "Node " << value << " liberado\n";
    }
};

#endif // NODE_H