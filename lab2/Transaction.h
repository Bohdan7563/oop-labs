#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    double amount;
    std::string type;

public:
    Transaction();
    Transaction(double a, std::string t = "none");

    void show() const;
};

#endif
