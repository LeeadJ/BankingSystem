#include "../include/Bank.h"
#include <iostream>

Bank::Bank() : m_users() {};

void Bank::addUser(const User& user){
    std::lock_guard<std::mutex> lock(m_mtx);

    // checking id user already exists
    for(const auto& u : m_users){
        if(u.getName() == user.getName() && u.getUserID() == user.getUserID()){
            std::cout << "addUser() Failed. User: " << user.getName() << " already exists." << std::endl;
            return;
        }
    }
    m_users.push_back(user);
}

User* Bank::getUser(std::string userName, int userID){
    for(auto& user : m_users){
        // std::cout << user.getName() << std::endl;
        if(user.getName() == userName && user.getUserID() == userID){
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
    std::cout << "Here getUser " << user_ptr->getName() << std::endl;
    std::cout << "Here getUser " << user_ptr->getUserID() << std::endl;
    std::cout << "Here getUser " << user_ptr->getAccount(accountNumebr)->getAccountNumber() << std::endl;

    if(user_ptr){
        for(auto& account : user_ptr->getAccounts()){
            if(accountNumebr == account.getAccountNumber()){
                std::cout << "Here getAccount: " << accountNumebr <<std::endl;

                return &account;
            }
        }
        //Account not found
        std::cout << "Cannot find account number: " << accountNumebr << " for user: " << userName << "." << std::endl;
    }
    // User not found
    else{
        std::cout << "Cannot find user: " << userName << " with ID: " << userID << "." << std::endl;
        return nullptr;
    }
    std::cout << "Here getAccount: Null Pointer" << std::endl;

    return nullptr;
}