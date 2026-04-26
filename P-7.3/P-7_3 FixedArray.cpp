#include<iostream>
using namespace std;
class celsius;
class fahrenheit
{
	float F;
public:
	float valuef();
	operator celsius();
	friend bool operator==(celsius,fahrenheit);
	fahrenheit(){}
	fahrenheit(float f):F{f} {}
	~fahrenheit(){}
};
class celsius
{
	float C;
public:
	float valuec();
	operator fahrenheit();
	friend bool operator==(celsius,fahrenheit);
	celsius(){}
	celsius(float c):C{c} {}
	~celsius(){}
};

int main()
{
	int n;
    cout<<"Enter number of values: ";
    cin>>n;

    celsius arr[100];

    float a;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter temperature in Fahrenheit: ";
        cin>>a;

        fahrenheit F(a);
        arr[i] = F;
    }

    cout<<"\nStored Values:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i].valuec()<<" C"<<endl;
    }
	cout<<"\n......Exiting......\n";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
    return 0;
}

inline fahrenheit::operator celsius()
{
	return celsius(((F-32)*5)/9);
}
inline celsius::operator fahrenheit()
{
	return fahrenheit((C*9)/5+32);
}

bool operator==(celsius c,fahrenheit f)
{
	celsius temp=f;
	return c.C==temp.C;
}

float fahrenheit::valuef()
{
	return F;
}

float celsius::valuec()
{
	return C;
}