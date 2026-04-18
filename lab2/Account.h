#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "Person.h"

class Account {
private:
    std::string name;
    double balance;
    std::shared_ptr<Person> owner;
public:
    Account();
    explicit Account(std::string n);
    Account(std::string n, double b, std::shared_ptr<Person> p);
    Account(const Account& other);
    Account(Account&& other) noexcept;
    ~Account();

    void deposit(double amount);
    void withdraw(double amount);
    void show() const;

    static int count;
    static void showCount();

    [[nodiscard]] std::string getName() const { return name; }
    [[nodiscard]] double getBalance() const { return balance; }
    [[nodiscard]] std::shared_ptr<Person> getOwner() const { return owner; }

    Account operator+(const Account& other) const;
    Account operator-() const;
    friend std::ostream& operator<<(std::ostream& os, const Account& acc);
    friend std::istream& operator>>(std::istream& is, Account& acc);
};