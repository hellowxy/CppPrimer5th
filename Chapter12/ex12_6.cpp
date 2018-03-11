#include<vector>
#include<iostream>
#include<memory>
using namespace std;

void input_vector(vector<int> * const pv){
    int value;
    cout << "input values" << endl;
    while(cin >> value){
        pv->push_back(value);
    }
}

void output_vector(vector<int> *const pv){
    for(vector<int>::iterator it = pv->begin(); it != pv->end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    vector<int> *pv = new vector<int>;
    input_vector(pv);
    output_vector(pv);
    delete pv;
    return 0;
}

