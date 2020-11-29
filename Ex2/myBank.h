#ifndef MY_BANK 
#define MY_BANK
#define MY_BANK_SIZE 50
#define ACCOUNT_NUM 0
#define CASH_AMOUNT 1 
#define FIRST_ACCOUNT 901
#define LAST_ACCOUNT 950

extern double MY_BANK_ACCOUNTS [MY_BANK_SIZE][2];

void openAccount(double amount);
void checkBalance(int account_number);
void deposit(int account_number, double amount);
void withdraw(int account_number, double amount);
void closeAccount(int account_number);
void addInterest(float interest_rate);
void printAccounts();
void closeAllAccounts();

#endif 


