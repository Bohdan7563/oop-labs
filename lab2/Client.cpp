#include "Client.h"
#include <utility>

Client::Client() : Person("NoName"), age(18) {}

Client::Client(std::string n, int a) : Person(std::move(n)), age(a) {}

Client::Client(const Client& other) : Person(other), age(other.age) {
    std::cout << "Client copy constructor\n";
}

Client::Client(Client&& other) noexcept : Person(std::move(other)), age(other.age) {
    std::cout << "Client move constructor\n";
}

Client& Client::operator=(const Client& other) {
    if (this == &other) return *this;
    Person::operator=(other);
    age = other.age;
    std::cout << "Client copy operator=\n";
    return *this;
}

Client& Client::operator=(Client&& other) noexcept {
    if (this == &other) return *this;
    Person::operator=(std::move(other));
    age = other.age;
    std::cout << "Client move operator=\n";
    return *this;
}

Client::~Client() {
    std::cout << "Client deleted: " << name << "\n";
}

void Client::show() const {
    std::cout << "Client: " << name << ", age: " << age << "\n";
}