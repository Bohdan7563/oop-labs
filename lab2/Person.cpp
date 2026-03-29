#include "Person.h"
#include <utility>

Person::Person() : name("NoName") {
    std::cout << "Person created\n";
}

Person::Person(std::string n) : name(std::move(n)) {
    std::cout << "Person created\n";
}

Person::~Person() {
    std::cout << "Person deleted: " << name << std::endl;
}

std::string Person::getName() const {
    return name;
}