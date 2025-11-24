#define MAX 10

void inputMatrix(int mat[MAX][MAX], int r, int c);
void displayMatrix(int mat[MAX][MAX], int r, int c);
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c);
void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c);
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r1, int c1, int r2, int c2);
void transposeMatrix(int A[MAX][MAX], int R[MAX][MAX], int r, int c);

int main() {
    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
    int r1, c1, r2, c2, choice;

    while (1) {
        printf("\n--- Matrix Operations ---\n");
        printf("1. Sum of matrices\n");
        printf("2. Subtraction of matrices\n");
        printf("3. Product of two matrices\n");
        printf("4. Transpose of a matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
            break;

        switch (choice) {
            case 1:
                printf("Enter rows and columns of matrices: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Enter Matrix B:\n");
                inputMatrix(B, r1, c1);

                addMatrix(A, B, R, r1, c1);

                printf("Result (A + B):\n");
                displayMatrix(R, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns of matrices: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Enter Matrix B:\n");
                inputMatrix(B, r1, c1);

                subtractMatrix(A, B, R, r1, c1);

                printf("Result (A - B):\n");
                displayMatrix(R, r1, c1);
                break;

            case 3:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);
                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("Matrix multiplication not possible! Columns of A must equal rows of B.\n");
                    break;
                }

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);
                printf("Enter Matrix B:\n");
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, R, r1, c1, r2, c2);

                printf("Result (A x B):\n");
                displayMatrix(R, r1, c2);
                break;

            case 4:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);

                transposeMatrix(A, R, r1, c1);

                printf("Transpose of A:\n");
                displayMatrix(R, c1, r1);
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

void inputMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            R[i][j] = A[i][j] - B[i][j];
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            R[i][j] = 0;
            for (int k = 0; k < c1; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
    }
}

void transposeMatrix(int A[MAX][MAX], int R[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            R[j][i] = A[i][j];
}
