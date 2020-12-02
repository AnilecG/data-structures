#include "bst.hh"
#include <iostream>

namespace bst
{

void BST::insertNode(Node* node, int value)
{ 
    if (value <= node->value) 
    {
        if (node->left != nullptr) insertNode(node->left, value);
        else node->left = new Node(value);
    }
    else if (value > node->value) 
    {
        if (node->right != nullptr) insertNode(node->right, value);
        else node->right = new Node(value);
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


} // bst