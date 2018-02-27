#include<vector>
#include<iostream>
using namespace std;
bool FindInVector(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value){       
    while(begin != end){     
        if(*begin == value){
            return true;
        }        
        else{
            begin++;
        }
    }
    return false;
}

int main(){
    vector<int> vec{0,1,2, 3};    
    vector<int>::const_iterator begin = vec.cbegin();
    vector<int>::const_iterator end = begin +3;
    bool isFind = FindInVector(begin, end, 0);
    cout << isFind << endl;
}