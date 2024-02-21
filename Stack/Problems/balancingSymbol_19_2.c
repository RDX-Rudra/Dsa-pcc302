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
    int n;
    char ch;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    bool v = true;
    getchar(); // Consume the newline character left in the input buffer

    while (v && n > 0) {
        scanf("%c", &ch);
        if (isOpeningS(ch)){
            push(S, ch);
        }
        else if (isClosingS(ch)) {
            char ch1 = pop(S);
            if (!match(ch1, ch)) {
                v = false;
                break;
            }
            else
                n--;
        }
        else 
            n--;
    }

    if (v && IsEmpty(S))
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
