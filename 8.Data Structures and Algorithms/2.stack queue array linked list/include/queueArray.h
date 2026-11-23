#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>

class Queue_Array {
    int front; 
    int back;
    int arrSize;
    int *arr;

    public:

        Queue_Array(int size) 
        {
            front = -1; back = -1; 
            arrSize = size;
            arr = new int [size];
        }

        bool isFull()
        {
            if ((back == arrSize - 1 && front == 0) || (back + 1 == front))
                return true;
            return false;
        }

        bool isEmpty()
        {   
            return front == -1;
        }

        void enQueue(int data)
        {
            if (isFull()) return;
            else if (isEmpty())
            {
                front = 0; back = 0;
            }
            else
            {
                back = (back + 1) % arrSize;
            }
            arr[back] = data;
        }

        void deQueue()
        {
            if (isEmpty()) return;
            else if (front == back)
            {
                front = -1; back = -1;
            }
            else
            {
                front = (front + 1) % arrSize;
            }
        }

        void display()
        {
            if (isEmpty()) return;
            int tmp = front;
            while (tmp != (back + 1) % arrSize)
            {
                std::cout << arr[tmp];
                tmp = (tmp + 1) % arrSize;
            }
        }

        int size()
        {
            if (isEmpty()) return 0;            
            if (back >= front)
            return back - front + 1;

            return (arrSize - front) + (back + 1);
        }

        ~Queue_Array()
        {
            delete[] arr;
        }
};

#endif