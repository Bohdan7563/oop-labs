#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

class Client {
private:
    std::string name;
    int age;

public:
    Client();
    Client(std::string n, int a = 18);  // передача за значенням для std::move

    ~Client();

    void show() const;
};

#endif