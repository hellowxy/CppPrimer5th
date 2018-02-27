#include<algorithm>
#include<iostream>
#include<numeric>
#include<vector>
#include"../AppComm/container_util.h"
using namespace std;

int main(){
    vector<const char*> roster1 = {"aaa", "bbb", "ccc"};
    vector<const char*> roster2 = {"aaa", "bbb", "ccc"};
    bool e = equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    cout << e << endl;
    return 0;
}