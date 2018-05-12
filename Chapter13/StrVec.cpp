#include<string>
#include<memory>
#include<utility>
#include"StrVec.h"
#include<iostream>
using std::cout;
using std::string;
using std::pair;
void StrVec::push_back(const string& s){
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::free(){
    if(elements){
        for(string* p = first_free; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e){
    string *data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

StrVec::~StrVec(){
    free();
}

StrVec::StrVec(const StrVec &s){
    pair<string*, string*> newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs){
    pair<string*, string*> data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate(){
    size_t newcapacity = size() ? 2 * size() : 1;
    string* newdata = alloc.allocate(newcapacity);
    string* dest = newdata;
    string* elem = elements;
    for(size_t i = 0; i != size(); i++){
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main(){
    StrVec sv;
    cout << sv.capacity() << std::endl;
    cout << sv.size() << std::endl;
    sv.push_back("a test");
    cout << sv.capacity() << std::endl;
    cout << sv.size() << std::endl;
    sv.push_back("b test");
    cout << sv.capacity() << std::endl;
    cout << sv.size() << std::endl;
    sv.push_back("c test");
    cout << sv.capacity() << std::endl;
    cout << sv.size() << std::endl;
    StrVec sv1 = sv;
    cout << sv.capacity() << std::endl;
    cout << sv.size() << std::endl;
 
    return 0;
}