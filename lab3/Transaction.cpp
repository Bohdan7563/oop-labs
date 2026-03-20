#include "Transaction.h"
#include <utility>

Transaction::Transaction() : amount(0.0), type("none") {}

Transaction::Transaction(double a, std::string t) : amount(a), type(std::move(t)) {}

Transaction::~Transaction() {
    std::cout << "Transaction deleted\n";
}

void Transaction::show() const {
    std::cout << type << " " << amount << std::endl;
}