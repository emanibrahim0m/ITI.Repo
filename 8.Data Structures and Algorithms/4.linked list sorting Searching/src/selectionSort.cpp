#include "../include/linkedlist.h"
#include "../include/lib.h"

void selectionSort(LinkedList &uoList)
{
    int lSize = uoList.size(); 

    if (lSize < 2) return;

    
    for (int i = 0; i < lSize - 1; i++)
    {
        Node* ptr = uoList.fNode();
        Node* ptrTrack = ptr;

        for (int j = 0; j < lSize - i - 1; j++)
        {
            ptr = ptr-> PreviousNode;
            if (ptr->data > ptrTrack->data)
            {
                ptrTrack = ptr;
            }
        }
        
        uoList.swapData(ptrTrack, ptr);
    }
}