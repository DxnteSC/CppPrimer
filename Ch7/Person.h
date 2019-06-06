#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

struct Person
{
    std::string name;
    std::string address;
    
    std::string getName() const {return name;} //const as should be able to read but not write
    std::string getAddress() const {return address;} //const as should be able to read but not write
};

std::istream &read(std::istream &is, Person &p) {
    is >> p.name >> p.address;
    return is;
}

std::ostream &print (std::ostream &os, const Person &p) {
    os << p.name << " lives at " << p.address;
    return os;
}

#endif
