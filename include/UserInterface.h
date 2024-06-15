#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Bank.h"

class UserInterface{
    private:
        Bank& m_bank;

    public:
        UserInterface(Bank& bank);
        void displayMenu();
        void handleUserInput();
};

#endif