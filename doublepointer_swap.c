#include <stdio.h>
#include <stdlib.h>

void SwapArray(int **pArr1, int **pArr2);

int main() {
   
    int *arr1 = malloc(sizeof(int));
    if(arr1 == NULL) {
        printf("Allocation Failed!\n");
        return 1;
    }
    int *arr2 = malloc(sizeof(int));
    if(arr2 == NULL) {
        printf("Allocation Failed!\n");
        return 1;
    }
    printf("Enter integer 1: ");
    scanf("%d",arr1);
    printf("Enter integer 2: ");
    scanf("%d",arr2);
    printf("===Before Swap===\n");
    printf("%d\n", *arr1);
    printf("%d\n", *arr2);
    SwapArray(&arr1, &arr2);
    printf("===After Swap===\n");
    printf("%d\n", *arr1);
    printf("%d\n", *arr2);
    free(arr1);
    free(arr2);
    arr1 = NULL;
    arr2 = NULL;
    return 0;
}

void SwapArray(int **pArr1, int **pArr2) {
    int temp = 0;
    temp = **pArr1;
    **pArr1 = **pArr2;
    **pArr2 = temp;

}
