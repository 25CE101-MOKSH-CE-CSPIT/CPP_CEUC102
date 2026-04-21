#include<iostream>
#include<string>
using namespace std;
class vehicle
{
protected:
	int vehNo;
};
class fuel:virtual protected vehicle
{
protected:
	string fuel;
};
class brand:virtual protected vehicle
{
protected:
	string brand;
};
class car:protected fuel,protected brand
{
	static int x;
public:
	static int valueX();
	void display();
	void addCar(car*);
	bool searchCar(int);
};
int car::x;

int main()
{
	int choice,i,vn;
	car c[100];
	r1:
	cout<<"\n1-Add Car\n2-Display Details\n0-Exit\nEnter Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			c[car::valueX()].addCar(c);
			goto r1;
		case 2:
			cout<<"Enter Vehicle No. : ";
			cin>>vn;
			for(i=0;i<car::valueX();i++)
			{
				if(c[i].searchCar(vn))
				{
					c[i].display();
					break;
				}
			}
			if(i==car::valueX())
			{
				cout<<"\nNo car entry found !\n";
			}
			goto r1;
		case 0:
			cout<<"\n......Exiting......\n";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<"\nInvalid Choice!\n";
			goto r1;
	}
}


void car::display()
{
	cout<<"\nVehicle No. : "<<vehNo<<"\nFuel Type : "<<fuel<<"\nBrand Name : "<<brand<<endl;
}
void car::addCar(car *c)
{
	r2:
	cout<<"\nEnter Vehicle No : ";
	cin>>vehNo;
	for(int i=0;i<x;i++)
	{
		if(searchCar(vehNo))
		{
			cout<<"\nDuplicate Vehicle no. found!\n";
			goto r2;
		}
	}

	cout<<"Enter Fuel Type : ";
	cin>>fuel;

	cout<<"Enter Brand Name : ";
	cin>>brand;
	x++;
}
bool car::searchCar(int vn)
{
	return vn==vehNo;
}

int car::valueX()
{
	return x;
}
