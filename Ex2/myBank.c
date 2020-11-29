#include <stdio.h>
#include "myBank.h"

double MY_BANK_ACCOUNTS [MY_BANK_SIZE][2];
//add to myBank.h?
float two_digits_after_point(double amount){
return (long)(amount * 100) / 100.0;
}

void openAccount(double amount){
if(amount < 0) {
printf ("/nError! unable to open account with negative amount of cash");
return;
}
if(MY_BANK_ACCOUNTS[MY_BANK_SIZE-1][ACCOUNT_NUM] == 0){
    for(int i = 0; i < MY_BANK_SIZE; i++){
        if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] != 0){
        MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] = i + FIRST_ACCOUNT;
        MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = two_digits_after_point(amount);
        printf("/nThe number of the new account is %d", i + FIRST_ACCOUNT);
        }
    }
}else {
printf ("/nUnable to open account, the bank is full");
}

void checkBalance(int account_number){
   // if(account_number < 901 || account_number > 950)
   // printf("/nError! the account is not exist")
 for (int i = 0; i < MY_BANK_SIZE; i++)
 {
    if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number){
        printf("/nThe balance is %lf ", MY_BANK_ACCOUNTS[i][CASH_AMOUNT]);
        return;
    }
 }
 printf("/nError! the account is not exist");
}

void deposit(int account_number, double amount){
      if(amount < 0) {
        printf ("/nError! unable to deposit negative amount of cash");
        return;
     for (int i = 0; i < MY_BANK_SIZE; i++){
    if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number){
        MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = MY_BANK_ACCOUNTS[i][CASH_AMOUNT] + two_digits_after_point(amount);
        printf("/nThe deposit was made successfully, the new balance is %lf ", MY_BANK_ACCOUNTS[i][CASH_AMOUNT]);
        return;
    }
 }
 printf("/nError! the account is not exist");
}

void withdraw(int account_number, double amount){
    if(amount < 0) {
    printf ("/nError! unable to withdraw negative amount of cash");
    return;
      for (int i = 0; i < MY_BANK_SIZE; i++){
    if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number && (MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] - amount) >= 0 ){
        MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = MY_BANK_ACCOUNTS[i][CASH_AMOUNT] - two_digits_after_point(amount);
        printf("/nThe balance now is %lf ", MY_BANK_ACCOUNTS[i][CASH_AMOUNT]);
        return;
    }
    if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number && (MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] - two_digits_after_point(amount)) < 0){
        printf("/nThere is not enough cash to withdraw");
        return;
    }
 }
 printf("/nError! the account is not exist");
}

void closeAccount(int account_number){ 
for (int i = 0; i < MY_BANK_SIZE; i++)
{
    if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] == account_number){
        MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] = 0;
        MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = 0;
        printf("The account number %d closed successfully", account_number);
        return;
    }
}
printf("/nError! unable to close non-existent account");
}

void addInterest(float interest_rate){
    if(interest_rate < -99 || interest_rate > 99){
         printf("/nInvalid interest rate");
         return; 
    }
    float interest = 0;
    for (int i = 0; i < MY_BANK_SIZE; i++)
    {
        if(MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] != 0){
             interest = (interest_rate/100)*MY_BANK_ACCOUNTS[i][CASH_AMOUNT];
             MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = MY_BANK_ACCOUNTS[i][CASH_AMOUNT] + two_digits_after_point(interest);
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
                printf("/n Account number: %d, balance: %lf", num, balance);
            } 
        }  
    }
}

void closeAllAccounts(){
    for (int i = 0; i < MY_BANK_SIZE; i++)
    {
        MY_BANK_ACCOUNTS[i][ACCOUNT_NUM] = 0;
        MY_BANK_ACCOUNTS[i][CASH_AMOUNT] = 0;
    }
}


