#include"QueryResult.h"
#include<string>
#include<set>
#include<memory>
#include<vector>
#include<iostream>

using namespace std;
ostream& print(ostream& os, const QueryResult& qr){
    os << qr.getSearchWord() << " occurs " << qr.lines->size() << " time(s)" << endl;
    for(int num : *(qr.lines)){
        os << "\t(line " << (num + 1) << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}

