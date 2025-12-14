#include <stdio.h>
#include <stdlib.h>

int **DeleteRows(int **matrix, int *n, int m);

int main() {
    int n  = 0, m = 2;

    printf("Enter rows: ");
    scanf("%d", &n);

    int **matrix = malloc(n * sizeof(int *));
    if(matrix == NULL) {
        printf("Allocation Failed for rows!\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        matrix[i] = malloc(m * sizeof(int));
        if(matrix[i] == NULL) {
            printf("Allocation Failed for columns!\n");
            return 1;
        }
    }
    for(int i =0; i < n; i++)
        for(int j  = 0; j < m; j++) {
            printf("Enter Element(%d, %d): ", i + 1, j + 1);
            scanf("%d",*(matrix + i) + j);
        }
    
    matrix = DeleteRows(matrix, &n, m);
    printf("New Matrix\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
    for(int i  = 0; i < n; i++) free(matrix[i]);
    free(matrix);
    matrix = NULL;
    return 0;
}

int **DeleteRows(int **matrix, int *n, int m) {
    int r = 0;
    printf("Enter the row you want to delete: ");
    scanf("%d", &r);
    if(r < 1 || r > *n) {
        printf("Invalid input!\n");
        return matrix;
    } 
    int target = r - 1;
    free(matrix[target]);

    for(int i = target; i < (*n); i++) {
        matrix[i] = matrix[i + 1];
    }

    (*n)--;

    if(*n == 0) {
        free(matrix);
        return NULL;
    }

    int **temp = realloc(matrix, (*n) * sizeof(int *) );
    if(temp == NULL) {
        printf("Allocation Failed for rows!\n");
        return matrix;
    }
        
    return temp;

}
