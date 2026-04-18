#include<iostream>
using namespace std;
class point
{
	float x,y;
	int pointID;
	static int n;
public:
	point & moveP(float , float);
	void addP(point*);
	char searchP(int);
	void displayP();
	static int valueN();
};

int point::n;

int main()
{
	int c,n,ID,i,dummy;
	float x,y;
	cout<<"Enter no. Points : ";
	cin>>n;
	point *p=new point[n];
	cout<<endl;
	r1:
	cout<<"\n1-Add Point\n2-Change Coordinates\n3-Display Point ID\n0-Exit\nEnter you choice :";
	cin>>c;

	switch(c)
	{
		case 1:
			if(point::valueN()<n)
			p[point::valueN()].addP(p);
			else
			{
				point *d=new point[n];
				for(i=0;i<point::valueN();i++)
				{
					d[i]=p[i];
				}
				delete[] p;
				dummy=n;
				n+=5;
				point *p=new point[n];
				for(i=0;i<dummy;i++)
				{
					p[i]=d[i];
				}
				delete[] d;
			}
			goto r1;
		case 2:
			cout<<"Enter point ID : ";
			cin>>ID;
			for(i=0;i<point::valueN();i++)
			{
				if(p[i].searchP(ID))
				{
					cout<<"Enter New X : ";
					cin>>x;
					cout<<"Enter New Y : ";
					cin>>y;
					p[i].moveP(x,y);
					break;
				}
			}
			if(i==point::valueN())
			{
				cout<<"\nPoint Entry not found !\n";
			}
			goto r1;
		case 3:
			cout<<"Enter point ID : ";
			cin>>ID;
			for(i=0;i<point::valueN();i++)
			{
				if(p[i].searchP(ID))
				{
					p[i].displayP();
					break;
				}
			}
			if(i==point::valueN())
			{
				cout<<"\nPoint Entry not found !\n";
			}
			goto r1;
		case 0:
			cout<<"\n......Exiting......\n";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<"\nInvalid Choice !\n";
			goto r1;
	}
}

point & point::moveP(float dx,float dy)
{
	x=dx;
	y=dy;
	return *this;
}

void point::addP(point *p)
{
	r2:
	cout<<"Enter point ID : ";
	cin>>pointID;
	for(int i=0;i<point::valueN();i++)
	{
		if(p[i].searchP(pointID))
		{
			cout<<"\nDuplicate ID found!\n";
			goto r2;
		}
	}
	cout<<"Enter X : ";
	cin>>x;
	cout<<"Enter Y : ";
	cin>>y;
	n++;
}

char point::searchP(int ID)
{
	if(pointID==ID)
		return '1';
	return '\0';
}

void point::displayP()
{
	cout<<"\nPoint : "<<pointID<<"\nX : "<<x<<"\nY : "<<y<<endl;
}

int point::valueN()
{
	return n;
}
