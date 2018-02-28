#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include "../AppComm/container_util.h"
using namespace std;

bool isEqualOrLongerThan5(string val){
    return val.size() >= 5;
}

int main(){
    vector<string> vec = {"better", "late", "fox", "jump", "over", "the", "than", "never"};
    output_vector(vec, cout);
    vector<string>::iterator it = partition(vec.begin(), vec.end(), isEqualOrLongerThan5);
    for(vector<string>::iterator i = vec.begin(); i != it; i++){
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}