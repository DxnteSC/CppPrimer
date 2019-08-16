#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

void runQuerries(std::ifstream& input)
{
    std::vector<std::string> inputText;
    std::map<std::string, std::set<std::vector<std::string>::size_type>> wordMap;
    
    std::string line;
    while (std::getline(input,line))
    {
        inputText.push_back(line);
        std::string word;
        std::istringstream words(line);
        while (words >> word)
        {
            static std::vector<std::string>::size_type pos = 0;
            auto it = wordMap.find(word);
            if (it == wordMap.end())
            {
                std::set<std::vector<std::string>::size_type> s = {pos};
                wordMap.insert({word,s});
                if (words.eof())
                    ++pos;
            }
            else
            {
                it->second.insert(pos);
                if (words.eof())
                    ++pos;
            }
        }
    }
    
   do
    {
        std::cout << "enter word to look for, or q to quit: " << std::endl;
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        auto it = wordMap.find(s);
        if (it == wordMap.end())
            std::cout << s << " not found in text" << std::endl;
        else
        {
            std::set<std::vector<std::string>::size_type> lineNos = std::set<std::vector<std::string>::size_type>((it->second));
            std::cout << s << " occurs " << lineNos.size() << ((lineNos.size() > 1) ? " times: " : " time: ") << std::endl;
            for (auto i = lineNos.begin(); i != lineNos.end(); ++i)
            {
                std::cout << "\t(line " << *i + 1 << ") " << inputText[*i] << std::endl;
            }
        }
    }
    while (true); // prefer this way as in my opinion it reads nicer
}

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        if (argc == 1)
        {
            std::cerr << "Missing input file" << std::endl;
            return -1;
        }
        if (argc > 2)
        {
            std::cerr << "Too many files" << std::endl;
            return -2;
        }
    }
    
    std::ifstream input(argv[1]);
    if (!input)
    {
        std::cerr << "Input file invalid" << std::endl;
        return -3;
    }
    
    runQuerries(input);
}

