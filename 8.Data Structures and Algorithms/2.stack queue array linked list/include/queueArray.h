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
            front = 0; back = 0; 
            arrSize = size;
            arr = new int [size];
        }

        bool isFull()
        {
            if (back == arrSize - 1)
                return front == 0;
            return back + 1 == front;
        }

        bool isEmpty()
        {   
            return front == back;
        }

        void enQueue(int data)
        {
            if (isFull())
                return;
            if (back == arrSize - 1)
                back = 0;
            else 
                back++;
            arr[back] = data;
        }

        void deQueue()
        {
            if (isEmpty())
                return;
            if (front == arrSize - 1)
                front = 0;
            else
                front++;
        }

        void display()
        {
            if (isEmpty())
            return;

            int tmp = front;
            while (tmp != back)
            {
                if (tmp == arrSize - 1)
                    tmp = 0;
                else
                    tmp++;

                std::cout << arr[tmp] << " ";
            }
        }

        int size()
        {
            int count = 0;
            int tmp = front;
            while (tmp != back)
            {
                count++;
                if (tmp == arrSize - 1)
                    tmp = 0;
                else
                    tmp++;
            }
            return count;
        }

        ~Queue_Array()
        {
            delete[] arr;
        }
};

#endif