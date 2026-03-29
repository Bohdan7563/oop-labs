#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

class Client : public Person {
protected:
    int age;

public:
    Client();
    Client(std::string n, int a = 18);

    Client(const Client& other);
    Client(Client&& other) noexcept;

    ~Client() override;

    virtual void show() const;
};

#endif