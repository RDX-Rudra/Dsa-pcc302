#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ArrayStack
{
    int top;
    int capacity;
    int *array;
} SA;

struct ArrayStack *createStack()
{
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
    if (!S)
    {
        return NULL;
    }
    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if (!S->array)
        return NULL;
    return S;
}

int IsEmpty(SA *S)
{
    return (S->top == -1);
}

int IsFullStack(SA *S)
{
    return (S->top == S->capacity - 1);
}

void DoubleStack(SA *S){
    S->capacity *=2;
    S->array = realloc(S->array, S->capacity *sizeof(int));
}

void push(SA *S, int data)
{
    if (IsFullStack(S))
    {
        DoubleStack(S);
    }
    S->array[++S->top] = data;
}

int pop(SA *S)
{
    if (IsEmpty(S))
    {
        printf("\nStack Underflow\n");
        return INT_MIN;
        ;
    }
    else
        return (S->array[S->top--]);
}

void display(SA *S)
{
    if (IsEmpty(S))
        printf("\nStack is Empty\n");
    else{
        for (int i = S->top; i >= 0; i--){
            printf("%d\n", S->array[i]);
        }
    }
}

void deleteStack(SA *S)
{
    if (S)
    {
        if (S->array)
            free(S->array);
        free(S);
    }
}

void main()
{
    int ch, a;
    SA *S = createStack();
    while (1)
    {
        printf("\n*** Stack Menu ***");
        printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\n\nEnter your choice(1-4): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int data;
            printf("enter the value: ");
            scanf("%d", &data);
            push(S, data);
            break;
        case 2:
            a = pop(S);
            if(a != INT_MIN)
                printf("\n%d popped\n", a);
            break;
        case 3:
            display(S);
            break;
        case 4:
            deleteStack(S);
            exit(0);
        default:
            printf("\nWrong Choice!!");
        }
    }
}