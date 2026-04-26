#include<iostream>
using namespace std;
void add(int,int);
void add(int,int,int);
void add(float,float);
void add(float,float,float);
void add(float,int);

int main()
{
	int a,b,c;
	float a1,b1,c1;
	cout<<"Enter 3 integers : ";
	cin>>a>>b>>c;
	cout<<"Enter 3 float No. : ";
	cin>>a1>>b1>>c1;
	add(a,b);
	add(a,b,c);
	add(a1,b1);
	add(a1,b1,c1);
	add(a1,a);
	cout<<"\n......Exiting......\n";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
	return 0;
}

inline void add(int a,int b)
{
	cout<<"Sum of two integers "<<a<<" and "<<b<<" : "<<a+b<<endl;

}

inline void add(int a, int b,int c)
{
	cout<<"Sum of three integers "<<a<<" , "<<b<<" and "<<c<<" : "<<a+b+c<<endl;
}

inline void add(float a,float b,float c)
{
	cout<<"Sum of three float No. "<<a<<" , "<<b<<" and "<<c<<" : "<<a+b+c<<endl;
}

inline void add(float a,float b)
{
	cout<<"Sum of two float No. "<<a<<" and "<<b<<" : "<<a+b<<endl;
}

inline void add(float a,int b)
{
	cout<<"Sum of a float No. "<<a<<" and integer "<<b<<" : "<<a+b<<endl;
}