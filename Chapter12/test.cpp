#include<memory>
#include<iostream>
#include"StrBlob.h"
#include"StrBlobPtr.h"
#include<string>
using namespace std;
int main(){
    StrBlob b1;
    {
        StrBlob b2({"hello", "world"});
        b1 = b2;
    }
    cout << b1.size() << endl;

    StrBlobPtr p = b1.begin();
    cout << p.deref() << endl;
    p.incr();
    cout << p.deref() << endl;
     
    return 0;

}
