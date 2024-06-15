#include "UserInterface.h"
#include "Transaction.h"
#include <iostream>
#include <string>

UserInterface::UserInterface(Bank& bank) : m_bank(bank) {}

void UserInterface::displayMenu(){
    std::cout << "1. Add User" << std::endl;
    std::cout << "2. Add Account to User" << std::endl;
    std::cout << "3. Simulate User Activity" << std::endl;
    std::cout << "4. Display User Accounts" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void UserInterface::handleUserInput() {
    int userChoise;
    while(true){
        displayMenu();
        std::cin >> userChoise;

        switch(userChoise){
            case 1: {
                std::string name;
                int userID;
                std::cout << "Enter user name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                m_bank.addUser(User(name, userID));
                break;
            }
            case 2: {
                std::string name;
                int userID;
                double initialBalance;
                std::cout << "Enter user name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                m_bank.getUser(name, userID)->addAccount(BankAccount(name));
                break;      
            }
            case 3: {
                std::string name;
                int userID, accountNumber;
                std::cout << "Enter user name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                int numDeposits, numWithdrawals;
                std::cout << "Enter number of deposits: ";
                std::cin >> numDeposits;
                std::cout << "Enter number of withdrawals: ";
                std::cin >> numWithdrawals;
                BankAccount* account = m_bank.getAccount(name, userID, accountNumber);
                if (account) {
                    simulateUserActivity(*account, numDeposits, numWithdrawals); 
                } 
                else {
                    std::cout << "Failed to find the account." << std::endl;
                }
                break;
            }
            case 4: {
                std::string name;
                int userID;
                double initialBalance;
                std::cout << "Enter user name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, name);
                std::cout << "Enter user ID: ";
                std::cin >> userID;
                User* user = m_bank.getUser(name, userID);
                if(user){
                    if(user->getAccounts().size() > 0){
                        double totalBalance=0;
                        for(auto& account : user->getAccounts()){
                            std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
                            std::cout << "Account Owner: " << account.getOwner() << std::endl;
                            std::cout << "Account Balance: " << account.getBalance() << std::endl;
                            totalBalance += account.getBalance();
                        }
                        std::cout << "Total balance across all acounts: " << totalBalance << std::endl;
                    }
                    else{
                        std::cout << "User has no accounts" << std::endl;
                    }
                    
                }
                break;
            }
            case 5: {
                return;
            }
            default:
                std::cout << "Invalid choice" << std::endl;

                
        }
    }
}
