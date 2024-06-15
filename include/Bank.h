#ifndef BANK_H
#define BANK_H

#include <vector>
#include <mutex>
#include "BankAccount.h"
#include "User.h"

class Bank {
    private:
        std::vector<User> m_users;
        mutable std::mutex m_mtx;

    public:
        Bank();
        void addUser(const User& user);
        User* getUser(std::string userName, int userID);
        BankAccount* getAccount(std::string userName, int userID, int accountNumebr);

};

#endif 