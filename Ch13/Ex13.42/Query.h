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

#include "../StrVec.h"

class QueryResult;

class TextQuery
{
public:
    using line_no = size_t;
public:
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<StrVec> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
public:
    using line_no = size_t;
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<StrVec> f): sought(s), lines(p), file(f) {}
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<StrVec> file;
};

#endif
