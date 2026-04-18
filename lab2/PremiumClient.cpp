#include "PremiumClient.h"
#include <iostream>
#include <utility>

PremiumClient::PremiumClient() : Client(), bonus(0.0) {}

PremiumClient::PremiumClient(std::string n, int a, double b)
    : Client(std::move(n), a), bonus(b) {}

void PremiumClient::show() const {
    std::cout << "PremiumClient: " << name
              << ", age: " << age
              << ", bonus: " << bonus << "\n";
}

void PremiumClient::printRole() const {
    std::cout << "Role: PremiumClient\n";
}

void PremiumClient::work() const {
    std::cout << name << " uses premium banking\n";
}