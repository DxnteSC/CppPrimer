#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
    
    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print (std::ostream&, const Person&);

public:
    std::string getName() const {return name;} //const as should be able to read but not write
    std::string getAddress() const {return address;} //const as should be able to read but not write
    Person() = default;
    Person(const std::string& n) : name(n), address("") {};
    Person(const std::string& n, const std::string& a) : name(n), address(a) {}
    Person(std::istream&);

private:
    std::string name;
    std::string address;
};

std::istream &read(std::istream&, Person&);
std::ostream &print (std::ostream&, const Person&);

#endif
