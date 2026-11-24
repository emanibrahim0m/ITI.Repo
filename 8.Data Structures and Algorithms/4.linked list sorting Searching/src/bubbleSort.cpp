#include "../include/linkedlist.h"
#include "../include/lib.h"

void bubbleSort(LinkedList &uoList)
{
    int lSize = uoList.size(); 

    if (lSize < 2) return;

    for (int i = 0; i < lSize - 1; i++)
    {
        
        Node* ptr = uoList.fNode();
        bool flag = false;

        for (int j = 0; j < lSize - i - 1; j++)
        {
            if (ptr->data > ptr->PreviousNode->data)
            {
                uoList.swapData(ptr, ptr-> PreviousNode);
                flag = true;
            }

            ptr = ptr->PreviousNode;
        }

        if (!flag) return;
    }
}