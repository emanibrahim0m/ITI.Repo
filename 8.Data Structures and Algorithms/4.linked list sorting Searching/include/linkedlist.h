#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

struct Node
{
    int data;
    Node *PreviousNode;

    Node(int x)
    {
        data = x;
        PreviousNode = NULL;
    }
};

class LinkedList {
    Node *head;
    Node *tail;

    public:
        LinkedList()
        {
            head = nullptr;
            tail = nullptr;
        }

        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;

        void push(int data)
        {
            Node *newNode = new Node(data);
            newNode->PreviousNode = nullptr;
            if (!head)
            {
                head = newNode;
                tail = newNode;
            }
            else 
            {
                newNode-> PreviousNode = head;
                head = newNode;
            }
        }
 
        int size() const
        {
            int counter = 0;
            Node *tmp = head;
            while (tmp)
            {
                counter++;
                tmp = tmp-> PreviousNode;
            }
            return counter;
        }

        void display() 
        {
            Node *tmp = head;
            while(tmp)
            {
                std::cout << tmp->data;
                tmp = tmp->PreviousNode;
            }
            std::cout << std::endl;
        }

        Node* fNode() const
        {
            return head;
        }

        Node* lNode() const
        {
            return tail;
        }

        void swapData(Node *one, Node *two)
        {
            if (!one || !two) return;

            int tmp = one-> data;
            one-> data = two-> data;
            two-> data = tmp;
        }

        ~LinkedList() {
            while (head) {
                Node* tmp = head;
                head = head-> PreviousNode;
                delete tmp;
            }
            tail = nullptr;
        }
};

#endif