#include "Client.h"
#include <iostream>

Client::Client() : name("NoName"), age(18) {}

Client::Client(std::string n, int a) : name(n), age(a) {}

void Client::show() const {
    std::cout << name << " " << age << std::endl;
}
