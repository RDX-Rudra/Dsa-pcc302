#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
typedef struct ArrayQueue{
    int front, rear;
    int capacity;
    int* array;
} Queue;

Queue* createQueue(int size){
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

int isEmpty(Queue* Q){
    return (Q->front == -1);
}

int isFull(Queue* Q){
    return ((Q->rear+1)%Q->capacity == Q->front);
}

void enQueue(Queue* Q, int data){
    if(isFull(Q))
        printf("Queue overflowed");
    else{
        Q->rear = (Q->rear +1)%Q->capacity;
        Q->array[Q->rear]= data;
        if(Q->front == -1)
            Q->front = Q->rear;
    }
}

int deQueue(Queue* Q){
    int data = 0;
    if(isEmpty(Q)){
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

void display(Queue *S)
{
    if (isEmpty(S))
        printf("\nStack is Empty\n");
    else{
        for (int i = S->front; i <=S->rear; i++){
            printf("%d\n", S->array[i]);
        }
    }
}

void deleteQueue(Queue* Q){
    if(Q){
        if(Q->array)
            free(Q->array);
        free(Q);
    }
}

void main()
{
    int ch, a, size, data;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    Queue* Q = createQueue(size);
    while (1)
    {
        printf("\n*** Queue Menu ***");
        printf("\n\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit");
        printf("\n\nEnter your choice(1-4): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &data);
            enQueue(Q, data);
            break;
        case 2:
            a = deQueue(Q);
            if(a != INT_MIN)
                printf("\n%d deQueued\n", a);
            break;
        case 3:
            display(Q);
            break;
        case 4:
            deleteQueue(Q);
            exit(0);
        default:
            printf("\nWrong Choice!!");
        }
    }
}