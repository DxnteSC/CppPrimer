#include <iostream>
#include <string>
#include <vector>

class Vehicle {
    
public:
    Vehicle(const std::string& n, const std::string& t, unsigned c, const std::string& cond): name(n), type(t),cost(c), condition(cond) {}
    Vehicle(): Vehicle("Unnamed","TBD",0,"Brand New") {}
    Vehicle(const std::string& n): Vehicle(n,"TBD",0," Brand New")
    Vehicle(const std::string& n, std::string& t) : Vehicle(n,t,0,"Brand New")
    Vehicle(const std::string& n, std::string& t, unsigned c) : Vehicle(n,t,c,"Brand New")
    
public:
    std::string name;
    std::string type;
    unsigned cost;
    std::string condition;

};
