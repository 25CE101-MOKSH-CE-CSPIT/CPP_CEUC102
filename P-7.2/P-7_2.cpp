#include<iostream>
#include<string>
using namespace std;

class complex
{
	float a,b;
public:
	complex operator+(complex c)
	{
		return complex((c.a+this->a),(c.b+this->b));
	}
	complex operator-(complex c)
	{
		return complex((this->a-c.a),(this->b-c.b));
	}
	void operator+=(complex c)
	{
		this->a+=c.a;
		this->b+=c.b;
	}
	void operator-=(complex c)
	{
		this->a-=c.a;
		this->b-=c.b;
	}
	void display()const
	{
		if(b<0)
			cout<<a<<" - "<<-b<<" i"<<endl;
		else
		cout<<a<<" + "<<b<<" i"<<endl;
	}
	complex(){}
	complex(int o)
	{
		string z,p,q;
		int i=0;
		cout<<"Enter Complex No. (a+bi) :  ";
		getline(cin,z);
		do
		{
			if(z[i]==' ')
			{
				i++;
				continue;
			}
			p+=z[i];
			i++;
		}while(z[i]!='+');
		i++;
		a=stoi(p);
		do
		{
			if(z[i]==' ')
			{
				i++;
				continue;
			}
			q+=z[i];
			i++;
		}while(z[i]!='i');
		b=stoi(q);

	}
	complex(float x,float y):a{x},b{y} {}
	~complex(){}
};

int main()
{
	complex z1(1),z2(1);
	complex z3;
	cout<<endl;
	z1.display();
	z2.display();

	z3=z1+z2;
	cout<<"\nSum : ";
	z3.display();

	z3=z1-z2;
	cout<<"\nDifference : ";
	z3.display();


	cout<<"\n......Exiting......\n";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
	return 0;
}