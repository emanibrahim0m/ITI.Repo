#include <iostream>
#include "../include/stackLinkedList.h"
#include "../include/lib.h"

void pushNum(Stack_LinkedList &stack, int n)
{

    if (n < 1)
    {
        return;
    }

    stack.push(n);

    pushNum(stack, n - 1);
}

int pop2Num(Stack_LinkedList &stack)
{
    if (stack.size() < 2) return 1; 
    return stack.pop() * stack.pop();
}

int factorial(int n)
{
    Stack_LinkedList stack;
    pushNum(stack, n);
    
    while(stack.size() > 1)
        stack.push(pop2Num(stack));

    return stack.peek();
}