#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int n = 0; // Number of vertices

// Create graph with n vertices
void createGraph() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;

    printf("Graph with %d vertices created.\n", n);
}

// Insert an edge
void insertEdge() {
    if (n == 0) {
        printf("Create a graph first.\n");
        return;
    }
    int u, v;
    printf("Enter the two vertices to connect (0 to %d): ", n - 1);
    scanf("%d %d", &u, &v);

    if (u >= n || v >= n || u < 0 || v < 0) {
        printf("Invalid vertices.\n");
        return;
    }

    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // undirected graph
    printf("Edge inserted between %d and %d.\n", u, v);
}

// Print adjacency matrix
void printAdjMatrix() {
    if (n == 0) {
        printf("Graph not created.\n");
        return;
    }

    printf("Adjacency Matrix:\n   ");
    for (int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
}

// List all vertices adjacent to a specified vertex
void listAdjacent() {
    if (n == 0) {
        printf("Graph not created.\n");
        return;
    }
    int v;
    printf("Enter the vertex (0 to %d): ", n - 1);
    scanf("%d", &v);

    if (v >= n || v < 0) {
        printf("Invalid vertex.\n");
        return;
    }

    printf("Vertices adjacent to %d: ", v);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (adjMatrix[v][i] == 1) {
            printf("%d ", i);
            flag = 1;
        }
    }
    if (!flag)
        printf("None");
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Undirected Graph Menu ---\n");
        printf("1. Create graph\n2. Insert an edge\n3. Print adjacency matrix\n4. List adjacent vertices\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                insertEdge();
                break;
            case 3:
                printAdjMatrix();
                break;
            case 4:
                listAdjacent();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}