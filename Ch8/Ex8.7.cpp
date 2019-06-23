#include "Sales_data.h" // From Ch7
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc > 3) {
        std::cerr << "Too many arguments passed" << std::endl;
        return -2;
    }
    if (argc != 3) {
        std::cerr << "Need to pass files for input and output" << std::endl;
        return -3;
    }
    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Failed to open file: " << argv[1] << std::endl;
        return -4;
    }
    std::ofstream output(argv[2]);
    Sales_data total;
    if (read(input,total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
        return 0;
    } else {
        std::cerr << "No Data" << std::endl;
        return -1;
    }
}
