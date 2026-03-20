#include "Client.h"
#include <iostream>
#include <utility>

Client::Client() : name("NoName"), age(18) {}

Client::Client(std::string n, int a) : name(std::move(n)), age(a) {}

Client::~Client() {
    std::cout << "Client deleted: " << name << std::endl;
}

void Client::show() const {
    std::cout << name << " " << age << std::endl;
}