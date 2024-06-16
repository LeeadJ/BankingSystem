#include "../include/Bank.h"
#include "../include/BankAccount.h"
#include "../include/User.h"
#include <iostream>

int main() {
    Bank bank;

    // Create and add users
    User user1("Alice", 1);
    User user2("Bob", 2);
    User user3("Charlie", 3);

    bank.addUser(user1);
    bank.addUser(user2);
    bank.addUser(user3);

    // Display user details
    std::cout << "User Name: " << user1.getName() << std::endl;
    std::cout << "User ID: " << user1.getUserID() << std::endl;

    std::cout << "User Name: " << user2.getName() << std::endl;
    std::cout << "User ID: " << user2.getUserID() << std::endl;

    std::cout << "User Name: " << user3.getName() << std::endl;
    std::cout << "User ID: " << user3.getUserID() << std::endl;

    // Attempt to add a duplicate user
    bank.addUser(user1); // Should fail and print a message

    // Retrieve and display user details
    User* retrievedUser = bank.getUser("Alice", 1);
    if (retrievedUser) {
        std::cout << "Retrieved User: " << retrievedUser->getName() << ", ID: " << retrievedUser->getUserID() << std::endl;
    } else {
        std::cout << "User not found!" << std::endl;
    }

    // Add bank accounts to the users
    BankAccount account1(user1.getName(), 1000.0);
    user1.addAccount(account1);

    BankAccount account2(user2.getName(), 2000.0);
    user2.addAccount(account2);

    BankAccount account3(user3.getName(), 3000.0);
    user3.addAccount(account3);
    

    // Print user account details
    std::cout << "User " << user1.getName() << " added an account with balance: " << account1.getBalance() << std::endl;
    std::cout << "User " << user2.getName() << " added an account with balance: " << account2.getBalance() << std::endl;
    std::cout << "User " << user3.getName() << " added an account with balance: " << account3.getBalance() << std::endl;

    std::cout << "Here Main" << std::endl;


    // Retrieve and display account details
    BankAccount* retrievedAccount = bank.getAccount("Alice", 1, account1.getAccountNumber());
    std::cout << "Here" <<  retrievedAccount << std::endl;
    if (retrievedAccount) {
        std::cout << "Retrieved Account Number: " << retrievedAccount->getAccountNumber() << std::endl;
        std::cout << "Account Balance: " << retrievedAccount->getBalance() << std::endl;
    } else {
        std::cout << "Account not found!" << std::endl;
    }

    // Attempt to retrieve a non-existent account
    BankAccount* nonExistentAccount = bank.getAccount("Alice", 1, 999999);
    if (nonExistentAccount) {
        std::cout << "Retrieved Account Number: " << nonExistentAccount->getAccountNumber() << std::endl;
    } else {
        std::cout << "Account number: 999999 not found." << std::endl;
    }

    // Attempt to retrieve a non-existent user
    User* nonExistentUser = bank.getUser("Dave", 4);
    if (nonExistentUser) {
        std::cout << "Retrieved User: " << nonExistentUser->getName() << ", ID: " << nonExistentUser->getUserID() << std::endl;
    } else {
        std::cout << "User with name: Dave and ID: 4 not found." << std::endl;
    }

    return 0;
}
