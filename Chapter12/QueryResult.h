#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H
#include<string>
#include<set>
#include<memory>
#include<vector>
#include<iostream>
class QueryResult{
    friend std::ostream& print(std::ostream& os, const QueryResult& qr);
    public:
    QueryResult(std::string& word, std::shared_ptr<std::vector<std::string>> file,
        std::shared_ptr<std::set<int>> lineNums):
        queryWord(word),file(file),lines(lineNums){}

    std::string getSearchWord() const{
        return queryWord;
    }
    
    private:
    std::string queryWord;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<int>> lines;
};
#endif