#include"Sales_data.h"
#include<fstream>
#include<iostream>
using namespace std;

void ProcessSalesData(istream &in, ostream &out){
    Sales_data total;    
    if(read(in, total)){
        Sales_data trans;
        while(read(in, trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else{
        std::cerr << "No data?!" << endl;
    }
}

int main(int argc, char* argv[]){
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    ProcessSalesData(input, output);
    return 0;
}