#include <stdio.h>
#include <stdlib.h>

int *Reallocate(int *arr, int *n);

int main() {
    int n = 0;

    printf("Enter size of array:");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Allocation Failed!\n");
        return 1;
    }
    
    for(int i = 0; i < n; i++)  {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }
    
    arr = Reallocate(arr, &n);

    for(int i = 0; i < n; i++)  {
        printf("%d ", *(arr + i));
        
    }
    
    free(arr);
    arr = NULL;
    return 0;
}

int *Reallocate(int *arr, int *n) {
    int input = 0;
    
    printf("Enter an input: ");
    scanf("%d", &input);
    
    if(input == 0) {
        return arr;
    }
    else {        
       int *temp = realloc(arr, (*n + 1) * sizeof(int));
       if(temp == NULL) {
        printf("Allocation failed!\n");
        return arr;
       }
       arr = temp;
       *(arr + *n) = input;
       (*n)++;
       return Reallocate(arr, n);
    }

}
