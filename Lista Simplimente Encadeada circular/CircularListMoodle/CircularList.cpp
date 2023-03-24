#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 

void CircularList::push_back(const Item& val) { 
    if (this->empyt() == true) {
        m_head = new Node(val, nullptr);
        m_head->next = m_head;
        m_size++;
    }

    else if (m_size == 1) {
        Node *aux = new Node(val, nullptr);
        aux->next = m_head;
        m_head->next = aux;
        m_size++;
    }

    else {
        Node *aux = m_head->next;
        while (aux->next != m_head) {
            aux = aux->next;
        }
        Node *newNode = new Node(val, m_head);
        aux->next = newNode;
        m_size++;
    }
}
// remove elemento do final da lista
void CircularList::pop_back() {
    if (this->empty() == true) {
        return;
    }
    else if (m_size == 1) {
        Node *aux = new Node(val, nullptr);
        aux->next = m_head; 
        m_size--;
    }
    else {
        Node *aux = m_head->next;
        while (aux->next != m_head) {
            
        }
    }
}

std::string CircularList::toString() const {
    // FAZER
}

Item& CircularList::operator[](int index) {
    if (index < 0 || index >= m_size) {
        throw std::range_error("indice invalido");
    }
    Node *aux = m_head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}

const Item& CircularList::operator[](int index) const {
    if (index < 0 || index >= m_size) {
        throw std::range_error("indice invalido");
    }
    Node *aux = m_head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}

void CircularList::clear() {
    // FAZER
}

CircularList::~CircularList() {
    // FAZER
}

