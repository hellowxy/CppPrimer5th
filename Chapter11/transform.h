#ifndef TRANSFORM_H
#define TRANSFORM_H
#include<string>
#include<map>
#include<vector>
#include<fstream>

std::string transform(const std::map<std::string, std::string> &rules, const std::string& input);
std::map<std::string, std::string> buildRules(std::ifstream &in);
std::vector<std::string> word_transform(std::ifstream &ruleStream, std::ifstream& srcStream);

#endif