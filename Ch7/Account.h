#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account(): owner("New Account"), amount(0.0) {}
    Account(std::string n): owner(n), amount(0.0) {}
    Account(std::string n, double c): owner(n), amount(c) {}
    void calculate() {amount += amount * interestRate;}
    static double getRate() {return interestRate;}
    static void setRate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

#endif
