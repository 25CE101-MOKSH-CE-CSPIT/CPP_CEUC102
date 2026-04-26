#include <iostream>
#include <iomanip>
using namespace std;


ostream& currency(ostream& os) {
    os << "₹";
    return os;
}

int main() {
    const int n = 3;
    string names[n] = {"Ramesh", "Suresh", "Mahesh"};
    int marks[n] = {92, 85, 78};
    double fees[n] = {150000.50, 4000000.75, 50000.00};


    cout << setfill('=') << setw(45) << "" << endl;
    cout << setfill(' ');
    cout << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Fees" << endl;
    cout << setfill('-') << setw(45) << "" << endl;
    cout << setfill(' ');


    for (int i = 0; i < n; ++i) {
        cout << left << setw(15) << names[i]
             << setw(10) << marks[i]
             << currency << fixed << setprecision(2) << setw(15) << fees[i] << endl;
    }

    cout << setfill('=') << setw(45) << "" << endl;
    cout<<endl<<"......Exiting......";
    cout<<endl<<"............................................................."<<endl;
    cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
    cout<<endl<<"............................................................."<<endl;
    return 0;
}