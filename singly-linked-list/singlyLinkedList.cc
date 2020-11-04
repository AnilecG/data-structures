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

void SinglyLinkedList::insertAtIndex(int index, int value)
{
    if (!index)
    {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = new Node(value);
    Node* temp = head;
    int i = 0;
    // index-1 because the preceding node is needed  
    while(i < index-1)     
    {
        if (temp == nullptr)
        {
            std::cout << "index too big!" << std::endl;
            return;
        }
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void SinglyLinkedList::deleteAtIndex(int index)
{
    if (!index)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    int i = 0;
    while(i < index)     
    {
        if (temp == nullptr)
        {
            std::cout << "index too big!" << std::endl;
            return;
        }
        prev = temp;
        temp = temp->next; 
        i++;
    }
    prev->next = temp->next;
    delete temp;
}

Node* SinglyLinkedList::searchValue(int value)
{
    Node* temp = head;
    // the order of conditions matters in this case!!!
    // if temp is null then its value cannot be checked
    while (temp != nullptr && temp->value != value) 
    {
        temp = temp->next;
    }
    return temp;
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