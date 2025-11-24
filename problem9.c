#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL; 


void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (last == NULL) {
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    printf("%d inserted.\n", value);
}


void delete(int value) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    struct Node* prev = last;
    int found = 0;

    
    if (last == last->next && last->data == value) {
        free(last);
        last = NULL;
        printf("%d deleted.\n", value);
        return;
    }

    do {
        if (temp->data == value) {
            found = 1;
            prev->next = temp->next;
            if (temp == last) {
                last = prev; 
            }
            free(temp);
            printf("%d deleted.\n", value);
            break;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != last->next);

    if (!found)
        printf("%d not found in the list.\n", value);
}


void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(back to head)\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
