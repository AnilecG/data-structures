
namespace bst{

class Node 
{
    public:
    Node(int value) : value(value), left(nullptr), right(nullptr) {} 
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}

    int value; 
    Node* right;
    Node* left;
}; 

class BST 
{
    public:
    BST() : root(nullptr){}

    void insertNode(Node* node, int value);
    void printInOrder(Node* node);
    void insertNode(int value);
    
    Node* root;
};

} // bst