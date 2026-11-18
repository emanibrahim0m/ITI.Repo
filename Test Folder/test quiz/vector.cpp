#include <iostream>

using namespace std;

class myVector {
    int size;
    int capacity;
    int* arr;

    myVector()
    {    
        size = 0;
        capacity = 2; 
        arr = new int[capacity];
    }

    myVector(myVector &vCopy)
    {
        this-> capacity = vCopy.capacity;
        this-> size = vCopy.size;
        for (int i = 0; i < size; i++)
        {
            this-> arr[i] = vCopy.arr[i];
        }
    }

    ~myVector()
    {
        delete[] arr;
    }

    int getSize() const {return this-> size;}
    int getCapacity() const {return this-> capacity;}

    int operator[] (int index) 
    {
        if (index < size && index >= 0)
        {
            return this-> arr[index];
        }
        else 
            cout << "invalid Index.";
    }

    myVector& operator=(const myVector& vSourse)
    {
        delete[] this-> arr;
        this-> size = vSourse.size;
        this-> capacity = vSourse.capacity;
        for (int i = 0; i < size; i++)
        {
            this-> arr[i] = vSourse.arr[i];
        }
        return *this;
    }

    void pushBack(int val)
    {
        if (this-> size < this-> capacity)
        {
            this-> arr[this-> size] = val;
            this-> size++;
        }
        else 
        {
            capacity *= 2;
            int *old = this-> arr;
            arr = new int[capacity];
            for (int i = 0; i < size; i++)
            {
                this-> arr[i] = old[i];
            }
            delete[] old;
            old = nullptr;
        }
    }

    void popBack()
    {
        if (size == 0)
            cout << "Empty.";
        else 
            size--;
    }
};

int main()
{
    return 0;    
}