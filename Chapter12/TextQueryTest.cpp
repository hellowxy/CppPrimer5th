#include<iostream>
#include<fstream>
#include"TextQuery.h"
#include"QueryResult.h"
#include<string>
using namespace std;


void runQueries(ifstream &infile){
    TextQuery tq(infile);
    while(true){
        cout << "enter word to look for, or q to quit:";
        string s;
        if(!(cin >> s) || s == "q"){
            break;
        }
        print(cout, tq.query(s)) << endl;
    }

}

int main(){
    string filename = "./demo.txt";
    ifstream infile(filename);
    runQueries(infile);
    return 0;
}