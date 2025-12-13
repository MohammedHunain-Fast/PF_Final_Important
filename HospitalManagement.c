#include <stdio.h>

typedef struct{
    char name[30];
    char specialization[30];
    int id;
}Doctor;

typedef struct{
    char name[30];
    int age;
    int id;
    
}Patient;

typedef struct{
    Patient patient_details;
    Doctor doctor_details;
    int admit_date;
}Record;

void AddRecord(Record record[], int n);
void CheckSenior(Record record[], int n);
void Search(Record record[], int n);

int main() {
    int ch = 0, cont = 1;
    Record record[2];
    while(cont) {
    printf("===Main Menu===\n");
    printf("Add record [1]\nCheck age status [2]\nSearch [3]\nExit [4]\n");
    printf("Enter: ");
    scanf("%d", &ch);
    switch(ch) {
        case 1: AddRecord(record, 2); break;
        case 2: CheckSenior(record, 2); break;
        case 3: Search(record,2); break;
        case 4: cont = 0; break;
        default: printf("Invalid input!\n");  break;
        }
    }
    return 0;
}

void AddRecord(Record record[], int n) {
    for(int i  = 0; i < n; i++) {
        printf("Enter Patient%d's Name: ", i + 1);
        scanf("%s", record[i].patient_details.name);
        printf("Enter Patients age: " );
        scanf("%d", &record[i].patient_details.age);
        printf("Enter Patients ID: ");
        scanf("%d", &record[i].patient_details.id);
        printf("Enter admit date: ");
        scanf("%d", &record[i].admit_date);
        printf("Enter Doctor's name: ");
        scanf("%s", record[i].doctor_details.name);
        printf("Enter Doctor's Specialization: ");
        scanf("%s", &record[i].doctor_details.specialization);
        printf("Enter Doctor's ID: ");
        scanf("%d", &record[i].doctor_details.id);
    }
}

void CheckSenior(Record record[], int n) {
    for(int i= 0; i < n; i++) {
        if(record[i].patient_details.age >= 50) {
            printf("Senior Citizen found\n");
            printf("-----Details----\n");
            printf("name: %s\n", record[i].patient_details.name);
            printf("ID: %d\n", record[i].patient_details.id);
            printf("Age %d\n", record[i].patient_details.age);
            printf("Admit date: %d\n", record[i].admit_date);
        }
    }
}
void Search(Record record[], int n) {
    int ch = 0, id =0, found = 0;
    printf("1.Patient[1]\t2.doctor[2]: ");
    scanf("%d", &ch);
    switch(ch) {
        case 1:
            printf("Enter Id:");
            scanf("%d", &id);
            for(int i = 0; i < n; i++) {
                if(id == record[i].patient_details.id) {
                    found = 1;
                    printf("Patient Found!\n");
                    printf("-----Details----\n");
                    printf("name: %s\n", record[i].patient_details.name);
                    printf("ID: %d\n", record[i].patient_details.id);
                    printf("Age %d\n", record[i].patient_details.age);
                    printf("Admit date: %d\n", record[i].admit_date);
        }
    }
            if(!found) printf("Patient not found!\n");
        break;

    }

}
