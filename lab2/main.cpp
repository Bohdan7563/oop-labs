#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string name;
    double balance;

public:
    Account() : Account("None", 0.0) {}

    Account(string n) : Account(n, 0.0) {}

    Account(string n, double b) : name{n}, balance{b} {}

    ~Account() {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
    }

    void show() {
        cout << name << " " << balance << endl;
    }
};

class Client {
private:
    string name;
    int age;

public:
    Client() : Client("NoName", 18) {}

    Client(string n, int a = 18) : name{n}, age{a} {}

    ~Client() {}

    void show() {
        cout << name << " " << age << endl;
    }
};

class Transaction {
private:
    double amount;
    string type;

public:
    Transaction() : Transaction(0.0, "none") {}

    Transaction(double a, string t = "none") : amount{a}, type{t} {}

    ~Transaction() {}

    void show() {
        cout << type << " " << amount << endl;
    }
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
