#include "bst.cc"

using namespace bst;
using namespace std;

int main()
{
    BST bst;
    bst.insertNode(10);
    bst.insertNode(5);

    bst.printInOrder(bst.root);
}
