#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
private:
    std::string name;
    double balance;

public:
    Account();
    Account(std::string n);
    Account(std::string n, double b);

    void deposit(double amount);
    void withdraw(double amount);
    void show() const;
};

#endif
