#ifndef QUEUELINKEDLIST_H
#define QUEUELINKEDLIST_H

#include <iostream>

struct QueueNode {
    int data;
    QueueNode *previousNode;

    QueueNode(int x) {data = x; previousNode = NULL;}
};

class Queue_LinkedList {

    QueueNode *front;
    QueueNode *back;
    int count;


    public:
        Queue_LinkedList()
        {
            front = NULL;
            back = NULL;
            count = 0;
        }

        bool isEmpty()
        {
            if (count == 0) return true;
            else return false;
        }

        void enQueue(int data)
        {
            QueueNode *newNode = new QueueNode(data);
            if (front == NULL)
            {
                front = newNode;
                back = newNode;
                newNode = nullptr;
            }
            else
            {
                back-> previousNode = newNode;
                back = newNode;
                newNode-> previousNode = NULL;
            }
            count++;
        }

        void deQueue()
        {
            // if is empty
            if (isEmpty()) return;

            // if one node
            else if (front == back)
            {
                delete front;
                front = nullptr;
                back = nullptr;
            }

            //else other node
            QueueNode *tmp = front;
            front = front-> previousNode;
            delete tmp;
            tmp = nullptr;
            count--;
        }

        void display()
        {
            QueueNode *tmp = front;
            while (tmp != NULL)
            {
                std::cout << tmp->data;
                tmp = tmp-> previousNode;
            }
            tmp = nullptr;
        }

        int size()
        {
            return count;
        }

        ~Queue_LinkedList()
        {
            QueueNode *tmp = front;
            while (tmp != NULL)
            {
                front = front-> previousNode;
                delete tmp;
                tmp = front;
            }
            front = nullptr;
            back = nullptr;
            tmp = nullptr;
        }
};

#endif