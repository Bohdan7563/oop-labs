#include "Transaction.h"
#include <iostream>

Transaction::Transaction() : amount(0.0), type("none") {}

Transaction::Transaction(double a, std::string t) : amount(a), type(t) {}

void Transaction::show() const {
    std::cout << type << " " << amount << std::endl;
}
