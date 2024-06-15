#include "Bank.h"
#include "UserInterface.h"
#include <iostream>

int main() {
    Bank bank;

    UserInterface userInterface(bank);
    userInterface.handleUserInput();

    return 0;
}
