#include <stdio.h> 
#include "myBank.h"

int main(){
    char operation_type = '0';
    int account_number = 0;
    double amount = 0;
    double interest_rate = 0;
    do
    {
        printf("\nPlease choose a transaction type:");
        printf("\n O-Open Account");
        printf("\n B-Balance Inquiry");
        printf("\n D-Deposit");
        printf("\n W-Withdrawal");
        printf("\n C-Close Accout");
        printf("\n I-Interest");
        printf("\n P-Print");
        printf("\n E-Exit");
        scanf(" %c", &operation_type);

        switch (operation_type)
        {
        case 'O':
            printf("\nPlease enter amount for deposit: ");
            int inO = scanf(" %lf", &amount);
            if(inO){
                openAccount(amount);
            }
            else{
                printf("Failed to read the amount");
            }
            break;
        case 'B':
            printf("\nPlease enter account number: ");
            int inB = scanf(" %d", &account_number);
            if(inB){
                checkBalance(account_number);
            }
            else{
                printf("Failed to read the account number");
            }
            break;
        case 'D':
            printf("\nPlease enter account number: ");
            int inD = scanf(" %d", &account_number);
            if(inD){
                printf("Please enter amount for deposit: ");
                int inD2 = scanf(" %lf", &amount);
                if(inD2){
                    deposit(account_number, amount);
                }
                else{
                    printf("Failed to read the amount");
                }
            }
            else{
                printf("Failed to read the account number");
            }
            break;
        case 'W':
            printf("\nPlease enter account number: ");
            int inW = scanf(" %d", &account_number);
            if(inW){
                printf("Please enter amount for withdraw: ");
                int inW = scanf(" %lf", &amount);
                if(inW){
                    withdraw(account_number, amount);
                }
                else{
                    printf("Failed to read the amount");
                }
            }
            else{
                printf("Failed to read the account number");
            }
            break;
        case 'C':
            printf("\nPlease enter account number: ");
            int inC = scanf(" %d", &account_number);
            if(inC){
                closeAccount(account_number);
            }
            else{
                printf("Failed to read the account number");
            }
            break;
        case 'I':
            printf("\nPlease enter interest rate: ");
            int inI = scanf(" %lf", &interest_rate);
            if(inI){
                addInterest(interest_rate);
            }
            else{
                printf("Failed to read the interest rate");
            }
            break;
        case 'P':
            printAccounts();
            break;
        case 'E':
            closeAllAccounts();
            break;
        default:
            printf("\nInvalid transaction type");
            break;
        }
        printf("\n");
    } while (operation_type != 'E');
    return 0;
}