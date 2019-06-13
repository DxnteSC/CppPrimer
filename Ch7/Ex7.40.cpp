#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    Book(): author("Classified"),  title("Undecided"), genre("Classified"),pageNumbers(0) {}
    Book(const std::string& a): author(a){}
    Book(const std::string& a, const std::string& t): author(a), title(t) {}
    Book(const std::string& a, const std::string& t, const std::string& g): author(a), title(t), genre(g) {}
    Book(const std::string& a, const std::string& t, const std::string& g, const int& i): author(a), title(t), genre(g), pageNumbers(i) {}
    
public:
    std::string author;
    std::string title;
    std::string genre;
    int pageNumbers;
};

int main() {
    std::vector<Book> b;
    std::string title = "The One", author = "Me", genre = "Comedy";
    int pg = 305;
    Book b1;
    Book b2(author);
    Book b3("You");
    Book b4(author, title);
    Book b5("You","Not The One");
    Book b6(author,title,genre);
    Book b7("You", "Not The One", "Documentary");
    Book b8(author,title,genre,pg);
    Book b9("You","Not The One","Documentary",305);
    
    b.push_back(b1);
    b.push_back(b2);
    b.push_back(b3);
    b.push_back(b4);
    b.push_back(b5);
    b.push_back(b6);
    b.push_back(b7);
    b.push_back(b8);
    b.push_back(b9);
    
    for (auto i = 0; i != b.size();++i) {
        std::cout << "B" << i + 1 << ": " <<std::endl;
        std::cout << "Author: " << b[i].author << std::endl;
        std::cout << "Title: " << b[i].title << std::endl;
        std::cout << "Genre: " << b[i].genre << std::endl;
        std::cout << "Number of Pages: " << b[i].pageNumbers << std::endl;
        std::cout << std::endl;
    }
}
