#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int temp[], int n);

int main(void) {
    
    int n = 0;
    
    printf("Enter the number of temperatures: ");
    scanf("%d", &n);
    
    int *temp = malloc(n * sizeof(int));
    
    if(temp == NULL) {
        printf("Allocation Failed!\n");
        return 1;
    }
    
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", temp + i);
    }
    
    printf("Before sorting\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", *(temp + i));
    }

    BubbleSort(temp, n);

    printf("\nAfter sorting\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", *(temp + i));
    }

    free(temp);
    temp = NULL;
    return 0;
}

void BubbleSort(int temp[], int n) {
    int tempval = 0;

    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n - i -1; j++) {
            if(*(temp + j) > *(temp + j + 1)) {
                tempval = *(temp + j);
                *(temp + j) = *(temp + j + 1);
                *(temp + j + 1) = tempval;
                }
            }
        }
}
