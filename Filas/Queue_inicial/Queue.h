#ifndef QUEUE_H
#define QUEUE_H
#include <stdexcept>
#include "Node.h"

template<typename T>
class Queue {
private:
    Node<T> *m_first {nullptr}; // ponteiro para primeiro
    Node<T> *m_last {nullptr}; // ponteiro para ultimo
    int m_size {0}; // numero de elementos na fila
    
public:
    Queue() = default;
    ~Queue();
    bool empty() const;
    int size() const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    void push(const T& val);
    void pop();
    Queue(const Queue& q) = delete;
    Queue& operator=(const Queue& q) = delete;
};

#endif