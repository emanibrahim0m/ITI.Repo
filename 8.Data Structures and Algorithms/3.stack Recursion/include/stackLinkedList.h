#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include <iostream>

struct StackNode {
    int data;
    StackNode *previousNode;

    StackNode(int x) {data = x; previousNode = NULL;}
};

class Stack_LinkedList {

    StackNode *top;
    int count;


    public:
        Stack_LinkedList()
        {
            top = NULL;
            count = 0;
        }

        bool isEmpty()
        {
            if (count == 0) return true;
            else return false;
        }

        void push(int data)
        {
            StackNode *newNode = new StackNode(data);
            if (top == NULL) 
            {
                // add first node
                top = newNode;
                newNode-> previousNode = NULL;
                newNode = nullptr;
            }
            else 
            {
                // add node to top
                newNode-> previousNode = top;
                top = newNode;
            }
            count++;
        }

        int pop() 
        {
            if (isEmpty()) return -1;

            StackNode *tmp = top;
            int poped = tmp-> data;
            top = top-> previousNode;
            delete tmp;
            tmp = nullptr;
            count--;

            return poped;
        }

        void display()
        {
            StackNode *tmp = top;
            while (tmp != NULL)
            {
                std::cout << tmp-> data;
                tmp = tmp-> previousNode;
            }
        }

        int size()
        {
            return count;
        }

        int peek() {
            if(isEmpty()) return -1;
            else return top->data;
        }
        
        ~Stack_LinkedList()
        {
            StackNode *tmp = top;
            while (tmp != NULL)
            {
                top = top-> previousNode;
                delete tmp; 
                tmp = top;
            }
        }
};

#endif
