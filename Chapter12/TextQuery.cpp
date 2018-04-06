#include"TextQuery.h"
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<iostream>
#include<memory>
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::shared_ptr;
TextQuery::TextQuery(ifstream& infile):file(new vector<string>){
    string line;
    int lineNum = 0;
    while(getline(infile, line)){
        file->push_back(line);
        istringstream is(line);
        string word;
        while(is >> word){
            auto& lineSet = wordsMapping[word];
            if(!lineSet){
                lineSet.reset(new set<int>);
            }
            lineSet->insert(lineNum);
        }

        lineNum++;
    }
    
}

QueryResult TextQuery::query(string& word){
    map<string, shared_ptr<set<int>>>::iterator it = wordsMapping.find(word);
    if(it != wordsMapping.end()){
        return QueryResult(word, file, it->second);
    }
    else{
        return QueryResult(word, file, shared_ptr<set<int>>(new set<int>));
    }
}