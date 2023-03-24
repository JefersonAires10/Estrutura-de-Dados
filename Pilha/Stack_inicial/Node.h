#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node {
    T value;    // valor a ser empilhado
    Node *next; // ponteiro para o proximo elemento

    // Construtor
    Node(const T& val, Node *nxt) {
        value = val;
        next = nxt;
    }

    // Destrutor
    ~Node() { 
        delete next; 
    }
};

#endif 