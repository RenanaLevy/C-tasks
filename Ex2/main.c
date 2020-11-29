#include <stdio.h> 
#include "myBank.h"

int main(){

    char operation_type = 0;
printf("\nWelcome to my bank!, choose an operation please:");
printf("\nInsert 'O' for opening a bank account");
printf("\nInsert 'B' for checking balance");
printf("\nInsert 'D' for deposing to the account");
printf("\nInsert 'W' for withdraw from the account");
printf("\nInsert 'C' for closing the account");
printf("\nInsert 'I' for adding interest at percentage rate to all open accounts");
printf("\nInsert 'P' for printing all the open accounts and their balance");
printf("\nInsert 'E' for closing all the accounts and exit the program");
scanf(" %c", &operation_type);

int account_number = 0;
float amount = 0;
float interest_rate = 0;
do
{
    switch (operation_type)
    {
    case 'O':
        printf("Initial deposit?:");
        openAccount(scanf("%lf", &amount));
        break;
    case 'B':
        printf("Account number?:");
        checkBalance(scanf("%d", &account_number));
        break;
    case 'D':
        printf("Account number?:");
        scanf("%d", &account_number);
        printf("Amount?:");
        scanf("%lf", &amount);
        deposit(account_number, amount);
        break;
    case 'W':
         printf("Account number?:");
        scanf("%d", &account_number);
        printf("Amount?:");
        scanf("%lf", &amount);
        withdraw(account_number, amount);
        break;
    case 'C':
        printf("Account number?:");
        scanf("%d", &account_number);
        closeAccount(account_number);
        break;
    case 'I':
        printf("Interest rate?:");
        scanf("%f", &interest_rate);
        addInterest(interest_rate);
        break;
    case 'P':
        printAccounts();
        break;
    case 'E':
        closeAllAccounts();
        break;
    default:
        ("Error! you can only insert O,B,D,W,C,I,P,E");
    }
} while (operation_type != 'E');

return 0;
}