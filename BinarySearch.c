#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int arr[], int key, int high, int low);

int main() {
    int n = 0, key = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if(arr == NULL) {
        printf("Allocation Failed!\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        printf("Enter element%d: ", i + 1);
        scanf("%d", arr + i);
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    int found = BinarySearch(arr, key, n - 1, 0);
    if(found !=  -1) {
        printf("Element found on index %d\n", found);
    }
    else {
        printf("Element not found!\n");
    }


    return 0;
}

int BinarySearch(int arr[], int key, int high, int low) {
    int mid = low + (high-low) / 2;
    if(low > high) return -1;
    else if(key == *(arr + mid)) {
        return mid;
    }
    else if(*(arr + mid) > key) {
        return BinarySearch(arr, key, mid - 1, low);
    }
    else {
        return BinarySearch(arr, key, high, mid + 1);
    }
}
