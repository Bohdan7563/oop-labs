#pragma once
#include "Client.h"

class PremiumClient final : public Client {
private:
    double bonus;
public:
    PremiumClient();
    PremiumClient(std::string n, int a, double b);
    ~PremiumClient() override = default;

    void show() const override;
    void printRole() const override;
    void work() const override;

    [[nodiscard]] double getBonus() const { return bonus; }
};