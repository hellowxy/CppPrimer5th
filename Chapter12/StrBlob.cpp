#include<string>
#include<vector>
#include"StrBlob.h"
#include"StrBlobPtr.h"
#include<memory>
#include<iostream>
using namespace std;

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this, data->size());    
}

StrBlob::StrBlob():data(make_shared<vector<string>>()){

}

StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){

}
void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBalob");
    data->pop_back();
}
string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return data->front();
} 

string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
} 

string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}

string& StrBlob::back() const{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::check(size_type i, const std::string &msg) const{
    if(i >= data->size()){
        throw out_of_range(msg);
    }
}