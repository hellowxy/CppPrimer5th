#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include<vector>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include"QueryResult.h"
class TextQuery{
    public:
    TextQuery(std::ifstream& infile);
    QueryResult query(std::string& word);
    private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<int>>> wordsMapping;
};
#endif