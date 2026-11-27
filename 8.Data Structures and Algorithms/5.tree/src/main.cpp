#include <iostream>
#include "../include/node.h"
#include "../include/tree.h"

using namespace std;

int main()
{
    Tree myTree;
    myTree.addNode(50);
    myTree.addNode(15);
    myTree.addNode(60);
    myTree.addNode(10);
    myTree.addNode(20);
    myTree.addNode(50);
    myTree.addNode(90);

    myTree.display();

    myTree.removeNode(15);
    myTree.removeNode(100);
    myTree.removeNode(90);
    myTree.removeNode(50);

    myTree.display();

    cout << myTree.DFS() << endl;
    cout << myTree.BFS() << endl;

    myTree.getNodeData(50);

    

    return 0;
}
