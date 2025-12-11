#include <stdio.h>

int Fibonacci(int n);

int main() {
    int term = 0;
    printf("Enter the number of terms: ");
    scanf("%d",&term);
    printf("=== Fibonacci Series ===\n");
    for(int i = 0; i < term; i++) {
        printf("%d ",Fibonacci(i));
    }
    return 0;
}
int Fibonacci(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

