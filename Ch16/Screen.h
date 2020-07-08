#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

typedef std::string::size_type pos;

template <pos h, pos w>
class Screen;

template <pos h, pos w>
class WindowMgr;

template <pos h, pos w>
class WindowMgr
{
public:
    typedef typename std::vector<Screen<h, w>>::size_type ScreenIndex;

public:
    WindowMgr() : screens{Screen<h, w>()} {}
    void clear(ScreenIndex);
    void addScreen(Screen<h, w> &);
    int size() { return screens.size(); }
    Screen<h, w> &getScreen(ScreenIndex i) { return screens[i]; }

private:
    std::vector<Screen<h, w>> screens;
};

template <pos h, pos w>
class Screen
{
public:
    typedef typename std::vector<Screen<h, w>>::size_type ScreenIndex;

public:
    template <pos a, pos b>
    friend class WindowMgr;
    friend void WindowMgr<h, w>::clear(ScreenIndex);

public:
    Screen() : contents(h * w, ' ') {}
    Screen(char c) : contents(h * w, c) {}
    char get() const
    {
        return contents[cursor];
    }
    char get(pos, pos) const;
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &);
    const Screen &display(std::ostream &) const;

private:
    pos cursor = 0;
    std::string contents;
    void doDisplay(std::ostream &os) const
    {
        os << contents;
    }
};

template <pos h, pos w>
void WindowMgr<h, w>::clear(ScreenIndex i)
{
    Screen<h, w> &s = screens[i];
    s.contents = std::string(h * w, ' ');
}

template <pos h, pos w>
void WindowMgr<h, w>::addScreen(Screen<h, w> &s)
{
    screens.push_back(s);
}

template <pos h, pos w>
char Screen<h, w>::get(pos r, pos c) const
{
    pos row = r * w;
    return contents[row + c];
}

template <pos h, pos w>
Screen<h, w> &Screen<h, w>::move(pos r, pos c)
{
    pos row = r * w;
    cursor = row + c;
    return *this;
}

template <pos h, pos w>
Screen<h, w> &Screen<h, w>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template <pos h, pos w>
Screen<h, w> &Screen<h, w>::set(pos r, pos c, char ch)
{
    contents[r * w + c] = ch;
    return *this;
}

template <pos h, pos w>
Screen<h, w> &Screen<h, w>::display(std::ostream &os)
{
    doDisplay(os);
    return *this;
}

template <pos h, pos w>
const Screen<h, w> &Screen<h, w>::display(std::ostream &os) const
{
    doDisplay(os);
    return *this;
}

#endif