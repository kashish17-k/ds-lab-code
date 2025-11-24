#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end of linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Display linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Concatenate two linked lists
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }
    struct Node* temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n1, n2, value;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter elements of List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertEnd(&list1, value);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter elements of List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertEnd(&list2, value);
    }

    printf("\nList 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    // Concatenate list2 to list1
    concatenate(&list1, list2);

    printf("\nConcatenated List: ");
    displayList(list1);

    return 0;
}
