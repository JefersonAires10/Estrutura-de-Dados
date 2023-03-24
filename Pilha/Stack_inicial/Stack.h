#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "Node.h"

template<typename T>
class Stack {
private: 
    Node<T> *m_top {nullptr}; // Ponteiro para o topo da pilha
    int m_size{0};

public: 
    Stack() = default; // Construtor default
    ~Stack(); // Destrutor
    int size() const; // Devolve tamanho da pilha
    bool empty() const; // Pilha esta vazia?
    void push(const T& val); // Inserir no topo
    void pop(); // Remover elemento do topo
    T& top(); // Consulta o elemento no topo
    const T& top() const; // Consulta o elemento no topo
};

#endif
