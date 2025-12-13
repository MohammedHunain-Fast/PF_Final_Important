#include <stdio.h>
#include <stdlib.h>

int **AllocateMatrix(int n);
int CalcDiagonalSum(int **matrix, int n, int current_row);
void freematrix(int **matrix, int n);

int main() {
    int n = 0;
    printf("Enter the n x n of matrix : ");
    scanf("%d", &n);
    int **matrix = AllocateMatrix(n);
    int sum = CalcDiagonalSum(matrix, n, 0);
    printf("Sum: %d\n", sum);
    freematrix(matrix, n);   
    matrix = NULL;
    return 0;
}

int **AllocateMatrix(int n) {
    int **mat = malloc(n * sizeof(int *));
    if(mat == NULL) {
        printf("Allocation Failed for rows!\n");
        return NULL;
    }
    for(int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(int));
        if(mat[i] == NULL) {
            printf("Allocation Failed!\n");
            return NULL;
        }
    }    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("Enter (%d, %d): ", i + 1, j + 1);
                scanf("%d", *(mat + i) + j);
            }
        }
    
    
    return mat;
}

int CalcDiagonalSum(int **matrix, int n, int current_row) {
    if(current_row == n) return 0;

    return *(*(matrix + current_row) + current_row) + CalcDiagonalSum(matrix, n, current_row + 1);
}

void freematrix(int **matrix, int n) {
    for(int i = 0;  i < n; i++) free(matrix[i]);
    free(matrix);
}
