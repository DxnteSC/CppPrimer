#include "Account.h"

double Account::initRate() {
    return 0.05;
}

double Account::interestRate = initRate();

void Account::setRate(double d) {
    interestRate = d;
}
