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
      void insertAtBeginning(int value);
      void append(int value);
      // insert new element before index-th node
      void insertAtIndex(int index, int value);

    //   void deleteNodeAtIndex(int index);
    //   Node* searchValue();
      void traverseList();

    private:
      Node* head;
};

}  // sinlgylinkedlist
