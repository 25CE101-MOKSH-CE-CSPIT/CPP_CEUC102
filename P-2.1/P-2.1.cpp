#include<iostream>
using namespace std;
class Rectangle
{
		int rectID;
		float length,width;
	public:
		void addRect(int,Rectangle *);
		void update();
		char searchRect(int);
		double area();
		double perimeter();
};
int main()
{
	int c,i,x=0,ID;
	Rectangle r[30];
	r1:
	cout<<"\n1-Add Rectangle\n2-Find Area\n3-Find Perimeter\n4-Update Rectangle\n0-Exit\nEnter Choice : ";
	cin>>c;
	switch(c)
	{
		case 1:
			r[x].addRect(x,r);
			x++;
			goto r1;
		case 2:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(r[i].searchRect(ID)=='y')
				{
					cout<<"\nArea = "<<r[i].area()<<endl;
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nRectangle not found!\n";
			}
			goto r1;
		case 3:
			cout<<"Enter ID:";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(r[i].searchRect(ID)=='y')
				{
					cout<<"\nPerimeter = "<<r[i].perimeter()<<endl;
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nRectangle not found!\n";
			}
			goto r1;
		case 4:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(r[i].searchRect(ID)=='y')
				{
					r[i].update();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nRectangle not found!\n";
			}
			goto r1;
		case 0:
			cout<<"\n......Exiting......";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<"\nInvalid value entered!\n";
			goto r1;
	}
	return 0;
}

void Rectangle::addRect(int x,Rectangle *r)
{
	int i;
	r2:
	cout<<"Enter Rectangle ID : ";
	cin>>rectID;
	for(i=0;i<x;i++)
	{
		if(r[i].searchRect(rectID)=='y')
		{
			cout<<"\nDuplicate Rectangle ID!\n";
			goto r2;
		}
	}
	cout<<"Enter Length : ";
	cin>>length;
	cout<<"Enter Width : ";
	cin>>width;
}

void Rectangle::update()
{
	cout<<"Enter length : ";
	cin>>length;
	cout<<"Enter width : ";
	cin>>width;
}

inline double Rectangle::area()
{
	return length*width;
}

inline double Rectangle::perimeter()
{
	return 2*(length+width);
}

inline char Rectangle::searchRect(int ID)
{
	if(ID==rectID)
		return 'y';
	return 'n';
}
