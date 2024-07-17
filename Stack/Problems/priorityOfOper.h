#include <stdio.h>
#include <string.h>

int priority(char ch){
    if (ch == '(' || ch == ')' || ch == '[' || ch == ']')
        return 17;
    if (ch == '*' || ch == '/' || ch == '%')
        return 13;
    if (ch == '+' || ch == '-')
        return 12;
    if (ch == '!')
        return 15;
    
    else
        return 0;
}