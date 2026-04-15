#include "Person.h"
#include <utility>

Person::Person() : name("NoName") {}

Person::Person(std::string n) : name(std::move(n)) {}

Person::Person(const Person& other) : name(other.name) {
    std::cout << "Person copy constructor\n";
}

Person::Person(Person&& other) noexcept : name(std::move(other.name)) {
    std::cout << "Person move constructor\n";
}

Person& Person::operator=(const Person& other) {
    if (this == &other) return *this;
    name = other.name;
    std::cout << "Person copy operator=\n";
    return *this;
}

Person& Person::operator=(Person&& other) noexcept {
    if (this == &other) return *this;
    name = std::move(other.name);
    std::cout << "Person move operator=\n";
    return *this;
}

Person::~Person() {
    std::cout << "Person deleted: " << name << "\n";
}

std::string Person::getName() const {
    return name;
}

void Person::show() const {
    std::cout << "Person: " << name << "\n";
}