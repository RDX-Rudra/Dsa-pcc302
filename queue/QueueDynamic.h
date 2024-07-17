#ifndef QUEUEDYNAMIC_H
#define QUEUEDYNAMIC_H

#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
typedef struct ArrayQueue{
    int front, rear;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(!Q)
        return NULL;
    Q->capacity = 1;
    Q->front = Q->rear = -1;
    Q->array = (int*)malloc(Q->capacity * sizeof(int));
    if(!Q->array)
        return NULL;
    return Q;
}

int isEmptyQueue(Queue* Q){
    return (Q->front == -1);
}

int isFullQueue(Queue* Q){
    return ((Q->rear+1)%Q->capacity == Q->front);
}

void resizeQueue(Queue* Q){
    int size = Q->capacity;
    Q->capacity *= 2;
    Q->array = (int*)realloc(Q->array, Q->capacity * sizeof(int));
    if(!Q->array){
        printf("memory Error");
        return;
    }
    if(Q->front> Q->rear){
        for(int i=0; i<Q->front; i++){
            Q->array[i+size] =Q->array[i];
        }
        Q->rear = Q->rear+size;
    }
}

void enQueue(Queue* Q, int data){
    if(isFullQueue(Q))
        resizeQueue(Q);
    Q->rear = (Q->rear +1)%Q->capacity;
    Q->array[Q->rear]= data;
    if(Q->front == -1)
        Q->front = Q->rear;
}

int deQueue(Queue* Q){
    int data = 0;
    if(isEmptyQueue(Q)){
        printf("Queue underflow");
        return INT_MIN;
    }
    else{
        data=Q->array[Q->front];
        if(Q->front == Q->rear)
            Q->front = Q->rear = -1;
        else
            Q->front =(Q->front + 1) % Q->capacity;
        return data;
    }
}

void displayQueue(Queue *S)
{
    if (isEmptyQueue(S))
        printf("\nStack is Empty\n");
    else{
        for (int i = S->front; i <=S->rear; i++){
            printf("%d\n", S->array[i]);
        }
    }
}

#endif