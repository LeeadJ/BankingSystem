# Bank System Project

This project implements a simple bank system using C++ with multithreading capabilities for deposit and withdrawal operations. The system includes functionality for managing users, accounts, transactions, and provides a basic command-line user interface (UI) for interaction.

## Table of Contents

- [Introduction](#introduction)
- [Project Structure](#project-structure)
- [Classes and Files](#classes-and-files)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Bank System project simulates a bank's backend operations with the following main functionalities:
- **User Management**: Adding users and associating bank accounts with users.
- **Account Management**: Creating bank accounts, depositing, and withdrawing funds.
- **Transaction Handling**: Recording transaction history for each bank account.
- **Concurrency**: Using mutex locks for thread safety during account operations.
- **User Interface**: A command-line interface (CLI) to interact with the bank functionalities.

The project is implemented in C++ and uses standard libraries for data structures, concurrency control, and input/output operations.

## Project Structure

The project is structured into several components:
- **Header Files**: Define class declarations and function prototypes.
- **Source Files**: Implementations for the defined classes and functions.
- **Main Program**: Entry point (`main.cpp`) for the command-line interface.

## Classes and Files

### Bank Class (`Bank.h`, `Bank.cpp`)

- Manages a collection of users (`std::vector<User>`) and provides methods to add users and retrieve user accounts.
- Uses mutex (`std::mutex`) for thread-safe operations on user data.

### User Class (`User.h`, `User.cpp`)

- Represents a bank user with a name, user ID, and a list of associated bank accounts (`std::vector<BankAccount>`).
- Provides methods to add accounts, retrieve accounts by account number, and access user information.

### BankAccount Class (`BankAccount.h`, `BankAccount.cpp`)

- Represents a bank account with an owner, account number, balance, and transaction history (`std::vector<TransactionDetails>`).
- Supports deposit, withdrawal, and retrieval of account information.
- Utilizes mutex for thread-safe operations on account data.

### Transaction Functions (`Transaction.h`, `Transaction.cpp`)

- Functions for simulating deposit and withdrawal activities on a bank account.
- Includes a function to simulate concurrent user activities using threads.

### UserInterface Class (`UserInterface.h`, `UserInterface.cpp`)

- Provides a CLI interface to interact with the bank functionalities.
- Includes menu options to add users, add accounts, simulate user activity, and display user accounts.

## Usage

To use the bank system:
1. Compile the source files using a C++ compiler (e.g., g++).
2. Execute the compiled program to run the command-line interface.
3. Follow the prompts to perform operations such as adding users, creating accounts, and simulating user activities.

Example commands:
```sh
g++ -std=c++20 -Wall -Wextra -Iinclude src/*.cpp -o bank_system
./bank_system
