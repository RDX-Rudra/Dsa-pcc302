#ifndef STACKDYNAMIC_H
#define STACKDYNAMIC_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ArrayStack
{
    int top;
    int capacity;
    char *array;
} SA;

SA *createStack()
{
    SA *S = (SA *)malloc(sizeof(SA));
    if (!S)
    {
        return NULL;
    }
    S->capacity = 1;
    S->top = -1;
    S->array = (char *)malloc(S->capacity * sizeof(char));
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

void DoubleStack(SA *S)
{
    S->capacity *= 2;
    S->array = (char *)realloc(S->array, S->capacity * sizeof(char));
}

void push(SA *S, char data)
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
    }
    else
        return (S->array[S->top--]);
}

void display(SA *S)
{
    if (IsEmpty(S))
        printf("\nStack is Empty\n");
    else
    {
        for (int i = S->top; i >= 0; i--)
        {
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
#endif
