#include<vector>
#include<string>
#include<iostream>
#include "../AppComm/container_util.h"
using namespace std;

void elimDups(vector<string> &words){
    //output_vector(words, cout);
    sort(words.begin(), words.end());
    //output_vector(words, cout);
    vector<string>::iterator end_unique = unique(words.begin(), words.end());
    //output_vector(words, cout);
    words.erase(end_unique, words.end());
    //output_vector(words, cout);
}

bool isShorter(const string &s1, const string &s2){
    return s1.size() < s2.size();
}

int main(){
    vector<string> vec = {"the", "quick", "red", "fox", "jump", "over", "the", "slow", "red", "turtle"};
    output_vector(vec, cout);
    elimDups(vec);
    output_vector(vec, cout);
    stable_sort(vec.begin(), vec.end(), isShorter);
    output_vector(vec, cout);
    return 0;
}