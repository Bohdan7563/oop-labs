#pragma once
#include <string>
#include <iostream>

class Transaction {
private:
    double amount;
    std::string type;
public:
    Transaction();
    Transaction(double a, std::string t = "none");
    ~Transaction();
    void show() const;
};