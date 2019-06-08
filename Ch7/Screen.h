#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>

class Screen {
public:
    typedef std::string::size_type pos;

public:
    Screen() = default;
    Screen(pos h, pos w) : height(h), width(w), contents(h*w, ' ') {}
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h*w,c) {}
    
public:
    char get() const {
        return contents[cursor];
    }
    char get(pos, pos) const;
    Screen& move(pos, pos);
    Screen& set(char);
    Screen& set(pos, pos, char);
    Screen& display(std::ostream&);
    const Screen& display (std::ostream&) const;

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;

private:
    void do_display(std::ostream& os) const {
        os << contents;
    }
};


#endif
