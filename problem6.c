#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int evaluatePostfix(char* postfix) {
    int i, op1, op2, res;
    char ch;
    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isspace(ch)) continue; // ignore spaces

        if (isdigit(ch)) {
            int num = 0;
            // Handle multi-digit numbers
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--; // step back one position since for loop will increment it
            push(num);
        } 
        else if (isOperator(ch)) {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': 
                    if (op2 == 0) {
                        printf("Division by zero error!\n");
                        exit(EXIT_FAILURE);
                    }
                    res = op1 / op2; break;
            }
            push(res);
        }
        else {
            printf("Invalid character '%c' in expression\n", ch);
            exit(EXIT_FAILURE);
        }
    }
    return pop();
}

int main() {
    char postfix[100];
    printf("Enter postfix expression (tokens separated by spaces):\n");
    fgets(postfix, sizeof(postfix), stdin);

    // Remove newline if present
    size_t len = strlen(postfix);
    if (len > 0 && postfix[len-1] == '\n') postfix[len-1] = '\0';

    int result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);
    return 0;
}