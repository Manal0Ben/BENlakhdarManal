#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


void infixToPostfix(const char *infix, char *postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        
        if (isdigit(c)) {
            postfix[j++] = c;
        }
        
        else if (c == '(') {
            push(&stack, c);
        }
        
        else if (c == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); 
        }
        else {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(c)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }
    }


    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; 
}


int evaluatePostfix(const char *postfix) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        
        if (isdigit(c)) {
            push(&stack, c - '0'); 
        }
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);

            switch (c) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }

    return pop(&stack); 
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an arithmetic expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
