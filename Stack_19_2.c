#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MaxSize 10

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
    S->capacity = MaxSize;
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

void push(SA *S)
{
    int data;
    printf("enter the value: ");
    scanf("%d", &data);
    if (IsFullStack(S))
    {
        printf("Stack Overflow");
    }
    else
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
        for (int i = 0; i <= S->top; i++){
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
            push(S);
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