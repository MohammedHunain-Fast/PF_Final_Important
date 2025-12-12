#include <stdio.h>

int CountDigits(int n);
int SumDigits(int n);

int main() {
    int number = 0, sum = 0, count = 0;
    printf("Enter number: ");
    scanf("%d", &number);    
    count = CountDigits(number);
    printf("Count = %d\n", count);
    sum = SumDigits(number);
    printf("Sum = %d\n", sum);
    return 0;
}

int CountDigits(int n) {
    if(n == 0) {
        return 0; 
    }
    else {      
         return 1 + CountDigits(n / 10);
    }
}

int SumDigits(int n) {
    if(n == 0) {
        return 0;
    }
    else 
    return (n%10) + SumDigits(n/10);
}
