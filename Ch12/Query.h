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
    using line_no = std::vector<std::string>::size_type;
public:
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
public:
    using line_no = std::vector<std::string>::size_type;
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f): sought(s), lines(p), file(f) {}
    std::shared_ptr<std::vector<std::string>> get_file { return file; }
    std::set<line_no>::iterator begin() { return lines->begin(); }
    std::set<line_no>::iterator cbegin() const { return lines->cbegin(); }
    std::set<line_no>::const_iterator end() { return lines->end(); }
    std::set<line_no>::const_iterator cend() const { return lines->cend(); }
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif
