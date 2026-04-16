#include <iostream>
#include "Client.h"
#include "PremiumClient.h"

int main() {

    std::cout << "=== STATIC BINDING ===\n";
    Client c1("Bohdan", 19);

    Person* p = &c1;

    p->info();  // ❌ static binding
    p->show();  // ✅ dynamic binding

    std::cout << "\n=== DYNAMIC POLYMORPHISM (pointer) ===\n";

    PremiumClient pc("Alice", 25, 500);
    p = &pc;

    p->show();
    p->printRole();
    p->work();

    std::cout << "\n=== DYNAMIC POLYMORPHISM (reference) ===\n";

    Person& ref = pc;
    ref.show();
    ref.work();

    std::cout << "\n=== END ===\n";
    return 0;
}