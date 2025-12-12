#include <stdio.h>
#include <stdlib.h>

int **AllocateMemory(int N, int M);
void InputMatrix(int **matrix, int N, int M);
void DisplayMatrix(int **matrix, int N, int M);
int **TransposeMatrix(int **matrix, int N, int M);
void FreeMemory(int **matrix, int N);

int main() {
    int n = 0, m = 0;
    printf("Enter rows: ");
    scanf("%d", &n);
    printf("Enter columns: ");
    scanf("%d", &m);
    int **matrix = AllocateMemory(n, m);
    InputMatrix(matrix, n, m);
    printf("Before Transpose\n");
    DisplayMatrix(matrix, n, m);
    int **transpose = TransposeMatrix(matrix, n, m);
     printf("After Transpose\n");
    DisplayMatrix(transpose, m, n);
    FreeMemory(matrix, n);
    FreeMemory(transpose, m);
    return 0;
}

int **AllocateMemory(int N, int M) {
    int **mat = malloc(N * sizeof(int *));
    if(mat == NULL) {
        printf("Allocation Failed!\n");
        return NULL;
    }
    for(int i = 0; i < N; i++) {
        mat[i] = malloc(M * sizeof(int));
        if(mat[i] == NULL) {
            printf("Allocation Failed!\n");
            return NULL;
        }
    }
    return mat;
}

void InputMatrix(int **matrix, int N, int M) {
    for(int i = 0; i < N;  i++)
        for(int j = 0; j < M; j++) {
            printf("Enter (%d, %d): ", i + 1, j + 1);
            scanf("%d", *(matrix + i) + j);
        }


}

void DisplayMatrix(int **matrix, int N, int M) {
    for(int i = 0; i < N;  i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
            printf("\n");
    }
}

int **TransposeMatrix(int **matrix, int N, int M) {
    int **trans = AllocateMemory(M, N);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            *(*(trans + j) + i) = *(*(matrix + i) + j);
        }

    return trans;
}

void FreeMemory(int **matrix, int N) {
    for(int i = 0; i < N; i++) {
        free(matrix[i]);
        matrix[i] = NULL;
    }
    free(matrix);
    matrix = NULL;
}
