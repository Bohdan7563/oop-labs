#include <iostream>
#include "Account.h"
#include "Client.h"
#include "PremiumClient.h"
#include "Transaction.h"

int main() {

    std::cout << "=== create objects ===\n";
    Client c1("Bohdan", 19);
    PremiumClient pc("Alice", 25, 500.0);
    Account a1("Main", 1000);
    Account a2("Second");
    Transaction t1(200.0, "deposit");
    Transaction t2;

    std::cout << "\n=== show ===\n";
    a1.deposit(200);
    a1.withdraw(100);
    a1.show();
    a2.show();
    t1.show();
    t2.show();

    std::cout << "\n=== polymorphism ===\n";
    Person* p = &c1;
    p->show();
    p = &pc;
    p->show();

    std::cout << "\n=== copy and move Account ===\n";
    Account a3 = a1;
    Account a4 = std::move(a1);
    Account::showCount();

    std::cout << "\n=== copy and move operator= Client ===\n";
    Client c2;
    c2 = c1;
    Client c3;
    c3 = std::move(c2);

    std::cout << "\n=== operators ===\n";
    Account sum = a2 + a3;
    sum.show();
    Account neg = -a3;
    neg.show();
    std::cout << a3 << "\n";

    std::cout << "\n=== destructors ===\n";
    return 0;
}