#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <mutex>
#include <vector>


struct TransactionDetails {
    enum class Type {
        DEPOSIT,
        WITHDRAW,
    };
    Type typeOfTransaction;
    std::string transactionDate;
    double transactionAmount;
    double balanaceBeforeTransaction;
    double balanceAfterTransaction;
};

class BankAccount {
    private:
        static int nextAccountNumber;
        std::string m_owner;
        int m_accountNumber;
        double m_balance;
        std::vector<TransactionDetails> m_transactionHistory;
        mutable std::mutex m_mtx;

    public:
        BankAccount(const std::string& owner, double balance);
        void deposit(double amount);
        bool withdraw(double amount);
        double getBalance() const;
        int getAccountNumber() const;
        std::string getOwner() const;
        std::string getDateString() const;
        std::vector<TransactionDetails> getTransactionHistory() const;

};

#endif BANKACCOUNT_H