#include "Client.h"
#include <iostream>
#include <utility>

Client::Client() : Person("NoName"), age(18) {}

Client::Client(std::string n, int a) : Person(std::move(n)), age(a) {}

void Client::show() const {
    std::cout << "Client: " << name << ", age: " << age << "\n";
}

void Client::printRole() const {
    std::cout << "Role: Client\n";
}

void Client::work() const {
    std::cout << name << " uses bank services\n";
}