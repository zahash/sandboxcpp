#ifndef SANDBOXCPP_PERSON
#define SANDBOXCPP_PERSON

#include <ostream>
#include <string>

class Person
{
public:
    std::string name;
    Person(std::string name) : name(name) {}
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "Person(\"" << p.name << "\")";
    return os;
}

#endif
