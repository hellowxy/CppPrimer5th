#ifndef HASPTR_H
#define HASPTR_H
#include <string>

class HasPtr{
    private:
        std::string *ps;
        int i;
    public:
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0){}
        HasPtr(const HasPtr& other):ps(new std::string(pther->ps)),i(other.i)
        {}
        
        HasPtr& operator=(const HasPtr& right){
            if(this != &right){
                delete ps;
                //切记，要释放掉原来的ps指针!!!
                this->ps = new string(*(right.ps));
                this.i = right.i;
            }
            return *this;
        }

        ~HasPtr(){
            delete ps;
            ps = nullptr;
        }
}
#endif