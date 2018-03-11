#include<map>
#include<list>
#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main(){
    map<string, int> m1={{"aaa", 10}, {"bbb", 20}};
    pair<map<string, int>::iterator, bool> ret = m1.insert(make_pair("aaa", 11));
    cout << boolalpha << ret.first->first << " " << ret.first->second << endl;
    cout << ret.second << endl;
    
    return 0;
}