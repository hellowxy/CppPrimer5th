#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main(){
    int a = 0;
    int b = 1;
    int *pa = &a;
    int *pb = &b;
    cout << (pa < pb) <<endl;

    return 0;
}

