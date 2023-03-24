#ifndef NODE_H
#define NODE_H

using Item = double; // Item eh um double, mas poderia ser qualquer outro tipo nativo

class Node {
    friend class ForwardList;
private:
    Item value;
    Node* next;
public:
    Node(Item value, Node* ptrNext) {
        this->value = value;
        this->next = ptrNext;
    }
};

#endif