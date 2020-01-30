#include "Book.h"

std::ostream& operator<< (std::ostream& os, const Book& b)
{
    os << b.author << ", " << b.title << ", " << b.genre << ", " << b.pageNumbers;
    return os;
}

std::istream& operator>> (std::istream& is, Book& b)
{
    is >> b.author >> b.title >> b.genre >> b.pageNumbers;
    if(!is)
    {
        b = Book();
    }
    return is;
}