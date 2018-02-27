#include<fstream>
#include<vector>
#include<string>
#include<iostream>
#include"prac8_4.h"
using namespace std;

int main(){
    string filePath = "./test_data";
    vector<string> lines;
    vector<string> words;
    ReadDataFromFileLBL(filePath, lines);
    PrintVector(lines);
    ReadDataFromFileWBW(filePath, words);
    PrintVector(words);
    return 0;
}

void ReadDataFromFileLBL(const string& filePath, vector<string>& lines){
    ifstream input(filePath.c_str());
    string line;
    while(getline(input, line)){
        lines.push_back(line);
    }
}

void ReadDataFromFileWBW(const string& filePath, vector<string>& words){
    ifstream input(filePath.c_str());
    string word;
    while(input >> word){
        words.push_back(word);
    }
}

void PrintVector(const vector<string> v){
    for(vector<string>::const_iterator it = v.cbegin(); it != v.cend(); it++){
        cout << *it << endl;
    }
}