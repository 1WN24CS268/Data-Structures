#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;


void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}


char pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}


char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


void infixToPostfix(char infix[]) {
    char postfix[SIZE];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];


        if (isalnum(c)) {
            postfix[j++] = c;
        }


        else if (c == '(') {
            push(c);
        }


        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();
        }


        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }


    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("\nPostfix Expression: %s\n", postfix);
}

int main() {
    char infix[SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix);

    return 0;
}
