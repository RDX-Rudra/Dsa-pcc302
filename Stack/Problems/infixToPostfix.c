#include <stdio.h>
#include <ctype.h>
#include "../StackDynamic.h"
#include "priorityOfOper.h"

// int priority(char ch){
//     if (ch == '(' || ch == ')' || ch == '[' || ch == ']')
//         return 17;
//     if (ch == '*' || ch == '/' || ch == '%')
//         return 13;
//     if (ch == '+' || ch == '-')
//         return 12;
//     if (ch == '!')
//         return 15;
    
//     else
//         return 0;
// }

int main(){
    SA* S;
    char* p;
    char x, infix[100];
    printf("Enter the infix expression: ");
    scanf("%s", &infix);
    p = infix;
    while(*p != '\0'){
        if(isalnum(*p)){
            printf("%c", *p);
        }
        else if(*p == '(')
            push(S, *p);
        else if(*p == ')'){
            while ((x = pop(S)) != '('){
                printf("%c", x);
            }
        }
        else{
            while(priority(S->top) >= priority(*p))
            printf("%c", pop(S));
        }
        push(S, *p);
    }
}