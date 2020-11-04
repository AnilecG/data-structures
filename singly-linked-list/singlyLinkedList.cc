#include <iostream>

#include "singlyLinkedList.hh"

namespace singlylinkedlist
{

void SinglyLinkedList::insertAtBeginning(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::append(int value)
{
    if (head == nullptr)
    {
        insertAtBeginning(value); 
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }       
    temp->next = newNode;
}

void SinglyLinkedList::traverseList()
{
    std::cout << "LIST: " << std::endl; 
    Node* node = head;
    while (node != nullptr)
    {
        std::cout << node->value << std::endl;
        node = node->next;
    }
}

} // singlylinkedlist