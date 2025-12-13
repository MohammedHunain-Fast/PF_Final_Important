#include <stdio.h>


typedef struct{
    char name[30];
    const long long  CNIC;
    const long long  phone;
} holder;

typedef struct {
    holder clientinfo;
    const int account_no;
    float balance;
    char type[10];
}BankAccount;

void DepositorWithdraw(BankAccount *account1);
void ShowInfo(BankAccount account1);


int main() {
    int ch = 0,cont = 1;

    holder clientinfo = {"John", 456789, 9234753345};
    BankAccount account1 = {clientinfo, 7654, 5000, "Current"};
    while(cont) {
    printf("====Main Menu====\n");
    printf("Withdraw or Deposit[1]\nShow info[2]\nExit[3]\n");
    printf("Enter:");
    scanf("%d", &ch);

    switch(ch) {
        case 1: DepositorWithdraw(&account1); break;
        case 2: ShowInfo(account1); break;
        case 3: cont = 0; break;
        default: printf("Invalid input!\n"); break;
        }
    }
    return 0;
}

void DepositorWithdraw(BankAccount *account1) {
    int number = 0;
    int ch = 0;
    printf("Enter Account number: ");
    scanf("%d", &number);
    if(number != account1->account_no) {
        printf("Invalid account number!\n");
    }
    else {
        printf("Enter Withdraw[1] / Deposit[2] :");
        scanf("%d", &ch);
         float withdrawlamount;
         float depositamount = 0;
        switch(ch) {
            case 1:
                printf("Enter amount: ");
                scanf("%f", &withdrawlamount);
                if(withdrawlamount > account1->balance) printf("Insufficient balance!\n");
                else{ 
                    account1->balance -= withdrawlamount;
                    printf("WWithdraw Succesful!\n");
                 } 
                 break;
            case 2:
                printf("Enter amount: ");
                scanf("%f", &depositamount);
                account1->balance += depositamount;
                printf("Deposit Successful!\n");
        }
    }

}

void ShowInfo(BankAccount account1) {
    int number;
    printf("Enter Account number: ");
    scanf("%d", &number);
    if(number != account1.account_no) printf("Invalid Account number!\n");
    else {
        printf("Name: %s\n", account1.clientinfo.name);
        printf("CNIC: %lld\n", account1.clientinfo.CNIC);
        printf("Phone: %lld\n", account1.clientinfo.phone);
        printf("Balance: %.2f\n", account1.balance);
        printf("Account type: %s\n", account1.type);

    }

}
