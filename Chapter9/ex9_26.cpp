#include<vector>
#include<iostream>
#include<list>
#include"container_util.h"
using namespace std;

int main(){
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> vec;
    list<int> lst;
    vec.assign(ia, ia + sizeof(ia) / sizeof(int));
    lst.assign(ia, ia + sizeof(ia) / sizeof(int));
    output_vector(vec, cout);
    output_list(lst, cout);

    vector<int>::iterator itVec = vec.begin();
    while(itVec != vec.end()){
        if(*itVec % 2 == 0){ //even
            itVec = vec.erase(itVec);
        }
        else{
            itVec++;
        }
    }

    list<int>::iterator itLst = lst.begin();
    while(itLst != lst.end()){
        if(*itLst % 2 == 0){ // even
            itLst++;
        }
        else{
            itLst = lst.erase(itLst);
        }
    }

    output_vector(vec, cout);
    output_list(lst, cout);

    return 0;
}