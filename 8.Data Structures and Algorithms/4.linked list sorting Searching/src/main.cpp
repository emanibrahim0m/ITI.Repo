#include <iostream>
#include "../include/linkedlist.h"
#include "../include/lib.h"

int main()
{
    // 5 1 9 4
    // 1 4 5 9
    LinkedList orderedList;
    orderedList.push(1);
    orderedList.push(4);
    orderedList.push(5);
    orderedList.push(9);
    
    LinkedList unOrderedListOne;
    unOrderedListOne.push(5);
    unOrderedListOne.push(1);
    unOrderedListOne.push(9);
    unOrderedListOne.push(4);
    
    LinkedList unOrderedListTwo;
    unOrderedListTwo.push(5);
    unOrderedListTwo.push(1);
    unOrderedListTwo.push(9);
    unOrderedListTwo.push(4);
    
    //
    unOrderedListOne.display();
    bubbleSort(unOrderedListOne);
    unOrderedListOne.display();

    unOrderedListTwo.display();
    selectionSort(unOrderedListTwo);
    unOrderedListTwo.display();

    binarySearch(orderedList, 5);
    binarySearch(orderedList, 2);
}