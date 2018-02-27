#ifndef WINDOW_MGR
#define WINDOW_MGR
#include<vector>
#include"Screen.h"
class Window_mgr{
    public:
    Window_mgr(){
        screens.push_back(Screen(24, 80, ' '));
    }
    private:
    std::vector<Screen> screens;
};
#endif