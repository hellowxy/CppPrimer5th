#include<forward_list>
#include<iostream>
#include"container_util.h"
using namespace std;

int main(){
    forward_list<int> fl = {0,1,2,3,4,5,6,7,8,9};
    output_forward_listi(fl, cout);
    auto prev = fl.before_begin();
    auto cur = fl.begin();
    while(cur != fl.end()){
        if(*cur % 2 == 0){            
            cur = fl.insert_after(cur, *cur);
            prev = cur;
            cur++;
        }
        else{
            cur = fl.erase_after(prev);
        }
    }
    output_forward_listi(fl, cout);
    return 0;
}