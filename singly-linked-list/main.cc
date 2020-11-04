#include <iostream>

#include "singlyLinkedList.hh"

using namespace std;
using namespace singlylinkedlist;

int main()
{
    // create single linked list
    cout << "Hello. Creating a singly linked list ..." << endl;
    SinglyLinkedList list;

    // append elements
    list.insertAtBeginning(1);    
    list.insertAtBeginning(2);    
    list.insertAtBeginning(3);

    list.append(9);    
    list.append(8);    
    list.append(7);

    // treaverse and print list
    list.traverseList();
}