#include<iostream>
using namespace std;

class circle;
class rectangle;

class shape
{
public:
	virtual float area(){return 0;}
};
class rectangle : public shape
{
	float a,b;
public :
	float area();
	rectangle(){}
	rectangle(float x, float y):a{x},b{y} {}
	~rectangle(){}
};

class circle : public shape
{
	float radius;
public:
	float area();
	circle(){}
	circle(float r):radius{r}{}
	~circle(){}
};

int main()
{
	float a,b,r;
	int i,n,m;
	cout<<"Enter no. of rectnagles : ";
	cin>>n;
	cout<<"Enter no. of circles : ";
	cin>>m;

	rectangle *rect= new rectangle[n];
	circle *cir=new circle[m];

	for(i=0;i<n;i++)
	{
		cout<<"Enter rect "<<i+1<<" parameters : ";
		cin>>a>>b;
		rect[i]=rectangle(a,b);
	}
	for(i=0;i<m;i++)
	{
		cout<<"Enter Circle "<<i+1<<" radius : ";
		cin>>r;
		cir[i]=circle(r);
	}
	for(i=0;i<n;i++)
	{
		cout<<"Area of Rect "<<i+1<<" : "<<rect[i].area()<<endl;
	}
	for(i=0;i<m;i++)
	{
		cout<<"Area of Rect "<<i+1<<" : "<<cir[i].area()<<endl;
	}
	delete[] rect;
	delete[] cir;
	cout<<endl<<"......Exiting......";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
	return 0;
}

float rectangle::area()
{
	return a*b;
}
float circle::area()
{
	return (3.14f)*radius*radius;
}