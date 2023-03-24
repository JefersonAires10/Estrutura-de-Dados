// LISTA SIMPLIMENTE ENCADEADA

#ifndef NODE_H
#define NODE_H

class Node
{
    friend class ForwardList;

private:
    int value;
    Node *next;
public:
    Node(int value, Node* ptrNext) {
        this -> value = value;
        this -> next = ptrNext;
    }
    ~Node() { cout << "Node: " << value << "Destruido " << endl;}
};

#endif // NODE_H