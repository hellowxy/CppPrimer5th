#include<iostream>
#include<forward_list>
#include"container_util.h"
using namespace std;



int main(int argc, char* argv[]){
    forward_list<int> fl;
    forward_list<int>::iterator flIterator = fl.before_begin();
   
    fl.insert_after(flIterator, 6);
    fl.insert_after(flIterator, 5);
    fl.insert_after(flIterator, 4);
    fl.insert_after(flIterator, 3);
    fl.insert_after(flIterator, 2);
    fl.insert_after(flIterator, 1);
    fl.insert_after(flIterator, 0);
       
    output_forward_listi(fl, cout);
    forward_list<int>::iterator prev = fl.before_begin();
    forward_list<int>::iterator cur = fl.begin();
    while(cur != fl.end()){
        if(*cur % 2 == 0){
            cur = fl.erase_after(prev);
        }
        else{
            prev = cur;
            cur++;
        }
    }
    output_forward_listi(fl, cout);
    return 0;
}