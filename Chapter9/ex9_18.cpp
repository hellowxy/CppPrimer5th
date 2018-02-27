#include<list>
#include<vector>
#include<deque>
#include<iostream>
#include<string>
using namespace std;

void input(istream& is, deque<string>& d){
    string input;
    while(is >> input){
        d.push_back(input);
    }
}

void output(ostream& os, const deque<string>& d){
    for(deque<string>::const_iterator ci = d.cbegin(); ci != d.cend(); ci++){
        os << *ci << endl;
    }
}

int main(){
    deque<string> d;
    input(cin, d);
    output(cout, d);
    return 0;
}