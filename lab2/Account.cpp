#include "Account.h"
#include "Client.h"
#include <stdexcept>
#include <utility>

int Account::count = 0;

Account::Account() : name("None"), balance(0.0), owner(std::make_shared<Client>()) {
    count++;
}

Account::Account(std::string n)
    : name(std::move(n)), balance(0.0), owner(std::make_shared<Client>()) {
    count++;
}

Account::Account(std::string n, double b, std::shared_ptr<Person> p)
    : name(std::move(n)), balance(b), owner(std::move(p)) {
    count++;
}

Account::Account(const Account& other)
    : name(other.name), balance(other.balance), owner(other.owner) {
    count++;
}

Account::Account(Account&& other) noexcept
    : name(std::move(other.name)),
      balance(other.balance),
      owner(std::move(other.owner)) {
    other.balance = 0.0;
    count++;
}

Account::~Account() {
    count--;
}

void Account::deposit(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Deposit amount must be greater than zero.");
    }
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= 0) {
        throw std::invalid_argument("Withdraw amount must be greater than zero.");
    }
    if (amount > balance) {
        throw std::runtime_error("Not enough money on balance.");
    }
    balance -= amount;
}

void Account::show() const {
    std::cout << "Account: " << name << " | Balance: " << balance << "\n";
}

void Account::showCount() {
    std::cout << "Total accounts: " << count << "\n";
}

Account Account::operator+(const Account& other) const {
    return {"Sum", balance + other.balance, owner};
}

Account Account::operator-() const {
    return {name, -balance, owner};
}

std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << "Account: " << acc.name << ", balance: " << acc.balance;
    return os;
}

std::istream& operator>>(std::istream& is, Account& acc) {
    is >> acc.name >> acc.balance;
    return is;
}