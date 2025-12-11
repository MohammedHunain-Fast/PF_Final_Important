#include <stdio.h>
#include <stdlib.h>
#define N 2

void InputMatrix(int **matrix,int n);
int SumMatrix(int **matrix,int n);

int main() {
    int sum = 0;
    int **matrix = malloc(N * sizeof(int *));
    if(matrix == NULL) {
        printf("Allocation Failed for rows!\n");
        return 1;
    }
    for(int i = 0; i < N; i++) {
     matrix[i] = malloc(N * sizeof(int));
        if(matrix[i] == NULL) {
            printf("Allocation Failed for columns!\n");
            return 1;
        }
    }    
    InputMatrix(matrix,N);
    sum = SumMatrix(matrix,N);
    printf("Sum = %d",sum);
    for(int i = 0; i < N; i++) free(matrix[i]);
    free(matrix);
    matrix = NULL;
    return 0;

}

void InputMatrix(int **matrix,int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < N; j++) {
            printf("Enter (%d,%d): ",i+1,j+1);
            scanf("%d",*(matrix + i) + j);
        }
    }
}

int SumMatrix(int **matrix,int n) {
    int s = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < N; j++) {
            s += *(*(matrix + i) + j);
        }
    return s;
}
