#include "Account.h"
#include <utility>   // для std::move

int Account::count = 0;

// constructors
Account::Account() : Account("None", 0.0) {}

// передача за значенням + std::move
Account::Account(std::string n) : name(std::move(n)), balance(0.0) {
    count++;
}

Account::Account(std::string n, double b) : name(std::move(n)), balance(b) {
    count++;
}

// copy constructor
Account::Account(const Account& other) {
    name = other.name;
    balance = other.balance;
    count++;
    std::cout << "Copy constructor\n";
}

// move constructor (noexcept)
Account::Account(Account&& other) noexcept {
    name = std::move(other.name);
    balance = other.balance;
    other.balance = 0;
    count++;
    std::cout << "Move constructor\n";
}

// destructor
Account::~Account() {
    count--;
    std::cout << "Deleted: " << name << std::endl;
}

void Account::deposit(double amount) {
    this->balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= this->balance)
        this->balance -= amount;
    else
        std::cout << "Not enough money" << std::endl;
}

void Account::show() const {
    std::cout << this->name << " " << this->balance << std::endl;
}

void Account::showCount() {
    std::cout << "Accounts: " << count << std::endl;
}

// binary operator+ (const)
Account Account::operator+(const Account& other) const {
    // використовуємо braced initializer list
    return {"Sum", this->balance + other.balance};
}

// unary operator- (const)
Account Account::operator-() const {
    // використовуємо braced initializer list
    return {this->name, -this->balance};
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << acc.name << " " << acc.balance;
    return os;
}

std::istream& operator>>(std::istream& is, Account& acc) {
    is >> acc.name >> acc.balance;
    return is;
}