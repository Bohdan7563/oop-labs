#include "Transaction.h"
#include <iostream>
#include <utility>

Transaction::Transaction() : accName("None"), amount(0.0), type("none") {}

Transaction::Transaction(std::string acc, double a, std::string t)
    : accName(std::move(acc)), amount(a), type(std::move(t)) {}

void Transaction::show() const {
    std::cout << "Account: " << accName << " | Transaction: " << type << " | Amount: " << amount << "\n";
}