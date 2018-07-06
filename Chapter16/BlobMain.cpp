#include<iostream>
#include<string>
#include"Blob.h"

int main()
{
    using namespace std;
    Blob<string> strBlob;
    cout << strBlob.size() << " " << strBlob.empty() << endl;

    strBlob.push_back("hello");
    strBlob.push_back(" ");
    strBlob.push_back("world");
    strBlob.push_back("!!!");
    for(Blob<string>::size_type i = 0; i < strBlob.size(); i++)
    {
        cout << strBlob[i];
    }
    cout << endl;
    while(!strBlob.empty())
    {
        cout << strBlob.back();
        strBlob.pop_back();
    }
    cout << endl;
    return 0;  
}