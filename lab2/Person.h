#pragma once
#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
public:
    Person();
    Person(std::string n);
    Person(const Person& other);
    Person(Person&& other) noexcept;
    Person& operator=(const Person& other);
    Person& operator=(Person&& other) noexcept;
    virtual ~Person();
    [[nodiscard]]std::string getName() const;
    virtual void show() const;
};