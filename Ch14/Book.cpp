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

bool operator== (const Book& lhs, const Book& rhs)
{
    if ((lhs.author == rhs.author) && (lhs.title == rhs.title) && (lhs.genre == rhs.genre))
        return true;
    return false;
}

bool operator!= (const Book& lhs, const Book& rhs)
{
    return !(lhs == rhs);
}