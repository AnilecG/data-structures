#include <iostream>

#include "singlyLinkedList.hh"

using namespace std;
using namespace singlylinkedlist;

int main()
{
    cout << "Hello. Creating a singly linked list ..." << endl;
    SinglyLinkedList list;

    list.insertAtBeginning(1);    
    list.insertAtBeginning(2);    
    list.insertAtBeginning(3);

    list.append(1);    
    list.append(2);    
    list.append(3);

    list.insertAtIndex(0, 0);
    list.traverseList();

    list.deleteAtIndex(0);
    list.traverseList();

    int searchedValue = 3;
    auto node = list.searchValue(searchedValue);
    if (node == nullptr) cout << "Value " << searchedValue << " doesn't exist in the list!" << endl;
    else cout << "Searched node value : " << node->value << endl;
}