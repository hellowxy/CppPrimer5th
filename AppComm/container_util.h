#ifndef CONTAINER_UTIL_H
#define CONTAINER_UTIL_H
#include<vector>
#include<list>
#include<forward_list>
#include<string>
#include<iostream>

void output_vector(const std::vector<int> &vec, std::ostream &os);
void output_vector(const std::vector<std::string> &vec, std::ostream &os);
void output_list(const std::list<int> &lst, std::ostream &os);
void output_forward_listi(const std::forward_list<int> &fl, std::ostream &os);
void output_forward_liststr(const std::forward_list<std::string> fl, std::ostream &os);

#endif