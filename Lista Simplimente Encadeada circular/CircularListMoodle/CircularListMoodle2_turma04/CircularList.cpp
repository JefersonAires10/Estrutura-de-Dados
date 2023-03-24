#include <sstream>
#include <string>
#include "Node.h" 
#include "CircularList.h" 

// Insere val no final da lista e incrementa o valor de m_size
// Haverá dois casos: lista vazia e lista com elementos
void CircularList::push_back(const Item& val) { 
    if(m_head == nullptr) { // lista vazia
        m_head = new Node(val, nullptr);
        m_head->next = m_head;
    }
    else { // lista com pelo menos 1 elemento
        Node *aux = m_head;
        while(aux->next != m_head) {
            aux = aux->next;
        }
        aux->next = new Node(val, m_head);
    }
    m_size++;
}

Item& CircularList::operator[](int index) {
    Node *aux = m_head;
    for(int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}

const Item& CircularList::operator[](int index) const {
    Node *aux = m_head;
    for(int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->value;
}

// Retira elemento do final da lista
// Se o elemento for retirado com sucesso, m_size é decrementado
void CircularList::pop_back() {
    
}

// Retorna lista como uma string
std::string CircularList::toString() const {
    
}

void CircularList::clear() {
    
}

CircularList::~CircularList() {
    // FAZER
}

