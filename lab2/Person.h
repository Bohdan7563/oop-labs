#pragma once
#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
public:
    Person();
    Person(std::string n);

    virtual ~Person(); // ✅ віртуальний деструктор

    // ❌ НЕ virtual → static binding
    void info() const;

    // ✅ virtual функції
    virtual void show() const;
    virtual void printRole() const;

    // ✅ pure virtual → робить клас абстрактним
    virtual void work() const = 0;
};