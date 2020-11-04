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

      // Appends a node at the end of the list
      void append(int value);

      // Insert a node at the given index
      void insertAtIndex(int index, int value);

      // Deletes a node at the given index
      void deleteAtIndex(int index);

      // Returns the first encountered node with the given value
      Node* searchValue(int value);

      // Travers a list and prints nodes' values
      void traverseList();

    private:
      Node* head;
};

}  // sinlgylinkedlist
