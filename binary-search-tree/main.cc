#include "bst.cc"

using namespace bst;
using namespace std;

int main()
{
    BST bst;
    bst.insertNode(10);
    bst.insertNode(5);
    bst.insertNode(20);
    bst.insertNode(8);
    bst.insertNode(3);
    bst.insertNode(16);
    bst.insertNode(9);

    cout << "In order " << endl;
    bst.printInOrder(bst.root);

    cout << "Pre order " << endl;
    bst.printPreOrder(bst.root);

    cout << "Post order " << endl;
    bst.printPostOrder(bst.root);

    cout << "Found value " << bst.searchNode(9)->value << endl;
    cout << "Min value: " << bst.minimumNode(bst.root)->value << endl;
    cout << "Max value: " << bst.maximumNode(bst.root)->value << endl;
    cout << "InOrderSuccessor: " << bst.inOrderSuccessor(bst.searchNode(10))->value << endl;
    cout << "InOrderPredecessor: " << bst.inOrderPredecessor(bst.searchNode(20))->value << endl;
    
    cout << "Remove 3 " << endl; 
    bst.removeNode(bst.searchNode(3));
    bst.printInOrder(bst.root);
    bst.insertNode(3);

    cout << "Remove 8 " << endl; 
    bst.removeNode(bst.searchNode(8));
    bst.printInOrder(bst.root);
 
    bst.insertNode(22);
    bst.insertNode(24);
    cout << "Remove 20 " << endl; 
    bst.removeNode(bst.searchNode(20));
    bst.printInOrder(bst.root);
 
}

