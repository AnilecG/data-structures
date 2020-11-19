#include <iostream>

#include "singlyLinkedList.hh"

using namespace std;
using namespace singlylinkedlist;

int main(int argc, char **argv)
{
    cout << "Hello. Creating a singly linked list ..." << endl;
    SinglyLinkedList list;

    list.insertAtBeginning(1);    
    list.insertAtBeginning(2);    
    list.insertAtBeginning(3);

    list.insertAtEnd(1);    
    list.insertAtEnd(2);    
    list.insertAtEnd(3);

    list.printList();
}