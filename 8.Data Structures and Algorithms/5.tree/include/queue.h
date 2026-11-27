#ifndef QUEUE_H
#define QUEUE_H

#include "../include/node.h"
#include <iostream>

class QNode
{
    public:
    Node* treeNode;
    QNode* nextNode;
    
    QNode(Node* newNode)
    {
        treeNode = newNode; nextNode = nullptr;
    }
};


class Queue
{
    QNode* front;
    QNode* rear;

    public:

    Queue() {front = nullptr; rear = nullptr;}

    void enqueue(Node* newNode)
    {
        if (!newNode) return;
        QNode* qNodeOne = new QNode(newNode);
        if (!front) {front = qNodeOne; rear = qNodeOne; return;}
        rear-> nextNode = qNodeOne;
        rear = qNodeOne;
    }

    void dequeue()
    {
        if (!front) return;
        if (front == rear) 
        {
            front->treeNode = nullptr;
            delete front;
            rear = nullptr;
            front = nullptr;
        }
        else 
        {
            QNode *ptr = front; 
            front = front->nextNode;
            delete ptr;
        }
    }

    int queueSize()
    {
        QNode* ptr = front;
        int size = 0;
        while(ptr)
        {
            size++;
            ptr = ptr->nextNode;
        }
        return size;
    }

    Node* peek()
    {
        return front ? front->treeNode : nullptr;
    }

    ~Queue()
    {
        while(front)
        {
            QNode* ptr = front;
            front = front->nextNode;
            ptr->treeNode = nullptr;
            delete ptr;
        }
    }
};

#endif