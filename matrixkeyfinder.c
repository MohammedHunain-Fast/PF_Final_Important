#include <stdio.h>
#include <stdlib.h>

int SearchKey(int **mat, int n, int m, int r, int c, int key);

int main() {
    int n =0, m = 0, key = 0, r = 0, c = 0;;
    printf("Enter rows: ");
    scanf("%d", &n);
    printf("Enter columns: ");
    scanf("%d", &m);

    int **matrix = malloc(n * sizeof(int *));
    if(matrix == NULL) {
        printf("Allocation failed for rows!\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        matrix[i] = malloc(m * sizeof(int));
        if(matrix[i] == NULL) {
            printf("Allocation failed for columns!\n");
            return 1;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            printf("Enter (%d, %d): ", i + 1, j + 1);
            scanf("%d", *(matrix + i) + j);
        }
        printf("Enter key: ");
        scanf("%d", &key);
       int found = SearchKey(matrix, n, m, r, c, key);
        if(!found){
            printf("Key not found!\n");
        }
        for(int i  = 0; i < n;  i++) free(matrix[i]);
        free(matrix);
        matrix = NULL;


    return 0;
}

int SearchKey(int **mat, int n, int m, int r, int c, int key) {
    if(r >= n) {
        return 0;
    }

    if(key == *(*(mat + r) + c)) {
        printf("Key found at (%d, %d)", r, c);
        return 1;
    }
    if(c  + 1 < m) {
        return SearchKey(mat, n, m, r, c + 1, key);
    }
    else {
        return SearchKey(mat, n, m, r + 1, 0, key);
    }

}
