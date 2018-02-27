#include<vector>
#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
    vector<int> vec;
    char* arg = argv[1];
    cout << arg << endl;
    int value = 0;
    switch(arg[0]){
        case '0':
            value = vec.at(0);
            break;
        case '1':
            value = vec[0];
            break;
        case '2':
            value=vec.front();
            break;
        case '3':
            value = *(vec.begin());
            break;
    }
    
    return 0;
}