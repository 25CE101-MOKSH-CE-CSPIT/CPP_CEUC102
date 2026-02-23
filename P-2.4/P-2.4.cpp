#include<iostream>
#include<cstring>
using namespace std;
class item
{
	long int itemID;
	float price;
	int quantity;
	char itemName[30];

public:
	item()
	{
		itemID=0;
		price=0.0f;
		quantity=0;
		strcpy(itemName,"xyz");
	}
	void addItem(int,item *);
	void incStock();
	void decStock();
	char validateStock(int);
	void display();
	char searchItem(long int);

};
int main()
{
	int ID,i,c,x=0;
	item Item[30];
	r1:
	cout<<"\n1-Add item\n2-Increase Stock\n3-Decrease stock\n4-Display item details\n0-Exit\nEnter choice : ";
	cin>>c;
	switch(c)
	{

		case 1:
			Item[x].addItem(x,Item);
			x++;
			goto r1;
		case 2:
			cout<<"Enter ID : " ;
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(Item[i].searchItem(ID)=='y')
				{
					Item[i].incStock();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nProduct not found!\n";
			}
			goto r1;
		case 3:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(Item[i].searchItem(ID)=='y')
				{
					Item[i].decStock();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nProduct not found!\n";
			}
			goto r1;
		case 4:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(Item[i].searchItem(ID)=='y')
				{
					Item[i].display();
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nProduct not found!\n";
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
	return 0;
}

void item::addItem(int x,item *Item)
{
	int i;
	r2:
	cout<<"\nEnter ID : ";
	cin>>itemID;
	for(i=0;i<x;i++)
	{
		if(Item[i].searchItem(itemID)=='y')
		{
			cout<<"\nDuplicate product ID found!\n";
			goto r2;
		}
	}
	cout<<"Enter Name : ";
	cin>>itemName;
	r4:
	cout<<"Enter initial quantity : ";
	cin>>quantity;
	if(quantity<0)
	{
		cout<<"\nQunatity should be non negative!\n";
		goto r4;
	}
	r5:
	cout<<"Enter price : ";
	cin>>price;
	if(price<=0)
	{
		cout<<"\nPrice should be non-zero positive integer!\n";
		goto r5;
	}
}

void item::incStock()
{
	int qty;
	r3:
	cout<<"Enter the newly recieved stock qty.: ";
	cin>>qty;
	if(qty>0)
	{
		quantity+=qty;
		cout<<"\nStock successfully increased by "<<qty<<endl;
	}
	else
	{
		cout<<"\nQuantity should be non zero positive integer!\n";
		goto r3;
	}
}

void item::decStock()
{
	int qty;
	r3:
	cout<<"Enter the recently sold stock qty.: ";
	cin>>qty;
	if(qty>0)
	{
		if(validateStock(qty)=='y')
		{
			quantity-=qty;
			cout<<"\nStock successfully decreased by "<<qty<<endl;
		}
		else
		{
			cout<<"\nStock is insufficient!\n";
			return;
		}
	}
	else
	{
		cout<<"\nQuantity should be non zero positive integer!\n";
		goto r3;
	}
}

inline char item::validateStock(int qty)
{
	if(quantity>=qty)
		return 'y';
	return'n';
}

inline char item::searchItem(long int ID)
{
	if(ID==itemID)
		return 'y';
	return 'n';
}

inline void item::display()
{
	cout<<"\nProduct ID : "<<itemID<<"\nProduct name : "<<itemName<<"\nQuantity : "<<quantity<<"\nPrice : "<<price<<endl;
}
