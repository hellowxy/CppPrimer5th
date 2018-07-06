#include<iostream>
#include<string>
#include"Blob.h"
#include"BlobPtr.h"

int main()
{
    using namespace std;
    Blob<string> strBlob;
    cout << strBlob.size() << " " << strBlob.empty() << endl;

    strBlob.push_back("hello");
    strBlob.push_back(" ");
    strBlob.push_back("world");
    strBlob.push_back("!!!");
  

    BlobPtr<string> ptr(strBlob);
    while(!ptr.past_of_end())
    {
        cout << *ptr++;
    }
    cout << endl;
    return 0;  
}