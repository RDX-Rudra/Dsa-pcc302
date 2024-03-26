#include<stdio.h>
typedef struct ArrayQueue{
    int front, rear;
    int capacity;
    int* array;
} Queue;

Queue* queue(int size){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(!Q)
        return NULL;
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->array = malloc(Q->capacity*sizeof(int));
    if(!Q->array)
        return NULL;
    return Q;
}
