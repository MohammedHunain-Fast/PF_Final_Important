#include <stdio.h>


    typedef struct {
        char name[30];
        int age;
        long long phone;
        long long CNIC;
    }CustomerInfo;

    typedef struct{
        char name[30];
        float price;
    }Product;

    typedef struct{
        int order_id;
        CustomerInfo customer_details;
        Product product_details[3];
    }Order;

void CalcBill(Order store_orders[], int n);


int main() {
    CustomerInfo c1 = {"John", 20, 926543, 65472};
    CustomerInfo c2 = {"Alice", 23, 923454, 65432};
    Product p1 = {"Samsung", 50000};
    Product p2 = {"Iphone",45000};
    Product p3 = {"Ps5",6450};
    Product p4 = {"PC",80000};

    Order Storeorders[2] = {{101, c1, {p1, p2, p3}},
                            {102, c2, {p1,p2,p4}},
                            };

    CalcBill(Storeorders, 2);

    

    return 0;
}
void CalcBill(Order store_orders[], int n) {
    float total[2] = {0};
    printf("=== Bill ===\n");
    for(int i = 0; i < n; i++) {
        printf("Customer %d Name: %s\n", i+1, store_orders[i].customer_details.name);
        for(int j = 0; j < 3; j++) {
            printf("Product %d Name : %s\n", j + 1, store_orders[i].product_details[j].name);
            total[i] += store_orders[i].product_details[j].price;         
        }
        if(total[i] > 50000) {
            total[i] -= total[i] * 0.10;
            printf("Discount Applied\n");
        }
        printf("Total: %.2f\n",total[i]);
        printf("=============\n");
    }
    
}
