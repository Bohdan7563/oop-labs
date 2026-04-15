#pragma once
#include "Client.h"

class PremiumClient : public Client {
private:
    double bonus;
public:
    PremiumClient();
    PremiumClient(std::string n, int a, double b);
    ~PremiumClient() override;
    void show() const override;
};