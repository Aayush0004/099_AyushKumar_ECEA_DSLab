/*
Name-Ayush Kumar
Branch - ECE A
Roll NO.-2023ECE099
Enrollment No.-23DOECBTEC000099
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top == -1);
}

int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

int evaluatePostfix(char *postfix) {
    Stack operandStack;
    initialize(&operandStack);

    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(&operandStack, postfix[i] - '0');
        } else {
            int operand2 = pop(&operandStack);
            int operand1 = pop(&operandStack);
            switch (postfix[i]) {
                case '+':
                    push(&operandStack, operand1 + operand2);
                    break;
                case '-':
                    push(&operandStack, operand1 - operand2);
                    break;
                case '*':
                    push(&operandStack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0)
                        push(&operandStack, operand1 / operand2);
                    else {
                        printf("Division by zero error!\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Invalid operator!\n");
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }

    return pop(&operandStack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    fgets(postfix, MAX_SIZE, stdin);
    postfix[strcspn(postfix, "\n")] = '\0';
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
