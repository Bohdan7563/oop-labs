#pragma once
#include "Person.h"

class Client : public Person {
protected:
    int age;
public:
    Client();
    Client(std::string n, int a = 18);
    Client(const Client& other);
    Client(Client&& other) noexcept;
    Client& operator=(const Client& other);
    Client& operator=(Client&& other) noexcept;
    ~Client() override;
    void show() const override;
};