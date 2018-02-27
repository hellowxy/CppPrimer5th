#ifndef PRAC8_4_H
#define PRAC8_4_H
#include<string>
#include<vector>
void ReadDataFromFileLBL(const std::string& filePath, std::vector<std::string>& lines);

void ReadDataFromFileWBW(const std::string& filePath, std::vector<std::string>& words);

void PrintVector(const std::vector<std::string> v);
#endif