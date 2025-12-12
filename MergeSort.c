#include <stdio.h>
#include <stdlib.h>

void MergeSortRecursive(int arr[], int left, int right);
void MergeSort(int arr[], int left, int mid, int right);

int main() {
    int n = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        printf("Enter elements %d: ", i + 1);
        scanf("%d", arr + i);
    }
    MergeSortRecursive(arr, 0, n - 1);
    printf("Sorted Array\n");
    for(int i = 0; i < n; i++) {
        printf("%d ",*(arr + i));
    }
    free(arr);
    arr = NULL;
    return 0;
}

void MergeSortRecursive(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        MergeSortRecursive(arr, left, mid);
        MergeSortRecursive(arr, mid + 1, right);

        MergeSort(arr, left, mid, right);
    }
}

void MergeSort(int arr[], int left, int mid, int right) {
    int i = 0, j = 0, k =0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if(L == NULL || R == NULL) {
        printf("Allocation Failed!\n");
        return;
    }

    for(int i = 0; i < n1; i++) *(L + i) = *(arr + left  + i);
    for(int j = 0; j < n2; j++) *(R + j) = *(arr + mid + 1 + j);

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2) {
        if(*(L + i) <= *(R + j)) {
            *(arr + k) = *(L + i);
            i++;
        }
        else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    while(i < n1) {
        *(arr + k) = *(L + i);
        i++;
        k++;
    }
    
    while(j < n2) {
        *(arr + k) = *(R + j);
        j++;
        k++;
    }

    free(L);
    free(R);
    L = NULL;
    R = NULL;

}
