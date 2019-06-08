#include "Screen.h"

char Screen::get(pos r,pos c) const{
    pos row = r * width;
    return contents[row + c];
}

Screen& Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}

Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

Screen& Screen::set(pos r, pos c, char ch) {
    contents[r*width + c] = ch;
    return *this;
}

Screen& Screen::display(std::ostream& os) {
    do_display(os);
    return *this;
}

const Screen& Screen::display(std::ostream& os) const {
    do_display(os);
    return *this;
}
