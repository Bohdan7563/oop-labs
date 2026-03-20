#include <iostream>
#include "Account.h"
#include "Client.h"
#include "Transaction.h"

int main() {

    Account a1("Main", 1000);
    Account a2("Second");

    Client c1("Bohdan", 19);
    Client c2;

    Transaction t1(500, "deposit");
    Transaction t2;

    a1.deposit(200);
    a1.withdraw(100);

    a1.show();
    a2.show();

    c1.show();
    c2.show();

    t1.show();
    t2.show();

    // copy
    Account a3 = a1;

    // move
    Account a4 = std::move(a1);

    // static
    Account::showCount();

    // operators
    Account sum = a2 + a3;
    sum.show();

    Account neg = -a2;
    neg.show();

    // <<
    std::cout << a2 << std::endl;

    // >>
    std::cin >> a2;
    a2.show();

    // const
    const Account a5("Const", 999);
    a5.show();

    return 0;
}