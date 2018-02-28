#include"container_util.h"
#include<iostream>
using namespace std;

void output_vector(const vector<int> &vec, ostream &os){
    for(vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++){
        os << *it << " ";
    }
    os << endl;
}

void output_vector(const vector<string> &vec, ostream &os){
    for(vector<string>::const_iterator it = vec.begin(); it != vec.end(); it++){
        os << *it << " ";
    }
    os << endl;
}

void output_list(const list<int> &l, ostream &os){
    for(list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        os << *it << " ";
    }
    os << endl;
}

void output_forward_listi(const std::forward_list<int> &fl, std::ostream &os){
    for(forward_list<int>::const_iterator it = fl.begin(); it != fl.end(); it++){
        os << *it << " ";
    }
    os << endl;
}

void output_forward_liststr(const std::forward_list<std::string> fl, std::ostream &os){
    for(forward_list<string>::const_iterator it = fl.begin(); it != fl.end(); it++){
        os << *it << " ";
    }
    os << endl;
}
