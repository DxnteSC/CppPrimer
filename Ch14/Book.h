#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book
{
    friend std::ostream &operator<<(std::ostream &, const Book &);
    friend std::istream &operator>>(std::istream &, Book &);
    friend std::istream &read(std::istream &, Book &);
    friend bool operator==(const Book &, const Book &);
    friend bool operator!=(const Book &, const Book &);
    friend bool operator<(const Book &, const Book &);
    friend bool operator>(const Book &, const Book &);
    friend bool operator<=(const Book &, const Book &);
    friend bool operator>=(const Book &, const Book &);

public:
    Book() : author("Classified"), title("Undecided"), genre("Classified"), pageNumbers(0) {}
    Book(const std::string &a) : author(a) {}
    Book(const std::string &a, const std::string &t) : author(a), title(t) {}
    Book(const std::string &a, const std::string &t, const std::string &g) : author(a), title(t), genre(g) {}
    Book(const std::string &a, const std::string &t, const std::string &g, const int &i) : author(a), title(t), genre(g), pageNumbers(i) {}
    Book(std::istream &is)
    {
        read(is, *this);
    }
    explicit operator bool() const;

private:
    std::string author;
    std::string title;
    std::string genre;
    int pageNumbers;
};

std::ostream &operator<<(std::ostream &, const Book &);
std::istream &operator>>(std::istream &, Book &);
std::istream &read(std::istream &, Book &);
bool operator==(const Book &, const Book &);
bool operator!=(const Book &, const Book &);
bool operator<(const Book &, const Book &);
bool operator>(const Book &, const Book &);
bool operator<=(const Book &, const Book &);
bool operator>=(const Book &, const Book &);

#endif