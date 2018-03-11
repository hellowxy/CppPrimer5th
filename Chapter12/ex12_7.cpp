#include<vector>
#include<memory>
#include<iostream>
using namespace std;

void input_vector(shared_ptr<vector<int> > p){
    int value;
    while(cin >> value){
        p->push_back(value);
    }
}
void output_vector(shared_ptr<vector<int> > p){
    for(vector<int>::iterator it = p->begin(); it != p->end(); it++){
        cout << *it << " ";
    }
}

int main(){
    shared_ptr<vector<int> > p = make_shared<vector<int> >();
    input_vector(p);
    output_vector(p);
    return 0;
}