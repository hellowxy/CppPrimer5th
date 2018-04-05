#include<string>
#include<memory>
#include<vector>
#include"StrBlob.h"
#include"StrBlobPtr.h"
using namespace std;

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string& msg) const{
   shared_ptr<vector<string>> ret = wptr.lock();
   if(!ret){
       throw std::runtime_error("unboubd StrBlobPtr");
   }
   if(i >= ret->size()){
       throw std::out_of_range(msg);       
   }
   return ret;
}

string& StrBlobPtr::deref() const{
    shared_ptr<vector<string>> ret = check(curr, "dereference past end");
    return (*ret)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

