#include <iostream>
#include "../include/stackLinkedList.h"
#include "../include/queueLinkedList.h"
#include "../include/queueArray.h"

using namespace std;

int main() {
    
    // Stack_LinkedList stack;

    // stack.push(5);
    // stack.push(6);
    // cout << stack.size();
    // stack.pop();
    // stack.display();

    // Queue_LinkedList queue;

    // queue.enQueue(5);
    // queue.enQueue(6);
    // cout << queue.size();
    // queue.deQueue();
    // queue.display();

    Queue_Array queue(3);

    queue.enQueue(5);
    queue.enQueue(6);
    cout << queue.size();
    queue.deQueue();
    queue.display();


    return 0;   
}

