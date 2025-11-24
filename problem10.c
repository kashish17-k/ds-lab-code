#include <stdio.h>
#include <stdlib.h>

// ================== STACK USING LINKED LIST ==================
struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* top = NULL;

void push(int value) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack.\n", value);
}

void popStack() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct StackNode* temp = top;
    top = top->next;
    printf("%d popped from stack.\n", temp->data);
    free(temp);
}

void displayStack() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct StackNode* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ================== QUEUE USING LINKED LIST ==================
struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct QueueNode* front = NULL;
struct QueueNode* rear = NULL;

void enqueue(int value) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued.\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    struct QueueNode* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    printf("%d dequeued.\n", temp->data);
    free(temp);
}

void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct QueueNode* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


struct CQueueNode {
    int data;
    struct CQueueNode* next;
};

struct CQueueNode* last = NULL;

void cenqueue(int value) {
    struct CQueueNode* newNode = (struct CQueueNode*)malloc(sizeof(struct CQueueNode));
    newNode->data = value;
    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("%d inserted in circular queue.\n", value);
}

void cdequeue() {
    if (last == NULL) {
        printf("Circular Queue Underflow\n");
        return;
    }
    struct CQueueNode* temp = last->next;
    if (last == last->next) {
        printf("%d dequeued.\n", temp->data);
        free(temp);
        last = NULL;
    } else {
        last->next = temp->next;
        printf("%d dequeued.\n", temp->data);
        free(temp);
    }
}

void displayCQueue() {
    if (last == NULL) {
        printf("Circular Queue is empty.\n");
        return;
    }
    struct CQueueNode* temp = last->next;
    printf("Circular Queue elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to head)\n");
}


int main() {
    int choice, value;
    while (1) {
        printf("\n===== MAIN MENU =====\n");
        printf("1. Stack Operations\n");
        printf("2. Queue Operations\n");
        printf("3. Circular Queue Operations\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int ch;
                while (1) {
                    printf("\n--- STACK MENU ---\n1.Push\n2.Pop\n3.Display\n4.Back\nEnter choice: ");
                    scanf("%d", &ch);
                    if (ch == 4) break;
                    switch (ch) {
                        case 1: printf("Enter value: "); scanf("%d", &value); push(value); break;
                        case 2: popStack(); break;
                        case 3: displayStack(); break;
                        default: printf("Invalid choice!\n");
                    }
                }
                break;
            }
            case 2: {
                int ch;
                while (1) {
                    printf("\n--- QUEUE MENU ---\n1.Enqueue\n2.Dequeue\n3.Display\n4.Back\nEnter choice: ");
                    scanf("%d", &ch);
                    if (ch == 4) break;
                    switch (ch) {
                        case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
                        case 2: dequeue(); break;
                        case 3: displayQueue(); break;
                        default: printf("Invalid choice!\n");
                    }
                }
                break;
            }
            case 3: {
                int ch;
                while (1) {
                    printf("\n--- CIRCULAR QUEUE MENU ---\n1.Enqueue\n2.Dequeue\n3.Display\n4.Back\nEnter choice: ");
                    scanf("%d", &ch);
                    if (ch == 4) break;
                    switch (ch) {
                        case 1: printf("Enter value: "); scanf("%d", &value); cenqueue(value); break;
                        case 2: cdequeue(); break;
                        case 3: displayCQueue(); break;
                        default: printf("Invalid choice!\n");
                    }
                }
                break;
            }
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}