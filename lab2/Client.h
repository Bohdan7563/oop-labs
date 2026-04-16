#pragma once
#include "Person.h"

class Client : public Person {
protected:
    int age;
public:
    Client();
    Client(std::string n, int a = 18);
    ~Client() override;

    void show() const override;
    void printRole() const override;
    void work() const override; // реалізація pure virtual
};