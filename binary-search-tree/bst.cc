#include "bst.hh"
#include <iostream>

namespace bst
{

void BST::insertNode(Node* node, int value)
{ 
    if (value < node->value) 
    {
        if (node->left != nullptr) insertNode(node->left, value);
        else 
        { 
            auto newNode = new Node(value);
            node->left = newNode;
            newNode->parent = node;
        }
    }
    else if (value >= node->value) 
    {
        if (node->right != nullptr) insertNode(node->right, value);
        else 
        {
            auto newNode = new Node(value);
            node->right = newNode;
            newNode->parent = node;
        }
    }
}

void BST::insertNode(int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        return;
    }
    insertNode(root, value);
}

void BST::printInOrder(Node* node)
{
    if (node == nullptr) return;
    printInOrder(node->left);
    std::cout << node->value << std::endl;
    printInOrder(node->right);
}

void BST::printPreOrder(Node* node)
{
    if (node == nullptr) return;
    std::cout << node->value << std::endl;
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void BST::printPostOrder(Node* node)
{
    if (node == nullptr) return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->value << std::endl;
}

Node* BST::searchNode(int value, Node* node)
{
    if (node != nullptr && node->value == value) return node;
    else if (node == nullptr) return nullptr;

    if (value < node->value) return searchNode(value, node->left);
    return searchNode(value, node->right);
}

Node* BST::searchNode(int value)
{
    if (root == nullptr) 
    {
        std::cout << "Empty tree!" << std::endl;
        return nullptr;
    }
    return searchNode(value, root);
}

Node* BST::minimumNode(Node* node)
{   
    while (node->left!=nullptr) 
        node = node->left;
    return node;
}

Node* BST::maximumNode(Node* node)
{   
    while (node->right != nullptr) 
        node = node->right;
    return node;
}

Node* BST::inOrderSuccessor(Node* node)
{
    if (node->right != nullptr)
        return minimumNode(node->right);
    auto ancestor = node->parent;
    // Travel up until a node which is left child of its parent
    while (ancestor != nullptr && node == ancestor->right)
    {
        node = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

Node* BST::inOrderPredecessor(Node* node)
{
    if (node->left != nullptr)
        return maximumNode(node->left);
    auto ancestor = node->parent;
    while (ancestor != nullptr && node == ancestor->left)
    {
        node = ancestor;
        ancestor = ancestor->parent;
    }
    return ancestor;
}

void BST::removeNode(Node* node)
{
    if (node == root) return;
    // Case 1: no children
    if (node->left == nullptr && node->right == nullptr)
    {
        auto parent = node->parent;
        if(parent->left == node) parent->left = nullptr;
        else parent->right = nullptr;
        delete node;
        return;
    }
    // Case 2: two children
    if (node->right != nullptr && node->left != nullptr)
    {
        auto successor = inOrderSuccessor(node);

        node->value = successor->value;

        removeNode(successor);
    }
    // Case 3: one child
    Node* child = (node->left != nullptr) ? node->left : node->right;
    Node* parent = node->parent;
    if (parent->left == node)
        parent->left = child;
    else
        parent->right = child;
    
    delete node;
    return;
}

} // bst