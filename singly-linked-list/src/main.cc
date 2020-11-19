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

    list.insertAtIndex(0, 0);
    list.printList();

    list.deleteAtIndex(0);
    list.printList();

    int searchedValue = 3;
    auto node = list.searchValue(searchedValue);
    if (node == nullptr) cout << "Value " << searchedValue << " doesn't exist in the list!" << endl;
    else cout << "Searched node value : " << node->value << endl;

    list.printList();
    int g = list.getValueAtIndex(2);
    cout << "value at index 2: " << g << endl;
    
    try{
        list.getValueAtIndex(7);
    }
    catch(string msg)
    {
        cout << msg << endl;
    }
}