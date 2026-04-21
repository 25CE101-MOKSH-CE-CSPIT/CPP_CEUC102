#include<iostream>
using namespace std;

class shape
{
	float radius;
protected:
	float radiusV(){ return radius; }
public:
	shape(){}
	shape(float r):radius(r){}
};

class circle : public shape
{
	static int x;
	int circleID;
public:
	static int valueX();
	circle(){}
	circle(float r):shape(r){}
	float area();
	bool searchCircle(int);
	void addCircle(circle*);
};

int circle::x = 0;

int main()
{
	int i,n,choice,ID;
	cout<<"Enter no. of circles : ";
	cin>>n;
	circle *c=new circle[n];
	r1:
	cout<<"\n1-Add Circle\n2-Display Area\n0-Exit\nEnter Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			c[circle::valueX()].addCircle(c);
			goto r1;
		case 2:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<circle::valueX();i++)
			{
				if(c[i].searchCircle(ID))
				{
					cout<<"\nArea : "<<c[i].area()<<endl;
					break;
				}
			}
			if(i==circle::valueX())
			{
				cout<<"\nNo circle found !\n";
			}
			goto r1;
		case 0:
			cout<<"\n......Exiting......\n";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<"\nInvalid Choice\n";
			goto r1;
	}
}

float circle::area()
{
	return (3.14f)*radiusV()*radiusV();
}

bool circle::searchCircle(int ID)
{
	return ID==circleID;
}

void circle::addCircle(circle *c)
{
	float r;
	int id;

	r2:
	cout<<"Enter Circle ID : ";
	cin>>id;

	for(int i=0;i<x;i++)
	{
		if(c[i].searchCircle(id))
		{
			cout<<"\nDuplicate Circle ID Found !\n";
			goto r2;
		}
	}

	cout<<"Enter Radius : ";
	cin>>r;

	c[x] = circle(r);
	c[x].circleID = id;
	x++;
}

int circle::valueX()
{
	return x;
}
