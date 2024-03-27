#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<queue\QueueDynamic.h>
#include<Stack\StackDynamic.h>

void ReverseQueue(Queue* Q){
    SA* S = createStack();
    while(!isEmptyQueue(Q))
        push(S, deQueue(Q));
    while (!IsEmpty(S))
    {
        enQueue(Q, pop(S));
    }
    
}

void main(){
    Queue* Q = createQueue();
    deQueue(45);
    deQueue(56);
    deQueue(12);
    deQueue(23);
    deQueue(20);
    deQueue(89);
    displayQueue(Q);
    ReverseQueue(Q);
    displayQueue(Q);
}