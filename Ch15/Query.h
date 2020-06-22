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

class QueryResult
{
public:
    using line_no = std::vector<std::string>::size_type;
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> l, std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(l), file(f) {}
    std::set<line_no>::iterator begin() { return lines->begin(); }
    std::set<line_no>::const_iterator cbegin() { return lines->cbegin(); }
    std::set<line_no>::iterator end() { return lines->end(); }
    std::set<line_no>::const_iterator cend() { return lines->cend(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;

public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryBase
{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query : public QueryBase
{
    friend Query operator~(const Query &);
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);
    friend std::ostream &operator<<(std::ostream &, const Query &);

public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const override
    {
        return queryBase->eval(t);
    }
    std::string rep() const override { return queryBase->rep(); }

private:
    Query(std::shared_ptr<QueryBase> q) : queryBase(q) {}
    std::shared_ptr<QueryBase> queryBase;
};

//std::ostream &operator<<(std::ostream &, const Query &);

class WordQuery : public QueryBase
{
    friend class Query;
    WordQuery(std::string s) : queryWord(s) {}
    QueryResult eval(const TextQuery &t) const override
    {
        return t.query(queryWord);
    }
    std::string rep() const override { return queryWord; }
    std::string queryWord;
};

class NotQuery : public QueryBase
{
    friend Query operator~(const Query &);
    NotQuery(Query q) : query(q) {}
    QueryResult eval(const TextQuery &t) const override;
    std::string rep() const override
    {
        return "~(" + query.rep() + ")";
    }
    Query query;
};

class BinaryQuery : public QueryBase
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s)
    {
    }
    std::string rep() const override
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery &) const override;
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery &) const override;
};
#endif
