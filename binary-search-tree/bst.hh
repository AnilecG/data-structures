
namespace bst{

class Node 
{
    public:
    Node(int value) : value(value), left(nullptr), right(nullptr), parent(nullptr) {} 
    Node(int value, Node* left, Node* right, Node* parent) 
        : value(value), left(left), right(right), parent(parent) {}

    int value; 
    Node* right;
    Node* left;
    Node* parent;
}; 

class BST 
{
    public:
    BST() : root(nullptr){}

    void insertNode(Node* node, int value);
    void insertNode(int value);
    void printInOrder(Node* node);
    void printPreOrder(Node* node);
    void printPostOrder(Node* node);
    Node* searchNode(int value);
    Node* searchNode(int value, Node* node);
    Node* minimumNode(Node* node);
    Node* maximumNode(Node* node);
    Node* inOrderPredecessor(Node* node);
    Node* inOrderSuccessor(Node* node);
    void removeNode(Node* node);

    Node* root;
};

} // bst