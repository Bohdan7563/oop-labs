#pragma once
#include "Client.h"

class PremiumClient final : public Client { // ✅ final
private:
    double bonus;
public:
    PremiumClient();
    PremiumClient(std::string n, int a, double b);
    ~PremiumClient() override;

    void show() const override;
    void printRole() const override;
    void work() const override;
};