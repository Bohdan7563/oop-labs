#pragma once
#include <string>

class Transaction {
private:
    std::string accName;
    double amount;
    std::string type;
public:
    Transaction();
    Transaction(std::string acc, double a, std::string t);
    ~Transaction() = default;

    void show() const;

    [[nodiscard]] std::string getAccName() const { return accName; }
    [[nodiscard]] double getAmount() const { return amount; }
    [[nodiscard]] std::string getType() const { return type; }
};