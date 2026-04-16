#pragma once
#include <string>
#include <iostream>
#include "Client.h"

class Account {
private:
    std::string name;
    double balance;
    Client owner;  // композиція
public:
    Account();
    Account(std::string n);
    Account(std::string n, double b);
    Account(const Account& other);
    Account(Account&& other) noexcept;
    ~Account();
    void deposit(double amount);
    void withdraw(double amount);
    void show() const;
    static int count;
    static void showCount();
    Account operator+(const Account& other) const;
    Account operator-() const;
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);
    friend std::istream& operator>>(std::istream& is, Account& acc);
};