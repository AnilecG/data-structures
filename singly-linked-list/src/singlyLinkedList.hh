namespace singlylinkedlist
{

class Node
{
    public:
      Node(int value) : value(value), next(nullptr) {}

      int value;
      Node* next;
};

class SinglyLinkedList
{
    public:
      SinglyLinkedList() : head(nullptr) {}    

      // Inserts a node at the beginning of the list
      void insertAtBeginning(int value);

      // Inserts a node at the end of the list
      void insertAtEnd(int value);

      // Insert a node at the given index
      void insertAtIndex(int index, int value);

      // Deletes a node at the given index
      void deleteAtIndex(int index);

      // Returns the first encountered node with the given value
      Node* searchValue(int value);

      // Travers a list and prints nodes' values
      void printList();

      // Returns value of a node at index
      int getValueAtIndex(int index);

      //  Returns the size of the list
      int getListSize();

      // Removes duplicated values
      void removeDuplicates();
      
    private:
      Node* head;
};

}  // sinlgylinkedlist
