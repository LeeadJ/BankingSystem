#include "Transaction.h"
#include <thread>
#include <chrono>

void depositMoney(BankAccount& account, double amount, int times) {
    for (int i = 0; i < times; ++i) {
        account.deposit(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void withdrawMoney(BankAccount& account, double amount, int times) {
    for (int i = 0; i < times; ++i) {
        account.withdraw(amount);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

void simulateUserActivity(BankAccount& account, int numDeposits, int numWithdrawals) {
    std::thread depositThread(depositMoney, std::ref(account), 50.0, numDeposits);
    std::thread withdrawThread(withdrawMoney, std::ref(account), 30.0, numWithdrawals);

    depositThread.join();
    withdrawThread.join();
}
