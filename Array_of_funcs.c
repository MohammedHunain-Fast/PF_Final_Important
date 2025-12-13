#include <stdio.h>
#include <stdlib.h>

float GetSum(int arr[], int N);
float GetAverage(int arr[], int N);
float GetMax(int arr[], int N);


int main() {
    int n = 0, ch = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if(arr  == NULL) {
        printf("Allocation Failed!\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", (arr + i));
    }

    float (*operations[3])(int *, int) = {GetSum,GetAverage,GetMax};

    printf("Enter your choice\nSum[0] Average[1] Max[2]: ");
    scanf("%d", &ch);

    if(ch > 2 || ch < 0) {
        printf("Invalid Input!\n");
    }
    else {
       float result = operations[ch](arr, n);
       printf("Result: %.2f\n", result);
    }
    free(arr);
    arr = NULL;
    return 0;
}

float GetSum(int arr[], int N) {
    float sum  = 0;
    for(int i = 0; i < N; i++) {
        sum += *(arr + i);
    }
    return sum;
}

float GetAverage(int arr[], int N) {
    float average = 0;
    for(int i = 0; i < N; i++) {
        average += *(arr + i);
    }
    average /= N;

    return average;
}

float GetMax(int arr[], int N) {
    float max = *arr;
    for(int i = 0; i < N; i++) {
        if(max < *(arr + i)) max = *(arr + i);
    }
    return max;
}
