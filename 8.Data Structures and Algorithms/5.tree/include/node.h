#ifndef NODE_H
#define NODE_H

class Node {
    public:

        int data;
        Node *leftChild;
        Node *rightChild;

        Node(int x) 
        {
            data = x;
            leftChild = nullptr;
            rightChild = nullptr;
        }
};

#endif
