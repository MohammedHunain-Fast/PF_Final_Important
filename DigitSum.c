#include <stdio.h>

int FindSum(int n);

int main() {
    int account_num = 0,sum = 0;
    printf("Enter account Number: ");
    scanf("%d",&account_num);
    sum = FindSum(account_num);
    printf("Sum:%d",sum);
    return 0;
}

int FindSum(int n) {
    if(n == 0) {
        return 0;
    }
    else {
        return (n%10) + FindSum(n/10);
    }
}
