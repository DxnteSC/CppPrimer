#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

bool valid(const std::string& phoneNo) {
    if (phoneNo.size() > 4) {
        return false;
    }
    return true;
}
std::string format(const std::string& phoneNo) {
    return phoneNo + ",";
}

int main(int argc, char* argv[]) {
    if (argc > 3) {
        std::cerr << "Too many files given" << std::endl;
        return -1;
    }
    if (argc < 3) {
        std::cerr << "Please give files for input and output" << std::endl;
    }
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);
    std::string line, word;
    std::vector<PersonInfo> people;
    while (getline(input, line)) {
        PersonInfo info;
        std::istringstream record(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (const auto& entry: people) {
        std::ostringstream badNums, formatted;
        for (const auto& nums: entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty()) {
            output << entry.name << ": " << formatted.str() << std::endl;
        } else {
            output << "INVALID: " << entry.name << ": " << badNums.str() << std::endl;
            std::cerr << "Invalid phone number: " << badNums.str() << " for " << entry.name << std::endl;
        }
    }
}
