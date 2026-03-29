#include <iostream>
#include "Account.h"
#include "Client.h"
#include "PremiumClient.h"
#include "Transaction.h"

int main() {

    Client c1("Bohdan", 19);
    PremiumClient pc("VIP", 25, 1000);

    Account a1("Main", 1000);
    Account a2("Second");

    Transaction t1(500, "deposit");

    a1.deposit(200);
    a1.show();

    c1.show();
    pc.show();

    Account a3 = a1;
    Account a4 = std::move(a1);

    Account::showCount();

    return 0;
}