#include <stdio.h>
#include <stdlib.h>

// Account data of a customer.
typedef struct customer {
    int account_no;
    char name[50];
    int balance;
    int status;
} customer;

// Declaration of the functions.
void accept(customer[], int);
void display(customer[], int);
int search(customer[], int, int);
void deposit(customer[], int, int, int);
void withdraw(customer[], int, int, int);
void delete(customer[], int, int);

int main() {
    // Declaring the required variables used to perform the given operations.
    customer data[20];
    customer *ptr = data;
    int n, choice, account_no, amount, index, stat;

    printf("\nBanking System\n\n");
    printf("Number of customer records you want to enter? : ");
    scanf("%d", &n);
    accept(data, n);

    // Creating a loop to perform the operations.
    do {
        printf("\nBanking System Menu :\n");
        printf(" Press 1 to display all records.\n");
        printf(" Press 2 to search a record.\n");
        printf(" Press 3 to deposit amount.\n");
        printf(" Press 4 to withdraw amount.\n");
        printf(" Press 5 to delete account.\n");
        printf(" Press 0 to exit.\n");
        fflush(stdin);
        printf("\n Enter choice(0-5) : ");
        scanf("%d", &choice);

        // Switch case according to the given choice.
        switch (choice) {
            // Case 0 to exit the program.
            case 0:
                printf("\nExiting program..\n");
                break;

            // Case 1 for displaying data.
            case 1:
                display(data, n);
                break;

            // Case 2 for searching a particular customer.
            case 2:
                printf("\nEnter account number to search : ");
                scanf("%d", &account_no);
                index = search(data, n, account_no);
                if (index ==  - 1)
                    printf("Record not found\n");
                else
                    printf("\nA/c Number: %d\nName: %s\nBalance: %d\n", data[index].account_no, data[index].name, data[index].balance);
                break;

            // Case 3 for depositing amount in account.
            case 3:
                printf("\nEnter account number : ");
                scanf("%d", &account_no);
                printf("\nEnter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
            
            // Case 4 for withdrawing amount from account.
            case 4:
                printf("\nEnter account number : ");
                scanf("%d", &account_no);
                printf("\nEnter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, account_no, amount);
                break;

            // Case 5 for deleting an account.
            case 5:
                printf("\nEnter account number : ");
                scanf("%d", &account_no);
                delete(data, n, account_no);

            // Default case.
            default:
                printf("\nIncorrect input");
        }
    } while (choice != 0);

    return 0;
}

// Function to taking data input of customers.
void accept(struct customer list[80], int s) {

    int i;
    for (i = 0; i < s; i++) {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        scanf("%s", list[i].name);
        list[i].balance = 0;
        list[i].status = 1;
    } 
}

// Function to display data of customers.
void display(struct customer list[80], int s) {

    int i;
    printf("\nA/c No\tName\tBalance\n");

    for (i=0; i<s; i++) {
        if (list[i].status != 0)
            printf("%d\t%s\t%d\n", list[i].account_no, list[i].name, list[i].balance);
    } 
}

// Function to search a customer account.
int search(struct customer list[80], int s, int number) {

    int i;
    for (i = 0; i < s; i++) {
        if (list[i].account_no == number && list[i].status != 0)
            return i;
    }
    return  - 1;
}

// Function to deposit amount in an account.
void deposit(struct customer list[], int s, int number, int amt) {

    int i = search(list, s, number);
    if (i ==  - 1)
        printf("Record not found\n");
    else
        list[i].balance += amt;
}

// Function to withdraw amount from an account.
void withdraw(struct customer list[], int s, int number, int amt) {

    int i = search(list, s, number);
    if (i ==  - 1)
        printf("Record not found\n");
    else if (list[i].balance < amt)
        printf("Insufficient balance\n");
    else
        list[i].balance -= amt;
}

// Function to delete an account.
void delete(struct customer list[], int s, int number) {

    int i = search(list, s, number);
    if(i==-1)
        printf("Record not found\n");
    else {
        list[i].status = 0;
        printf("Record deleted\n");
    }
}