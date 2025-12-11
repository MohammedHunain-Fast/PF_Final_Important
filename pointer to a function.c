#include <stdio.h>

int AddNumber(int c, int d);
int (*pAddNumber)(int, int ) = &AddNumber;
int MultiplyNumber(int c, int d);
int (*pMultiplyNumber)(int, int) = &MultiplyNumber;

int main() {
    int a = 0, b = 0, sum = 0, product = 0, choice = 0;
    printf("Enter 1st number: ");
    scanf("%d", &a);
    printf("Enter 2nd number: ");
    scanf("%d", &b);   
    printf("Which action do you want to perform(Add[1],Multiply[2]): ");
    scanf("%d", &choice);
    if(choice != 1 && choice !=2) {
        printf("Invalid input!\n");
    }
    else if(choice == 1) {
    sum = (*pAddNumber)(a,b); 
    printf("Sum = %d\n", sum);
    }
    else {
    product = (*pMultiplyNumber)(a,b);
    printf("Product = %d\n", product);
    }
    return 0;
}

int AddNumber(int c, int d) {
    return c + d;
}

int MultiplyNumber(int c, int d) {
    return c * d;
}


