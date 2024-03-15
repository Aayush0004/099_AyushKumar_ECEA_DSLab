/*
Name-Ayush Kumar
Branch - ECE A
Roll NO.-2023ECE099
Enrollment No.-23DOECBTEC000099
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Node* createNode(char data) {
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

void push(Stack* s, char data) {
    Node* newNode = createNode(data);
    newNode->next = s->top;
    s->top = newNode;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }
    char data = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}

int areBracketsBalanced(char* exp) {
    Stack bracketStack;
    initialize(&bracketStack);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(&bracketStack, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(&bracketStack)) {
                return 0;
            } else {
                char topBracket = pop(&bracketStack);
                if ((exp[i] == ')' && topBracket != '(') ||
                    (exp[i] == '}' && topBracket != '{') ||
                    (exp[i] == ']' && topBracket != '[')) {
                    return 0;
                }
            }
        }
    }

    return isEmpty(&bracketStack);
}

int main() {
    char exp[100];

    printf("Enter an expression: ");
    fgets(exp, sizeof(exp), stdin);

    if (areBracketsBalanced(exp)) {
        printf("Brackets are balanced!\n");
    } else {
        printf("Brackets are not balanced!\n");
    }

    return 0;
}
