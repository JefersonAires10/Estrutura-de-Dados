#ifndef LIST_H
#define LIST_
#include "Node.h"

template <typename T>
class List
{
private:
    Node<T> *m_head{nullptr};
    int m_size{0};

public:
    class iterador
    {
    private:
        Node<T> *pointer{nullptr};

    public:
        iterator(Node<T> *ptr)
        {
            pointer = ptr;
        }
        iterador& operator++() 
        {
            pointer = pointer->next;
            return *this;
        }
        bool operator!=(const iterator& it)
        {
            return this->pointer != it.pointer;
        }
        T& operator*()
        {
            return pointer->value;
        }
    };

    iterador begin()
    {
        return iterator(m_head->next);
    }
    iterator end() 
    {
        return iterator(m_head);
    }

    // default constructor
    List()
    {
        m_head = new Node<T>(0, m_head, nullptr);
        m_head->prev = m_head->next = m_head;
    }
    // insere um elemento no final da lista
    void push_back(const T &val)
    {
        Node<T> *aux = new Node<T>(val, m_head->prev, m_head);
        aux->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    }
    T &operator[](int index)
    {
        Node<T> *aux = m_head->next;
        for (int i = 0; i < index; i++)
        {
            aux = aux->next;
        }
        return aux->value;
    }
    const T &operator[](int index) const
    {
        Node<T> *aux = m_head->next;
        for (int i = 0; i < index; i++)
        {
            aux = aux->next;
        }
        return aux->value;
    }
    // retorna o numero de elementos da lista
    int size() const
    {
        return m_size;
    }
    // retorna true se e somente se a lista estiver vazia
    bool empty() const
    {
        return m_size == 0;
    }
    // deixa a lista vazia novamente, liberando memoria
    void clear()
    {
        Node<T> *aux = m_head->prev;
        while (aux != m_head)
        {
            Node<T> *temp = aux;
            aux = aux->prev;
            delete temp;
        }
        m_head->prev = m_head->next = m_head;
        m_size = 0;
    }
    // Destrutor
    ~List()
    {
        clear();
        delete m_head;
    }
};

#endif