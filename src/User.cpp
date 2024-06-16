#include "../include/User.h"
#include <iostream>

User::User(const std::string& name, int userID) 
    : m_name(name), m_userID(userID), m_accounts() {};

User::User(const User& other) : m_name(other.m_name), m_userID(other.m_userID), m_accounts(other.m_accounts) {}

void User::addAccount(const BankAccount& account){
    std::lock_guard<std::mutex> lock(m_mtx);
    m_accounts.push_back(account);
}

BankAccount* User::getAccount(int accountNumber){
    std::lock_guard<std::mutex> lock(m_mtx);
    std::cout << "Wanted account number: " << accountNumber << std::endl;
    std::cout << "Accounts: " << this->m_accounts.size() << std::endl;
    for(auto& account : m_accounts){
        std::cout << "Current Loop Acount number: " << account.getAccountNumber() << std::endl;
        if(account.getAccountNumber() == accountNumber){
            return &account;
        }
    }

    // account number not found
    std::cout << "Account numebr: " << accountNumber << " not found." << std::endl;
    return nullptr;
}

std::string User::getName() const {return m_name;}

int User::getUserID() const {return m_userID;}

std::vector<BankAccount>& User::getAccounts(){
    std::lock_guard<std::mutex> lock(m_mtx);
    return m_accounts;

}