#include<iostream>
#include<string>
#include<sstream>
using std::cin;
using std::cout;
using std::istream;
using std::string;
istream& getInput(istream& is);
int main(){
    std::istringstream is("a red fox jump");
    
    getInput(is);
    return 0;
}

istream& getInput(istream& is){
    string value;
    while(is >> value){
        cout << value;
    }
    is.clear();
    return is;
}