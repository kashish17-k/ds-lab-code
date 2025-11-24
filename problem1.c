

#define MAX 100   // Maximum size of the list

void insert(int arr[], int *n);
void delete(int arr[], int *n);
void display(int arr[], int n);

int main() {
    int arr[MAX], n = 0, choice;

    while (1) {
        printf("\n--- List Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(arr, &n);
                break;
            case 2:
                delete(arr, &n);
                break;
            case 3:
                display(arr, n);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void insert(int arr[], int *n) {
    int pos, value;

    if (*n == MAX) {
        printf("List is full! Cannot insert.\n");
        return;
    }

    printf("Enter position to insert (0 to %d): ", *n);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements to right
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;

    printf("Element inserted successfully!\n");
}

void delete(int arr[], int *n) {
    int pos;

    if (*n == 0) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    printf("Enter position to delete (0 to %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    // Shift elements left
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully!\n");
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("List is empty.\n");
        return;
    }

    printf("List elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}