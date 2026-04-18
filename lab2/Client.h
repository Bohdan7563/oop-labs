#pragma once
#include "Person.h"

class Client : public Person {
protected:
    int age;
public:
    Client();
    explicit Client(std::string n, int a = 18);
    ~Client() override = default;

    void show() const override;
    void printRole() const override;
    void work() const override;

    [[nodiscard]] int getAge() const { return age; }
};