#ifndef QUERY_H
#define QUERY_H

#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class QueryResult;

class TextQuery
{
public:
    friend class QueryResult;
public:
    TextQuery(std::ifstream&);
    QueryResult query(std::string&);
private:
    std::shared_ptr<std::vector<std::string>> inputText;
    std::map<std::string, std::set<std::vector<std::string>::size_type>> wordMap;
};

class QueryResult
{
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(const std::string& s, std::shared_ptr<std::vector<std::string>>& lines, std::shared_ptr<std::set<std::vector<std::string>::size_type>>& lineNumbers): query(s), queryPtrLines(lines), queryPtrLineNo(lineNumbers) {}
private:
    std::string query;
    std::shared_ptr<std::vector<std::string>> queryPtrLines;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> queryPtrLineNo;
};

#endif
