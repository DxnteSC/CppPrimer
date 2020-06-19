#include "Quote.h"

#include <memory>
#include <vector>

int main()
{
    std::vector<Quote> nonPtrVec;
    std::vector<std::shared_ptr<Quote>> ptrVec;
    double nonPtrSum, ptrSum;

    Bulk_quote q1("q1", 50, 10, 0.5);
    Bulk_quote q2("q2", 40, 8, 0.4);
    Bulk_quote q3("q3", 30, 6, 0.3);
    Bulk_quote q4("q4", 20, 4, 0.2);
    Bulk_quote q5("q5", 10, 2, 0.1);

    nonPtrVec.push_back(q1);
    nonPtrVec.push_back(q2);
    nonPtrVec.push_back(q3);
    nonPtrVec.push_back(q4);
    nonPtrVec.push_back(q5);

    ptrVec.push_back(std::make_shared<Bulk_quote>(q1));
    ptrVec.push_back(std::make_shared<Bulk_quote>(q2));
    ptrVec.push_back(std::make_shared<Bulk_quote>(q3));
    ptrVec.push_back(std::make_shared<Bulk_quote>(q4));
    ptrVec.push_back(std::make_shared<Bulk_quote>(q5));

    for (auto i : nonPtrVec)
    {
        nonPtrSum += i.net_price(20);
    }
    std::cout << "Non-Pointer Sum: " << nonPtrSum << std::endl;

    for (auto i : ptrVec)
    {
        ptrSum += i->net_price(20);
    }
    std::cout << "Pointer Sum: " << ptrSum << std::endl;
}