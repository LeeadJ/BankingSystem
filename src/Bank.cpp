#include "Bank.h"
#include <iostream>

Bank::Bank() : m_users() {};

void Bank::addUser(const User& user){
    std::lock_guard<std::mutex> lock(m_mtx);

    // checking id user already exists
    for(const auto& u : m_users){
        if(u.getName() == user.getName() && u.getUserID() == user.getUserID()){
            std::cout << "Adduser Failes. User: " << user.getName() << " already exists." << std::endl;
            return;
        }
    }
    m_users.push_back(user);
}

User* Bank::getUser(std::string userName, int userID){
    std::lock_guard<std::mutex> lock(m_mtx);

    for(auto& user : m_users){
        if(user.getName() == userName && user.getUserID() == userID){
            std::cout << "Adduser Failes. User: " << user.getName() << " already exists." << std::endl;
            return &user;
        }
    }
    //User not found
    std::cout << "User with name: " << userName << " and ID: " << userID << " not found." << std::endl;
    return nullptr;
}

BankAccount* Bank::getAccount(std::string userName, int userID, int accountNumebr){
    std::lock_guard<std::mutex> lock(m_mtx);
    
    User* user_ptr = getUser(userName, userID);
    if(user_ptr){
        for(auto& account : user_ptr->getAccounts()){
            if(accountNumebr = account.getAccountNumber()){
                return &account;
            }
        }
    }
    // Bankaccount not found
    else{
        std::cout << "Cannot find account number: " << accountNumebr << " for acount user: " << userName << "." << std::endl;
        return nullptr;
    }
}