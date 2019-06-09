#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <vector>
#include <iostream>

class Screen;

class Window_mgr {
public:
    typedef std::vector<Screen>::size_type ScreenIndex;
    
public:
    Window_mgr();
    
public:
    void clear(ScreenIndex);
    void addScreen(Screen&);
    int size() {return screens.size();}
    Screen& getScreen(ScreenIndex i) {return screens[i];}
    
private:
    std::vector<Screen> screens;
};

#include "Screen.h"

#endif
