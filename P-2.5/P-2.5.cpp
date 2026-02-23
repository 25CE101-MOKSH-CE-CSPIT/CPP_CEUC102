#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class loanAccount
{
	long int loanID;
	string name;
	float loanAmt,interest;
	int tenure;
public:
	void addAccount(int, loanAccount *);
	char searchAccount(long int) const;
	float calculateEMI();
	loanAccount():loanID{0},name{"xyz"},loanAmt{0},interest{0},tenure{0} { }
	loanAccount(long int ID,string n,float amt,float irate,int t):loanID{ID},name{n},loanAmt{amt},interest{irate},tenure{t} { }
};

int main()
{
	loanAccount a[20];
	int i,x=0,c;
	long int ID;
	r1:
	cout<<"\n1-Add Account\n2-calculate EMI\n0-Exit\nEnter Choice:";
	cin>>c;
	switch(c)
	{
		case 1:
			a[x].addAccount(x,a);
			x++;
			goto r1;
		case 2:
			cout<<"Enter ID:";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(a[i].searchAccount(ID)=='y')
				{
					cout<<"\nEMI : "<<a[i].calculateEMI()<<endl;
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nAccount not found\n";
			}
			goto r1;
		case 0:
			cout<<"\n......Exiting......\n";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<"Invalid Choice!";
			goto r1;

	}
}

char loanAccount::searchAccount(long int ID) const
{
	if(ID==loanID)
		return 'y';
	return 'n';
}

void loanAccount::addAccount(int x,loanAccount *a)
{
	int i,t;
	long int lid;
	float lamt,irate;
	string n;
	r2:
	cout<<"Enter loan ID : ";
	cin>>lid;
	for(i=0;i<x;i++)
	{
		if(a[i].searchAccount(lid)=='y')
		{
			cout<<"\nDuplicate ID found\n";
			goto r2;
		}
	}
	getchar();
	cout<<"Enter Name : ";
	getline(cin,n);
	cout<<"Enter loan Amt : ";
	cin>>lamt;
	cout<<"Enter Interest : ";
	cin>>irate;
	cout<<"Enter Tenure : ";
	cin>>t;
	a[x]=loanAccount(lid,n,lamt,irate,t);
}

inline float loanAccount::calculateEMI()
{
	float c=pow((1+interest),tenure);
	return (loanAmt*interest*c)/(c-1);
}
