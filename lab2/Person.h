#pragma once
#include <string>
#include <iostream>

class Person {
protected:
    std::string name;

public:
    Person();
    Person(std::string n);
    virtual ~Person();

    [[nodiscard]] std::string getName() const;
};