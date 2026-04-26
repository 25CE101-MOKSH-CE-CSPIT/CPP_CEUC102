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
	float a;
	cout<<"Enter Tempreture in Fahrenheit : ";
	cin>>a;
	fahrenheit F(a);
	cout<<"Enter Tempreture in Celsius : ";
	cin>>a;
	celsius C(a);
	celsius C1=F;
	fahrenheit F1=C;
	cout<<"Covesion of "<< F.valuef()<<"F into celsius : "<<C1.valuec()<<"C"<<endl;
	cout<<"Covesion of "<< C.valuec()<<"C into fahrenheit : "<<F1.valuef()<<"F"<<endl;
	cout<<"Comparing "<<F.valuef()<<" and "<<C.valuec()<<" : ";
	(F==C)? cout<<"Equal" : cout<<"Not equal";
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