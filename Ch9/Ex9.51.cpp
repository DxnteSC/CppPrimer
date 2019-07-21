#include <iostream>
#include <string>
#include <vector>

class USDateFormat {
public:
    friend std::ostream& print(std::ostream&, const USDateFormat&);
public:
    USDateFormat(unsigned m = 1, unsigned d = 1, unsigned y = 1): Month(m), Day(d),  Year(y) {}
    USDateFormat(const std::string&);
    
private:
    unsigned Month;
    unsigned Day;
    unsigned Year;
    static const std::vector<std::string> months;
    static const std::string letters;
    static const std::vector<std::string> days;

};

const std::vector<std::string> USDateFormat::months = {"Jan = 01", "Feb = 02", "Mar = 03", "Apr = 04", "May = 05", "Jun = 06", "Jul = 07", "Aug = 08", "Sep = 09", "Oct = 10", "Nov = 11", "Dec = 12"};

const std::string USDateFormat::letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnoprstuvwxyz";

USDateFormat::USDateFormat(const std::string& s) {
    if ((s.size() == 8 || s.size() == 10) && (s.find_first_of(letters) == std::string::npos)) {
        if (s.size() == 10) {
            Month = stoi(s.substr(0,2));
            Day = stoi(s.substr(3,5));
            Year = stoi(s.substr(6));
        } else {
            Month = stoi(s.substr(0,1));
            Day = stoi(s.substr(2,3));
            Year = stoi(s.substr(4));
        }
    } else if (s.find_first_of(letters) != std::string::npos) {
        for (auto i = months.begin(); i != months.end(); ++i) {
            if (s.find((*i).substr(0,3)) != std::string::npos) {
                Month = stoi((*i).substr(6));
                break;
            }
        }
        std::string::size_type pos = s.find_first_of("0123456789");
        std::string day = s.substr(s.find_first_of("0123456789"));
        Day = stoi(day);
        std::string::size_type pos2 = s.find_first_of(",",pos);
        std::string year = s.substr(s.find_first_of("0123456789",pos2));
        Year = stoi(year);
    } else {
        Month = 1;
        Day = 1;
        Year = 1;
        std::cerr << "Unrecognised format for input. Please re-enter." << std::endl;
    }
}

std::ostream& print(std::ostream& out, const USDateFormat& d) {
    out << "(US) Date: " << d.Month << "/" << d.Day << "/" << d.Year << std::endl;
    return out;
}

int main() {
    
    USDateFormat d("Sep 09, 2001");
    USDateFormat d1("09/09/2001");
    USDateFormat d2("Sep 9, 2001");
    USDateFormat d3("9/9/2001");
    USDateFormat d4("September 9, 2001");
    
    std::vector<USDateFormat> v = {d,d1,d2,d3,d4};
    for (auto c: v) {
        print(std::cout, c);
    }
}
