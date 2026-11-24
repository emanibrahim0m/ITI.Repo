#include <iostream>
#include "../include/linkedlist.h"
#include "../include/lib.h"


Node *binarySearch(LinkedList &oList, int data)
{
    int size = oList.size();
    if (size == 0) return nullptr;

    int min = 0;
    int max = oList.size() - 1;
    
    while (min <= max)
    {
        // avoid overflow in ((min + max) / 2)
        int mid = min + (max - min) / 2;
        
        Node* ptr = oList.fNode();

        for (int i = 0; i < mid; i++)
        {
            ptr = ptr->PreviousNode;
        }
        if (ptr->data == data)
        {
            std::cout << "found" << std::endl;
            return ptr;
        }
        else if (ptr->data > data)
        {
            max = mid - 1;
        }
        else 
        {
            min = mid + 1;
        }
    }
    std::cout << "Not found" << std::endl;
    return nullptr;
}