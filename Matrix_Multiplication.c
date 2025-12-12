#include <stdio.h>
#include <stdlib.h>

int **MultiplyMatrix(int **matrix1, int N1, int M1, int **matrix2, int N2, int M2);

int main() {
    int n1 = 0, m1 = 0, n2  = 0, m2 = 0;
    printf("Enter number of rows and columns for Matrix 1: ");
    scanf("%d %d", &n1, &m1);
    int **matrix1 = malloc(n1 * sizeof(int *));
     if(matrix1 == NULL) {
        printf("Allocation Failed!\n");
        return 1;
     }
    for(int i = 0; i < n1; i++) {
        matrix1[i] = malloc(m1 * sizeof(int));
        if(matrix1[i] == NULL) {
            printf("Allocation failed for columns!\n");
            return 1;
        }
    }
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m1; j++) {
            printf("Enter(%d, %d) of matrix 1: ", i + 1, j + 1);
            scanf("%d",*(matrix1 + i) + j);
            }
        }
    
    printf("Enter number of rows and columns for Matrix 2: ");
    scanf("%d %d", &n2, &m2);
    int **matrix2 = malloc(n2 * sizeof(int *));
     if(matrix2 == NULL) {
        printf("Allocation Failed!\n");
        return 1;
     }
    for(int i = 0; i < n2; i++) {
        matrix2[i] = malloc(m2 * sizeof(int));
        if(matrix2[i] == NULL) {
            printf("Allocation failed for columns!\n");
            return 1;
        }
    }
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < m2; j++) {
            printf("Enter(%d, %d) of matrix 2: ",i + 1, j + 1);
            scanf("%d",*(matrix2 + i) + j);
            }
        }
    if (m1 != n2) {
        printf("Error: Matrix multiplication not possible. Cols of M1 (%d) != Rows of M2 (%d).\n", m1, n2);
        for(int i = 0; i < n1; i++) free(matrix1[i]);
        free(matrix1);
        return 1;
    }
    int  **Result = MultiplyMatrix(matrix1, n1, m1, matrix2, n2, m2);
        printf("Result\n");
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < m2; j++) {
            printf("%d ",*(*(Result + i) + j));
            }
            printf("\n");
        }
        for(int i = 0; i < n1; i++) free(matrix1[i]);
        free(matrix1);
        for(int i = 0; i < n2; i++) free(matrix2[i]);
        free(matrix2);
        for(int i = 0; i < n1; i++) free(Result[i]);
        free(Result);
        matrix1 = NULL;
        matrix2 = NULL;
        Result = NULL;
    return 0;
}

int **MultiplyMatrix(int **matrix1, int N1, int M1, int **matrix2, int N2, int M2) {
    int **result  = malloc(N1 * sizeof(int *));
     if(result == NULL) {
        printf("Allocation Failed!\n");
        return NULL;
     }
    for(int i = 0; i < N1; i++) {
        result[i] = malloc(M2 * sizeof(int));
        if(result[i] == NULL) {
            printf("Allocation failed for columns!\n");
            return NULL;
        }
    }
    for(int i  = 0; i < N1; i++) {
        for(int j = 0; j < M2; j++) {
            *(*(result + i) + j) = 0;
            for(int k = 0; k < M1; k++) {
                *(*(result + i) + j) += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
            }
        }
    }
        return result;
}
