#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "../include/node.h"
#include "../include/queue.h"

class Tree {
    Node* root;

    // search for Node by data
    Node* getNodeByData(int data) 
    {
        Node* nodePtr = root;
        while (nodePtr)
        {
            if (data == nodePtr->data) return nodePtr;

            else if (data > nodePtr->data) 
                nodePtr = nodePtr-> rightChild;

            else
                nodePtr = nodePtr-> leftChild;
        }
        return nullptr;
    }

    // get parent knowing data of child
    Node* getParent(int data) 
    {
        Node* current = getNodeByData(data);
        if (!current || current == root) return nullptr;
        Node* nodePtr = root;
        while (nodePtr)
        {
            if (nodePtr-> rightChild == current || nodePtr-> leftChild == current) return nodePtr;

            else 
            {
                if (data > nodePtr->data) 
                    nodePtr = nodePtr-> rightChild;
                else
                    nodePtr = nodePtr-> leftChild;
            }
        }
        return nullptr;
    }

    // get last leaf right from a specific node
    Node* getMaxRight(int data) 
    {
        Node* nodePtr = getNodeByData(data);
        if (!nodePtr) return nullptr;
        while (nodePtr)
        {
            if (!nodePtr-> rightChild) return nodePtr;
            else nodePtr = nodePtr->rightChild;
        }
        return nodePtr;
    }

    void displayLDRtree(Node *ptr)
    {
        if (!ptr) return;
        
        displayLDRtree(ptr->leftChild); 

        std::cout << ptr->data << "\t";

        displayLDRtree(ptr-> rightChild); 
    }
    
    public:
        // construct tree 
        Tree()
        {
            root = nullptr;
        }
        Tree(const Tree &copy) = delete;
        Tree& operator=(const Tree &copy) = delete;

        // add new node
        void addNode(int data) {
            Node* newNode = new Node(data);
            Node* nodePtr = root;
            if (!root) 
            {
                root = newNode;
                return;
            }
            Node* tmp = nullptr;
            while (nodePtr)
            {
                if (data == nodePtr->data) 
                {
                    delete newNode;
                    return;
                }
                tmp = nodePtr;
                if (data > nodePtr->data) 
                    nodePtr = nodePtr-> rightChild;
                else
                    nodePtr = nodePtr-> leftChild;
            }
            if (tmp->data > data)
                tmp->leftChild = newNode;
            else 
                tmp->rightChild = newNode;
        }
        
        // check if node with data exist
        bool getNodeData(int data) 
        {
            Node* current = getNodeByData(data);
            if (!current) return false;
            else return true; 
        }

        // get parent data by child data
        int getParentData(int data) 
        {
            Node* current = getParent(data);
            if (!current) return -1;
            else return current-> data;
        }

        // get max right of given data
        int getMaxRightData(int data) 
        {
            Node* current = getMaxRight(data);
            if (!current) return -1;
            else return current-> data;
        }

        // remove node by data 
        void removeNode(int data) 
        {
            Node* current = getNodeByData(data); 
            if (!current) return;
            Node* nodePtr = nullptr;

            // if root 
            if (current == root)
            {
                // if only root exist
                if (!root->leftChild && !root->rightChild)
                    root = nullptr;

                // if root only has one child
                else if (!root->leftChild)
                    root = root->rightChild;
                else if (!root->rightChild)
                    root = root->leftChild;

                // if root with 2 child
                else
                {
                    root = root->leftChild;
                    nodePtr = root;
                    while(nodePtr->rightChild)
                    {
                        nodePtr = nodePtr->rightChild;
                    }
                    nodePtr->rightChild = current->rightChild;
                }

                delete current;
                return;
            }

            // if leaf 
            else if (!current-> rightChild && !current->leftChild)
            {
                Node* tmp = getParent(data);
                if (tmp->leftChild == current)
                    tmp->leftChild = nullptr;
                else 
                    tmp->rightChild = nullptr;
                delete current;
            }

            // if inner node
            else
            {
                Node* tmp = getParent(data);
                nodePtr = current;
                
                if (!current->leftChild)
                {
                    if (tmp->leftChild == current)
                        tmp-> leftChild = current->rightChild;
                    else 
                        tmp-> rightChild = current->rightChild;
                    delete current;
                }
                else if (!current->rightChild)
                {
                    if (tmp->leftChild == current)
                        tmp-> leftChild = current->leftChild;
                    else
                        tmp-> rightChild = current->leftChild;
                    delete current;
                }
                else
                {
                    if (tmp->leftChild == current)
                        tmp->leftChild = current->leftChild;
                    else
                        tmp->rightChild = current->leftChild;
                        
                    nodePtr = current->leftChild;
                    while (nodePtr->rightChild)
                        nodePtr = nodePtr->rightChild;
                    nodePtr->rightChild = current->rightChild;
                    delete current;
                }
            }
        }

        void display()
        {
            displayLDRtree(root);
            std::cout << std::endl;
        }



        int findMax(int one, int two)
        {
            if (one>two) return one;
            else return two;
        }

        int longestDFSpath(Node* ptr)
        {
            if (!ptr) return 0;

            int one = longestDFSpath(ptr->rightChild);
            int two = longestDFSpath(ptr->leftChild);

            return 1 + findMax(one, two);
        }
        int DFS() {return longestDFSpath(root);}

        int longestBFSpath(Node*ptr)
        {
            if (!ptr) return 0;

            int level = 0;
            Queue newQueue;
            newQueue.enqueue(ptr);

            while(newQueue.peek())
            {
                int levelSize = newQueue.queueSize();

                for (int i = 0; i < levelSize; i++)
                {
                    Node* current = newQueue.peek();
                    newQueue.dequeue();

                    if (current->leftChild)
                        newQueue.enqueue(current->leftChild);
                    if (current->rightChild)
                        newQueue.enqueue(current->rightChild);
                }
                level++;
            }

            return level;
        }
        int BFS() {return longestBFSpath(root);}


        void deleteTree(Node* ptr)
        {
            if (!ptr) return;

            deleteTree(ptr->leftChild);

            deleteTree(ptr->rightChild);

                delete ptr;
                ptr = nullptr;
        }

        ~Tree() 
        {     
            deleteTree(root); 
        }
};

#endif