#include<iostream>
#include<queue>
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
	 queue<celsius> q;

    float a;
    int n;
    cout<<"How many values? ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter temperature in Fahrenheit: ";
        cin>>a;
        fahrenheit F(a);

        celsius C = F;
        q.push(C);
    }

    cout<<"\nProcessing Queue:\n";
    while(!q.empty())
    {
        cout<<q.front().valuec()<<" C"<<endl;
        q.pop();
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