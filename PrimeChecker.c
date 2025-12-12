#include <stdio.h>
#include <stdlib.h>

void PrimeSelect(int primearr[], int N, int count, int current);
int isPrime(int c, int i);

int main() {
    int n = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *primearr = malloc(n * sizeof(int));
    if(primearr == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }
    PrimeSelect(primearr, n, 0, 2);
    for(int i = 0; i < n; i++) {
        printf("%d\n", *(primearr + i));
    }
    free(primearr);
    primearr = NULL;
    return 0;
}

void PrimeSelect(int primearr[], int N, int count, int current) {
    if(count == N) 
        return;
    if(isPrime(current, current / 2)) { 
        *(primearr + count) = current;
        PrimeSelect(primearr, N, count + 1, current + 1);
    }
    else {
        PrimeSelect(primearr, N, count, current + 1);
    }
}

int isPrime(int num, int i) {
    if(num <= 1) 
        return 0;
    if(i == 1) 
        return 1;
    if(num % i == 0) 
        return 0;

    return isPrime(num, i - 1);
}
