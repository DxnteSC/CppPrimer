#include "Query.h"

class QueryResult;

TextQuery::TextQuery(std::ifstream& input): inputText(std::make_shared<std::vector<std::string>>()), wordMap()
{
    std::string line;
    while (std::getline(input,line))
    {
        inputText->push_back(line);
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
}

QueryResult TextQuery::query(std::string& s)
{
    auto it = wordMap.find(s);
    if (it == wordMap.end())
        std::cout << "Word not found" << std::endl;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> lineNos = std::make_shared<std::set<std::vector<std::string>::size_type>>((it->second));
    QueryResult qr(s,inputText, lineNos);
    return qr;
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
    os << qr.query << " occurs " << qr.queryPtrLineNo->size() << ((qr.queryPtrLineNo->size() > 1) ? " times: " : " time: ") << std::endl;
    for (auto i = qr.queryPtrLineNo->begin(); i != qr.queryPtrLineNo->end(); ++i)
    {
        os << "\t(line " << *i + 1 << ") " << (*qr.queryPtrLines)[*i] << std::endl;
    }
    return os;
}
