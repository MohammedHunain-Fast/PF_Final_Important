#include <stdio.h>
#include <stdlib.h>

int CountEven(int arr[], int N);

int main() {
    int n = 0, count = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
    }
    count = CountEven(arr, n - 1);
    printf("Even: %d", count);
    free(arr);
    arr = NULL;
    return 0;
}

int CountEven(int arr[], int N)  {
    if(N < 0) {
        return 0;
    }
    int even = 0;
    if(*(arr + N) % 2 == 0) {
        even += 1;
    } 
    return even + CountEven(arr, N - 1);
}
