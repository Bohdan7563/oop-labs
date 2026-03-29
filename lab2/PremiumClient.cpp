#include "PremiumClient.h"
#include <iostream>

PremiumClient::PremiumClient() : Client(), bonus(0) {}

PremiumClient::PremiumClient(const std::string& n, int a, double b)
    : Client(n, a), bonus(b) {}

PremiumClient::~PremiumClient() {
    std::cout << "PremiumClient deleted\n";
}

void PremiumClient::show() const {
    std::cout << name << " " << age << " bonus: " << bonus << std::endl;
}