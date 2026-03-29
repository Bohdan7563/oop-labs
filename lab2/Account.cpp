#include "Account.h"
#include <utility>

int Account::count = 0;

Account::Account() : Account("None", 0.0) {}

Account::Account(std::string n)
    : name(std::move(n)), balance(0.0), owner() {
    count++;
}

Account::Account(std::string n, double b)
    : name(std::move(n)), balance(b), owner() {
    count++;
}

Account::Account(const Account& other)
    : name(other.name), balance(other.balance), owner(other.owner) {
    count++;
    std::cout << "Copy constructor\n";
}

Account::Account(Account&& other) noexcept
    : name(std::move(other.name)),
      balance(other.balance),
      owner(std::move(other.owner)) {
    other.balance = 0;
    count++;
    std::cout << "Move constructor\n";
}

Account::~Account() {
    count--;
    std::cout << "Deleted: " << name << std::endl;
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= balance)
        balance -= amount;
    else
        std::cout << "Not enough money\n";
}

void Account::show() const {
    std::cout << name << " " << balance << " | owner: ";
    owner.show();
}

void Account::showCount() {
    std::cout << "Accounts: " << count << std::endl;
}

Account Account::operator+(const Account& other) const {
    return {"Sum", balance + other.balance};
}

Account Account::operator-() const {
    return {name, -balance};
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << acc.name << " " << acc.balance;
    return os;
}

std::istream& operator>>(std::istream& is, Account& acc) {
    is >> acc.name >> acc.balance;
    return is;
}