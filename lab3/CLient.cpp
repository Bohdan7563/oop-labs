#include "Client.h"
#include <iostream>

Client::Client() : name("NoName"), age(18) {}

Client::Client(std::string n, int a) : name(n), age(a) {}

Client::~Client() {
    std::cout << "Client deleted: " << name << std::endl;
}

void Client::show() const {
    std::cout << name << " " << age << std::endl;
}
