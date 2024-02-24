#include <stdio.h>
#include <stdbool.h>
#include "../StackDynamic.h" // Adjust the path to StackDynamic_19_2.c relative to the current file

int isOpeningS(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

int isClosingS(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

int match(char ch1, char ch2) {
    return (ch1 == '(' && ch2 == ')') || (ch1 == '{' && ch2 == '}') || (ch1 == '[' && ch2 == ']');
}

int main() {
    SA *S = createStack();
    int i;
    char ch[100];
    printf("Enter the expression: ");
    scanf("%s", ch);
    bool v = true;
    for(i=0; ch[i] != '\0'; i++) {
        if (isOpeningS(ch[i])){
            push(S, ch[i]);
        }
        else if (isClosingS(ch[i])) {
            char ch1 = pop(S);
            if (!match(ch1, ch[i])) {
                v=false;
                printf("False\n");
                break;
            }
            else
                continue;
        }
        else 
          continue;  
    }
    if(v==true && IsEmpty(S)){
        printf("TRUE\n");
    }
    else
        printf("False\n");
    return 0;
}
