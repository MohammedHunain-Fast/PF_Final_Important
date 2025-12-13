#include <stdio.h>
#include <stdlib.h>

int *RemoveDuplicates(int *arr, int *n);

int main() {
    int n = 0;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Allocation Failed!\n");
        return 1;
    }
    
    for(int i = 0; i < n; i++) {
    printf("Enter Element %d: ", i + 1);
    scanf("%d", arr + i);
    }

    arr = RemoveDuplicates(arr, &n);
    
    printf("Updated array: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ",*(arr + i));
    }

    free(arr);
    arr = NULL;
    return 0;
}

int *RemoveDuplicates(int *arr, int *n) {
    if(*n == 0) return arr;

    int unique_count = 1;

    for(int i = 1; i < *n; i++) {
        int isDuplicate = 0;
            for(int j = 0; j < unique_count; j++) {
                if(*(arr + i) == *(arr + j)) {
                    isDuplicate = 1;
                    break;
                }
            }
            if(!isDuplicate) {
                *(arr + unique_count) = *(arr + i);
                unique_count++;
            }
    }
    *n = unique_count;


    int *new_arr = realloc(arr, *n * sizeof(int));
    if(new_arr == NULL) {
        printf("Allocation Failed!\n");
        return NULL;
    }

    return new_arr;


}
