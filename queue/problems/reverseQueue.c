#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include "../../Stack/StackDynamic.h"
#include "../../queue/QueueDynamic.h"

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
    enQueue(Q, 56);
    enQueue(Q, 45);
    enQueue(Q, 12);
    enQueue(Q, 23);
    enQueue(Q, 20);
    enQueue(Q, 89);
    displayQueue(Q);
    ReverseQueue(Q);
    printf("After reverse :-\n");
    displayQueue(Q);
}
