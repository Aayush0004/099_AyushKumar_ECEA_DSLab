/*
Name-Ayush Kumar
Branch - ECE A
Roll NO.-2023ECE099
Enrollment No.-23DOECBTEC000099
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initialize(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack* s) {
    return (s->top == NULL);
}

void push(Stack* s, int data) {
    Node* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    int data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int evaluatePostfix(char* postfix) {
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
    char postfix[100];

    printf("Enter a postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
