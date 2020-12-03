#include <stdio.h>
#include "myBank.h"

#define ACCOUNT_NUM 0
#define CASH_AMOUNT 1 
#define FIRST_ACCOUNT 901
#define LAST_ACCOUNT 950
#define MY_BANK_SIZE 50

double MY_BANK_ACCOUNTS [MY_BANK_SIZE][2];

void openAccount(double amount){
    if(amount > 0){
        int i = 0;
        for(; i < MY_BANK_SIZE; i++){
            if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == 0){
                MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] = i + FIRST_ACCOUNT;
                MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = amount;
                printf("New account number is: %d \n", i + FIRST_ACCOUNT);
                break;
            }
        }
        if(i == MY_BANK_SIZE){
            printf ("Unable to open account, the bank is full\n");
        }
        return;
    }
    printf("Failed to read the amount\n");
}

void checkBalance(int account_number){
    if(account_number >= 901 && account_number <= 950){
        int i= account_number-900-1;
        if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number){
            double balance = MY_BANK_ACCOUNTS[i][CASH_AMOUNT];
            printf("The balance of account number %d is: %0.2lf\n", account_number, balance);
        } else{
            printf("This account is closed\n");
        }
        return;
    }
    printf("Failed to read the account number\n");
}

void deposit(int account_number, double amount){
    if(account_number >= 901 || account_number <= 950){
        int i= account_number-900-1;
        if(amount < 0) {
            printf ("Failed to read the amount\n");
        }
        else if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number){
            MY_BANK_ACCOUNTS[i][CASH_AMOUNT] += amount;
            double balance = MY_BANK_ACCOUNTS[i][CASH_AMOUNT];
            printf("The new balance is: %0.2lf \n", balance);
        }
        else{
            printf("Failed to read the amount\n");
        }
        return;
    }
    printf("Failed to read the account number\n");
}

void withdraw(int account_number, double amount){
    if(amount < 0) {
        printf ("Failed to read the amount\n");
        return;
    }
    if(account_number >= 901 && account_number <= 950){
        int i= account_number-900-1;
        if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] != account_number){
            printf("Failed to read the account number\n");
            return;
        }
        if((MY_BANK_ACCOUNTS[i][CASH_AMOUNT] - amount) < 0 ){
            printf("Cannot withdraw more than the balance\n");
            return;
        }
        MY_BANK_ACCOUNTS[i][CASH_AMOUNT] -= amount;
        double balance = MY_BANK_ACCOUNTS[i][CASH_AMOUNT];
        printf("The new balance is: %0.2lf\n", balance);
        return;
    }
    printf("Failed to read the account number\n");
}

void closeAccount(int account_number){ 
    if(account_number >= 901 && account_number <= 950){
        int i= account_number-900-1;
        if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number){
            MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] = 0;
            MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = 0;
            printf("The account number %d closed successfully\n", account_number);
            return;
        }
    }
    printf("Failed to read the account number\n");
}

void addInterest(int interest_rate){
    if(interest_rate < -99){
        printf("Invalid interest rate\n");
        return;
    }
    int interest = 0;
    for (int i = 0; i < MY_BANK_SIZE; i++){
        if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] != 0){
            interest = (interest_rate/100)*MY_BANK_ACCOUNTS[i][CASH_AMOUNT];
            MY_BANK_ACCOUNTS[i][CASH_AMOUNT] += interest;
        }
        interest = 0;
    }
}

void printAccounts(){
    int num = 0;
    double balance = 0;
    for (int i = 0; i < MY_BANK_SIZE; i++){
        if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] != 0){
            num = MY_BANK_ACCOUNTS[i][ACCOUNT_NUM];
            balance = MY_BANK_ACCOUNTS[i][CASH_AMOUNT];
            printf("\nThe balance of account number %d is: %0.2lf", num, balance);
        } 
    }
    printf("\n");
}

void closeAllAccounts(){
    for (int i = 0; i < MY_BANK_SIZE; i++){
        MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] = 0;
        MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = 0;
    }
}