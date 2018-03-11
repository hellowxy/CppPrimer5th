#include"transform.h"
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
#include<sstream>
using namespace std;

int main(){
    ifstream ruleStream("./rule");
    ifstream srcStream("./src");
    vector<string> mappedVec = word_transform(ruleStream, srcStream);
    for(const string& item : mappedVec){
        cout << item << endl;
    }
    return 0;
}

string transform(const map<string, string> &rules, const string& input){
    istringstream is(input);
    string ret;
    string word;
    map<string, string>::const_iterator map_it;
    while(is >> word){
        map_it = rules.find(word);
        if(map_it != rules.end()){
            word = map_it->second;//对于const的map不能使用下标
        }
        ret = ret + word + " ";
    }
    return ret;
}

map<string, string> buildRules(ifstream &in){
    map<string, string> rules;
    string key;
    string value;
    while(in >> key && getline(in, value)){
        rules[key] = value.substr(1);
    }
    return rules;
}

vector<string> word_transform(ifstream &ruleStream, ifstream& inputStream){
    map<string, string> rules = buildRules(ruleStream);
    vector<string> ret;
    string line;
    while(getline(inputStream, line)){
        string transformedLine = transform(rules, line);
        ret.push_back(transformedLine);
    }
    return ret;
}

