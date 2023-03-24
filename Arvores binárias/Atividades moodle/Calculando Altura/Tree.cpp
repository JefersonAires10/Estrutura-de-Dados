#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

// Definicao do struct Node
// Em C++ os structs podem ter funcoes-membro, como 
// construtores, destrutores, etc.
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

// Construtor
Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

// Essa funcao recursiva recebe como entrada uma string contendo 
// uma versao serializada da arvore e recebe um ponteiro para ponteiro para o no raiz.
// A funcao ler os dados e constroi a arvore seguindo um percurso em pre-ordem.
void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

// Destrutor
Tree::~Tree() {
    _root = _clear(_root);
}

// Essa funcao recebe uma raiz chamada node e
// ela libera todos os nos decendentes de node e o proprio node.
Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
    std::cout << std::endl;
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}

int Tree::size() { //TODO
    return _size(_root);
}

int Tree::_size(Node *node) { // TODO
    // pré-ordem
    int cont = 0; // armazenar os nós
    if (node != nullptr) { // levando em conta que a árvore não está vazia
        cont = node->key; // primeiro armazeno a cabeça por ser de pré-ordem
        cont = _size(node->left); // passo a quantidade de nós da esquerda para meu cont 
        cont = _size(node->right); // passo a quanntidade de nós da direita para meu cont 
    }
    return cont; // retorno meu contador
}

int Tree::height() { // TODO
    return _height(_root); 
}

int Tree::_height(Node *node) { // TODO
    // pré-ordem
    int esquerda;
    int direita;
    if (node != nullptr) {
        esquerda = _height(node->left);
        direita = _height(node->right);
    }
    if (esquerda > direita) {
        return esquerda + node->key;
    }
    else {
        return direita + node->key;
    }
}



