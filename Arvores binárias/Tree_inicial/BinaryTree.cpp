#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

/**
 * @brief Construct a new empty Binary Tree object
 */
BinaryTree::BinaryTree() {
    root = nullptr;
}

/**
 * @brief Construct a new Binary Tree with two subtrees.
 * The subtrees become empty after this operation
 * 
 * @param value The data at the root
 * @param lchild The left subtree
 * @param rchild The right subtree
 */
BinaryTree::BinaryTree(int value, BinaryTree& lchild, BinaryTree& rchild) {
    root = new Node(value, lchild.root, rchild.root);
    lchild.root = nullptr;
    rchild.root = nullptr;
}

/**
 * @brief Indicate that this is the empty tree.
 * 
 * @return true if tree is empty
 * @return false if tree is not empty
 */
bool BinaryTree::is_empty() const {
    return root == nullptr;
}

/**
 * @brief Indicate that this tree is a leaf.
 * 
 * @return true if tree is a leaf
 * @return false if tree is not a leaf
 */
bool BinaryTree::is_leaf() const {
    return (root != nullptr && root->left == nullptr && root->right == nullptr);
}

/* 
    Função recursiva que recebe uma raíz de árvore e retorna true se ela contém valor e falso caso contrário.
*/
bool contains_recursivo(Node *node, int value) {
    if (node == nullptr) { // caso de parada , quando a arvore ta vazia
        return false;
    }
    else if (node->key == value) { // caso de parada 2, a raíz é igual ao valor procurado
        return true;
    }
    else {
        return contains_recursivo(node->left, value) ||
               contains_recursivo(node->right, value);
    }
}
/**
 * @brief Indicate if the tree contains the given value
 * 
 * @return true if the tree contains the given value
 * @return false if the tree does not contains the given value
 */
bool BinaryTree::contains(int value) const {
    return contains_recursivo(root, value);
}
// função que imprime todas as chaves da árvore
// árvore enraizada no ponteiro node
void print_keys_recursivo(Node *node) { // função em pré-ordem
    if (node == nullptr) {
        return; // caso de parada
    }
    else {
        cout << node->key << " ";
        print_keys_recursivo(node->left);
        print_keys_recursivo(node->right);
    }
}
/**
 * @brief Print the keys saved on the tree
 */
void BinaryTree::print_keys() const {
    print_keys_recursivo(root);
}

// se voce passar a raiz de uma arvore para essa função
//ela vai deletar todos os nós da arvore dada e retornar um ponteiro para nullptr
// arvore vazia
Node* clear_recursivo(Node *node) { // função em pós-ordem
    if (node == nullptr) {
        return nullptr;
    }
    else {
        node->left = clear_recursivo(node->left);
        node->right = clear_recursivo(node->right);
        delete node;
        return nullptr;
    }
}

/**
 * @brief empties the tree
 */
void BinaryTree::clear() {
    root = clear_recursivo(root);
}

BinaryTree::~BinaryTree() {
    clear();
}

//função auxiliar que reccebe uma árvore e uma stringstream
// e modifica a stringstream guardando nela uma serialização da sua árvore 
void serialization_rec(Node *node, stringstream &oss) {
    if (node == nullptr) {
        oss << "#";
    }
    else {
        oss << node->key << " ";
        serialization_rec(node->left, oss);
        serialization_rec(node->right, oss);
    }
}

// retorna a serialização da árvore como uma string
std::string BinaryTree::serialization() const {
    stringstream ss;
    serialization_rec(root, ss);
    return ss.str();
}
// Essa função recebe como entrada uma árvore
// string contendo uma versão serializada de uma árvore
// lê os dados e constrói a árvore em pré-ordem 
Node* serializeTree(stringstream &ss) {
    string valor;
    ss >> valor;
    if (valor == "#") { // caso de parada
        return nullptr;
    }
    else {
        //pré-ordem
        int key = std::stoi(valor);
        Node *aux = new Node(key, nullptr, nullptr);
        aux->left = serializeTree(ss);
        aux->right = serializeTree(ss);
        return aux;
    }
}

//Construct
BinaryTree::BinaryTree(string serial) {
    stringstream ss {serial};
    root = serializeTree(ss);
}