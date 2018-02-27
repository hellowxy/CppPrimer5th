#include"container_util.h"
#include<forward_list>
#include<iostream>
#include<string>
using namespace std;
void insert_after_value(forward_list<string> &fl, string strA, string strB){
    forward_list<string>::iterator prev = fl.before_begin();
    forward_list<string>::iterator cur = fl.begin();
    while(cur != fl.end() && *cur != strA){
        prev = cur;
        cur++;
    }
    if(cur == fl.end()){
        fl.insert_after(prev, strB);
    }
    else{
        fl.insert_after(cur, strB);
    }    
}

int main(){
    //forward_list<string> fl = {"a", "fox", "jump", "over", "a", "dog"};
    forward_list<string> fl;
    output_forward_liststr(fl, cout);
    insert_after_value(fl, "a", "red");
    output_forward_liststr(fl, cout);
    insert_after_value(fl, "b", "dog");
    output_forward_liststr(fl, cout);
    return 0;
}