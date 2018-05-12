#ifndef STRVEC_H
#define STRVEC_H
#include<string>
#include<memory>
class StrVec{
    private:
        std::string *elements;
        std::string *first_free;
        std::string *cap;
        static std::allocator<std::string> alloc; //分配元素
        void free();
        void reallocate();
        void chk_n_alloc(){
            if(size() == capacity()){
                reallocate();
            }
        }
    public:
        StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}

        StrVec(const StrVec&);

        StrVec &operator=(const StrVec&);

        ~StrVec();

        std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);

        void push_back(const std::string&);

        size_t size() const{
            return first_free - elements;
        }

        size_t capacity() const{
            return cap - elements;
        }
        std::string *begin() const{
            return elements;
        }
        
        std::string *end() const{
            return first_free;
        }
        
};
std::allocator<std::string> StrVec::alloc;
#endif