#include "BankAccount.h"
#include <chrono>
#include <ctime>


BankAccount::BankAccount(const std::string& owner, double balance) 
    : m_owner(owner), m_balance(balance){}

void BankAccount::deposit(double amount){
    std::lock_guard<std::mutex> lock(m_mtx);

    m_transactionHistory.push_back({
        TransactionDetails::Type::DEPOSIT,
        getDateString(),
        amount,
        m_balance,
        m_balance + amount
    });

    m_balance += amount;
}

bool BankAccount::withdraw(double amount) {
    std::lock_guard<std::mutex> lock(m_mtx);

    if(amount <= m_balance){ // withdraw ok
        m_transactionHistory.push_back({
            TransactionDetails::Type::WITHDRAW,
            getDateString(),
            amount,
            m_balance,
            m_balance - amount
        });
        m_balance -= amount;
        return true;
    }
    return false; // withdraw not allowed   
}

double BankAccount::getBalance() const {
    std::lock_guard<std::mutex> lock(m_mtx);
    return m_balance;
}

std::string BankAccount::getOwner() const {
    std::lock_guard<std::mutex> lock(m_mtx);
    return m_owner;
}

std::vector<TransactionDetails> BankAccount::getTransactionHistory() const {
    std::lock_guard<std::mutex> lock(m_mtx);
    return m_transactionHistory;

}

std::string BankAccount::getDateString() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&now_c); // Convert time to string
}