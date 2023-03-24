#ifndef LIST_H
#define LIST_H
#include <string>
#include <sstream>
#include <iostream>
#include "Node.h"

class ForwardList {
private:
    Node* m_head {nullptr};
    Item m_size {0};
public: 
    // Construtor default: cria uma lista vazia.
    // Internamente, m_head aponta para o sentinela
    ForwardList() {
        m_head = new Node(0, nullptr);
        m_size = 0;
    }
    // insere val no inicio da lista
    void push_front(Item val) {
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        m_size++;
    }
    // inserir val no final da lista
    void push_back(Item val) {
        Node *aux = m_head;
        while(aux->next != nullptr) {
            aux = aux->next;
        }
        Node *novo = new Node(val, nullptr);
        aux->next = novo;
        m_size++;
    }
    // retorna uma string contendo os elementos da lista
    std::string toString() {
        std::stringstream ss;
        ss << "[ ";
        Node* atual = m_head->next;
        while(atual != nullptr) {
            ss << atual->value << " ";
            atual = atual->next;
        }
        ss << "]";
        return ss.str();
    }
    // deixa a lista vazia novamente: com 0 elementos
    void clear() {
        while(m_head->next != nullptr) {
            Node *temp = m_head->next;
            m_head->next = temp->next;
            delete temp;
        }
        m_size = 0;
    }
    // Destrutor
    ~ForwardList() {
        clear();
        delete m_head;
    }
};

#endif