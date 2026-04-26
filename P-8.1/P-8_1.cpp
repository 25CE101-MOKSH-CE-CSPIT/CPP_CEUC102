#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    double a,b,result = 0;
    cin >> a >> b;
    try
    {
        if(b!=0)
        {
        result=a/b;
        }
        else
        {
            throw std::runtime_error("Division by 0 is not allowed!");
        }
    }
    catch(exception &e)
    {
        cerr << e.what() << endl;
    }
    cout << result;
    cout<<endl<<"......Exiting......";
    cout<<endl<<"............................................................."<<endl;
    cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
    cout<<endl<<"............................................................."<<endl;
    return 0;
}
