#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    StrBlob(): data(std::make_shared<std::vector<std::string>>) {}
    StrBlob(std::initializer_list<std::string>): data(std::make_shared<std::vector<std::string>>(il)) {}
    size_type size() const { return data -> size(); }
    bool empty() const { return data -> empty(); }
    // Add and remove elements
    void push_back(const std::string& s) { data -> push_back(s); }
    void pop_back();
    // Element access
    std::string& front();
    std::string& back();
    const std::string& front() const ;
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    // Error message if data[i] is unabailable
    void check(size_type, const std::string&) const;
};

#endif
