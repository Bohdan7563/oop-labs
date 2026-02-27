#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Account {
private:
    string name;
    double balance;

public:
    Account() : Account("None", 0.0) {}
    Account(string n) : Account(std::move(n), 0.0) {}
    Account(string n, double b) : name{std::move(n)}, balance{b} {}
    ~Account() = default;

    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) {
        if (amount <= balance) balance -= amount;
        else cout << "Not enough money" << endl;
    }
    void show() const { cout << name << " " << balance << endl; }
};

class Client {
private:
    string name;
    int age;

public:
    Client() : Client("NoName", 18) {}
    Client(string n, int a = 18) : name{std::move(n)}, age{a} {}
    ~Client() = default;
    void show() const { cout << name << " " << age << endl; }
};

class Transaction {
private:
    double amount;
    string type;

public:
    Transaction() : Transaction(0.0, "none") {}
    Transaction(double a, string t = "none") : amount{a}, type{std::move(t)} {}
    ~Transaction() = default;
    void show() const { cout << type << " " << amount << endl; }
};

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

    return 0;
}