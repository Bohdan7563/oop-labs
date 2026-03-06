#include "Account.h"
#include <iostream>

Account::Account() : name("None"), balance(0.0) {}

Account::Account(std::string n) : name(n), balance(0.0) {}

Account::Account(std::string n, double b) : name(n), balance(b) {}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= balance)
        balance -= amount;
    else
        std::cout << "Not enough money" << std::endl;
}

void Account::show() const {
    std::cout << name << " " << balance << std::endl;
}
