#pragma once
#include <string>

class Person {
protected:
    std::string name;
public:
    Person();
    explicit Person(std::string n);
    virtual ~Person() = default;

    virtual void info() const;
    virtual void show() const;
    virtual void printRole() const;
    virtual void work() const = 0;

    [[nodiscard]] std::string getName() const { return name; }
};