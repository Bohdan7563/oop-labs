#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

class Account {
private:
    std::string name;
    double balance;

public:
    Account();
    Account(std::string n);               // передача за значенням
    Account(std::string n, double b);     // передача за значенням

    // copy constructor
    Account(const Account& other);

    // move constructor (noexcept)
    Account(Account&& other) noexcept;

    // destructor
    ~Account();

    void deposit(double amount);
    void withdraw(double amount);
    void show() const;

    // static
    static int count;
    static void showCount();

    // operators (const versions)
    Account operator+(const Account& other) const;
    Account operator-() const;

    // stream operators
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);
    friend std::istream& operator>>(std::istream& is, Account& acc);
};

#endif