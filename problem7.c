#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

// Return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(const char* infix, char* postfix) {
    int i, k = 0;
    char c;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        // If whitespace, skip
        if (isspace(c)) continue;

        // If operand (letter or digit), add to postfix
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push it
        else if (c == '(') {
            push(c);
        }
        // If ')', pop till '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            if (top == -1) {
                printf("Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
            pop(); // Remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (top != -1 && isOperator(peek()) &&
                   ((precedence(c) < precedence(peek())) ||
                    (precedence(c) == precedence(peek()) && c != '^'))) {
                postfix[k++] = pop();
            }
            push(c);
        }
        else {
            printf("Invalid character: %c\n", c);
            exit(EXIT_FAILURE);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        if (peek() == '(') {
            printf("Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression:\n");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline if read by fgets
    size_t len = strlen(infix);
    if (len > 0 && infix[len-1] == '\n') infix[len-1] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
