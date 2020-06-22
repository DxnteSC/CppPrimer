#include "Query.h"

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
    std::string text;
    while (std::getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Query &q)
{
    return os << q.rep();
}

inline Query::Query(const std::string &s) : queryBase(new WordQuery(s)) {}
inline Query operator~(const Query &qOperand)
{
    return std::shared_ptr<QueryBase>(new NotQuery(qOperand));
}
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}
inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{

    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}
