#include<vector>
using namespace std;

int main(){
    vector<int> data = {0,1,2,3,4};
    auto iter = data.begin();
    while(iter != data.end()){
        if(*iter % 2 == 0){
            iter = data.insert(iter, *iter);
            ++iter;
        }
    }
    return 0;
}