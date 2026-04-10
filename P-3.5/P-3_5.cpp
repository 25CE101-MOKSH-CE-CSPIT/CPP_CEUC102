#include<iostream>
#include<string>
using namespace std;

int main()
{
	int i,n,k,l,j,x;
	string s;
	cout<<"Enter the No. : ";
	cin>>n;
	cout<<"Enter no. of times concatination is required : ";
	cin>>k;
	for(i=1;i<=k;i++)
	{
		s+=to_string(n);
	}
	cout<<"Concatenated No. : "<<s<<endl;
	l=s.length();

	while(l!=1)
	{
		x=0;
		for(j=0;j<l;j++)
		{
			x+=(int)(s[j]-'0');

		}
		s=to_string(x);
		l=s.length();
	}
	cout<<"\nSuper Digit = "<< x <<endl;
	cout<<"\n......Exiting......\n";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
}
