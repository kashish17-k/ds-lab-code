#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;   // Found
    }
    return -1;  // Not found
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Simple Bubble Sort (for Binary Search)
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int n, key;
    clock_t start, end;
    double time_linear, time_binary;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    int *sorted = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    // Copy array for sorting
    for (int i = 0; i < n; i++)
        sorted[i] = arr[i];

    // Sort before binary search
    sortArray(sorted, n);

    // Linear Search Time
    start = clock();
    int linearIndex = linearSearch(arr, n, key);
    end = clock();
    time_linear = (double)(end - start) / CLOCKS_PER_SEC;

    // Binary Search Time
    start = clock();
    int binaryIndex = binarySearch(sorted, n, key);
    end = clock();
    time_binary = (double)(end - start) / CLOCKS_PER_SEC;

    // Results
    printf("\n--- Search Results ---\n");

    if (linearIndex != -1)
        printf("Linear Search: Element found at index %d\n", linearIndex);
    else
        printf("Linear Search: Element NOT found\n");

    if (binaryIndex != -1)
        printf("Binary Search: Element found at index %d (sorted array)\n", binaryIndex);
    else
        printf("Binary Search: Element NOT found\n");

    printf("\n--- Time Comparison ---\n");
    printf("Linear Search Time: %lf seconds\n", time_linear);
    printf("Binary Search Time: %lf seconds\n", time_binary);

    free(arr);
    free(sorted);

    return 0;
}