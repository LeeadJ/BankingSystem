#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "BankAccount.h"

void depositMoney(BankAccount& account, double amount, int times);
void withdrawMoney(Bankaccount& account, double amount, int times);
void simulateUserActivity(BankAccount& account, int numDeposits, int numWithdrawals);


#endif