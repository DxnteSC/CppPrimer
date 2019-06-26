#include <vector>
#include <sstream>
#include <iostream>
#include <string>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main() {
    /* old code :: string line, word;  // will hold a line and word from input, respectively
    vector<PersonInfo> people; // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line)) {
        PersonInfo info;      // create an object to hold this record's data
        istringstream record(line); // bind record to the line we just read
        record >> info.name;  // read the name
        while (record >> word)        // read the phone numbers
            info.phones.push_back(word);  // and store them
        people.push_back(info); // append this record to people
    } */
    std::vector<PersonInfo> people;
    std::string line, word;
    std::istringstream record;
    while (getline(std::cin,line)) {
        PersonInfo info;
        record.clear(); // stream has to be reset.
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    for (auto &c: people) {
        std::cout << c.name << ": ";
        for (auto &d: c.phones) {
            std::cout << d << ", ";
        }
        std::cout << std::endl;
    }
}
