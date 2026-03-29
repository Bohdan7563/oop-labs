#include "Client.h"
#include <iostream>
#include <utility>

Client::Client() : Person("NoName"), age(18) {}

Client::Client(std::string n, int a)
    : Person(std::move(n)), age(a) {}

Client::Client(const Client& other)
    : Person(other.name), age(other.age) {
    std::cout << "Client copied\n";
}

Client::Client(Client&& other) noexcept
    : Person(std::move(other.name)), age(other.age) {
    std::cout << "Client moved\n";
}

Client::~Client() {
    std::cout << "Client deleted: " << name << std::endl;
}

void Client::show() const {
    std::cout << name << " " << age << std::endl;
}