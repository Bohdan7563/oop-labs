#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
private:
    std::string name;
    int age;

public:
    Client();
    Client(std::string n, int a = 18);

    void show() const;
};

#endif
