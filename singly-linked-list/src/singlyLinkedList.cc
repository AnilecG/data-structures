#include <iostream>
#include <string>
#include <unordered_set>

#include "singlyLinkedList.hh"

namespace singlylinkedlist
{

void SinglyLinkedList::insertAtBeginning(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::insertAtEnd(int value)
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
    if (index < 0) 
    {
        std::string msg("Negative index not allowed!");
        throw msg;
    }
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
            std::string msg("Index too big!");
            throw msg;
        }
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void SinglyLinkedList::deleteAtIndex(int index)
{
    if (index < 0) 
    {
        std::string msg("Negative index not allowed!");
        throw msg;
    }
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
            std::string msg("Index too big!");
            throw msg;
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

void SinglyLinkedList::printList()
{
    std::cout << "LIST: " << std::endl; 
    Node* node = head;
    while (node != nullptr)
    {
        std::cout << node->value << std::endl;
        node = node->next;
    }
}

int SinglyLinkedList::getValueAtIndex(int index)
{
    if (index < 0) 
    {
        std::string msg("Negative index not allowed!");
        throw msg;
    }
    int i = 0;
    Node* temp = head;
    while (temp && i != index)
    {
        temp = temp->next;
        i++;
    }
    if (temp == nullptr)
    {
        std::string msg("Value not found!");
        throw msg;
    }
    return temp->value;
}

int SinglyLinkedList::getListSize()
{
    int size = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        temp = temp->next;
        size++;
    }    
    return size;
}

void SinglyLinkedList::removeDuplicates()
{
    std::unordered_set<int> hashTable;
    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr)
    {
        auto result = hashTable.insert(curr->value);
        if (!result.second)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }       
    }
}

void SinglyLinkedList::reverseList()
{
    Node* prev = head;
    Node* curr = head->next;
    while (prev != nullptr && curr!= nullptr)
    {
        prev->next = curr->next;
        curr->next = head;
        head = curr;
        curr = prev->next;
    }
}

// bool SinglyLinkedList::isPalindrome()
// {

// }
} // singlylinkedlist