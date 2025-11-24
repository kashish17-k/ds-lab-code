#include <stdio.h>
#include <stdlib.h>

#define MAX 50



int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
    printf("Inserted %d\n", x);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Deleted %d\n", stack[top--]);
}

void displayStack() {
    if (top == -1) {
        printf("Stack is Empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
    printf("Inserted %d\n", x);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted %d\n", queue[front++]);
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}


int cqueue[MAX], front2 = -1, rear2 = -1;

void cenqueue(int x) {
    if ((front2 == 0 && rear2 == MAX - 1) || (rear2 + 1 == front2)) {
        printf("Circular Queue Overflow!\n");
        return;
    }
    if (front2 == -1)
        front2 = rear2 = 0;
    else
        rear2 = (rear2 + 1) % MAX;

    cqueue[rear2] = x;
    printf("Inserted %d\n", x);
}

void cdequeue() {
    if (front2 == -1) {
        printf("Circular Queue Underflow!\n");
        return;
    }

    printf("Deleted %d\n", cqueue[front2]);

    if (front2 == rear2)
        front2 = rear2 = -1;
    else
        front2 = (front2 + 1) % MAX;
}

void displayCQueue() {
    if (front2 == -1) {
        printf("Circular Queue is Empty.\n");
        return;
    }

    printf("Circular Queue elements: ");
    int i = front2;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear2) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}



int main() {
    int choice, value;

    while (1) {
        printf("\n=========== MAIN MENU ===========\n");
        printf("1. Stack using Array\n");
        printf("2. Queue using Array\n");
        printf("3. Circular Queue using Array\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int ch;
            while (1) {
                printf("\n--- STACK OPERATIONS ---\n");
                printf("1. Push\n2. Pop\n3. Display\n4. Back\nEnter: ");
                scanf("%d", &ch);
                if (ch == 4) break;
                switch (ch) {
                case 1: printf("Enter value: "); scanf("%d", &value); push(value); break;
                case 2: pop(); break;
                case 3: displayStack(); break;
                default: printf("Invalid!\n");
                }
            }
            break;
        }

        case 2: {
            int ch;
            while (1) {
                printf("\n--- QUEUE OPERATIONS ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\nEnter: ");
                scanf("%d", &ch);
                if (ch == 4) break;
                switch (ch) {
                case 1: printf("Enter value: "); scanf("%d", &value); enqueue(value); break;
                case 2: dequeue(); break;
                case 3: displayQueue(); break;
                default: printf("Invalid!\n");
                }
            }
            break;
        }

        case 3: {
            int ch;
            while (1) {
                printf("\n--- CIRCULAR QUEUE OPERATIONS ---\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back\nEnter: ");
                scanf("%d", &ch);
                if (ch == 4) break;
                switch (ch) {
                case 1: printf("Enter value: "); scanf("%d", &value); cenqueue(value); break;
                case 2: cdequeue(); break;
                case 3: displayCQueue(); break;
                default: printf("Invalid!\n");
                }
            }
            break;
        }

        case 4:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}