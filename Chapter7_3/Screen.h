#ifndef SCREEN_H
#define SCREEN_H
#include<string>
class Screen{
    public:
        typedef std::string::size_type pos;
        Screen():cursor(0), height(0), width(0), contents(){}
        Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht * wd, c){}
        char get() const{
            return contents[cursor];
        }
        char get(pos ht, pos wd) const;
        Screen &move(pos r, pos c);
        Screen &set(char);
        Screen &set(pos, pos, char);
        Screen &display() const;
    private:
        pos cursor;
        pos height;
        pos width;
        std::string contents;

};
#endif