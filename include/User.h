#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "BankAccount.h"
#include <mutex>

class User {
    private:
        std::string m_name;
        int m_userID;
        std::vector<BankAccount> m_accounts;
        mutable std::mutex m_mtx;

    public:
        User(const std::string& name, int userID);
        void addAccount(const BankAccount& account);
        BankAccount* getAccount(int accountNumebr);
        std::string getName() const;
        int getUserID() const;
        std::vector<BankAccount>& getAccounts();
};

#endif 