#include"Sales_data.h"
#include<fstream>
#include<iostream>
using namespace std;
using std::cout;

void ProcessSalesData(istream &in, ostream &out){
    Sales_data total;    
    if(read(in, total)){
        Sales_data trans;
        while(read(in, trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    }
    else{
        cerr << "No data?!" << endl;
    }
}

int main(int argc, char* argv[]){
    ifstream input(argv[1]);
    ProcessSalesData(input, cout);    
    return 0;
}