#include "Person.h"
#include <utility>

Person::Person() : name("NoName") {}

Person::Person(std::string n) : name(std::move(n)) {}

Person::~Person() {
    std::cout << "Person deleted: " << name << "\n";
}

void Person::info() const {
    std::cout << "Person info: " << name << "\n";
}

void Person::show() const {
    std::cout << "Person: " << name << "\n";
}

void Person::printRole() const {
    std::cout << "Role: Person\n";
}