#include<iostream>
using namespace std;
class Account
{
	long int accountNo;
	char name[30];
	float currentBalance;
	static int x;
public:
	void addAccount(Account *);
	char searchAccount(long int ID)const;
	void transferMoney(Account &a);
	void display() const;
	static int valueX();
	static void totAccounts();
};
int Account::x;
int main()
{
	int c,n,j,i,x;
	long int an;
	r4:
	cout<<"Enter no of accounts : ";
	cin>>n;
	Account *a=new Account[n];
	if(!a)
	{
		cout<<"\nUnable to Allocate memory!\n";
		goto r4;
	}
	r1:
	cout<<"\n1-Add Account\n2-Transfer Money\n3-Display Summary of an account\n4-Track no. of total accounts\n0-Exit\nEnter Choice : ";
	cin>>c;
	switch(c)
	{
		case 1:
			r5:
			if(Account::valueX()!=n)
			{
				a[Account::valueX()].addAccount(a);
			}
			else
			{
				Account *d=new Account[n];
				if(!d)
				{
					cout<<"\nUnable to Allocate new memory! Memory limit Reached!\n";
					goto r1;
				}
				for(i=0;i<n;i++)
				{
					d[i]=a[i];
				}
				delete[] a;
				x=n;
				n+=5;
				Account *a=new Account[n];
				if(!a)
				{
					cout<<"\nUnable to Allocate new memory! Memory limit Reached!\n";
					delete[] d;
					goto r1;
				}
				for(i=0;i<x;i++)
				{
					a[i]=d[i];
				}
				delete[] d;
				goto r5;

			}
			goto r1;

		case 2:
			cout<<"Enter your Account no. : ";
			cin>>an;
			for(i=0;i<Account::valueX();i++)
			{
				if(a[i].searchAccount(an))
				{
					cout<<"Enter second Account no. : ";
					cin>>an;
					for(j=0;j<Account::valueX();j++)
					{
						if(a[j].searchAccount(an))
						{
							a[i].transferMoney(a[j]);
							break;
						}
					}
					if(j==Account::valueX())
					{
						cout<<"\nAccount doesn't exist!\n";
					}
					break;
				}
			}
			if(i==Account::valueX())
			{
				cout<<"\nAccount doesn't exist!\n";
			}
			goto r1;

		case 3:
			cout<<"Enter Account no. : ";
			cin>>an;
			for(i=0;i<Account::valueX();i++)
			{
				if(a[i].searchAccount(an))
				{
					a[i].display();
					break;
				}
			}
			if(i==Account::valueX())
			{
				cout<<"\nAccount doesn't exist!\n";
			}
			goto r1;
		case 4:
			Account::totAccounts();
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

void Account::addAccount(Account *a)
{
	r2:
	cout<<"\nEnter Account No. : ";
	cin>>accountNo;
	for(int i=0;i<x;i++)
	{
		if(a[i].searchAccount(accountNo))
		{
			cout<<"\nDuplicate Account no. found !\n";
			goto r2;
		}
	}
	getchar();
	cout<<"Enter name : ";
	cin.getline(name,30);
	cout<<"Enter Current Balance : ";
	cin>>currentBalance;
	x++;
}
char Account::searchAccount(long int an) const
{
	if(an==accountNo)
		return '1';
	else
		return '\0';
}

void Account::transferMoney(Account &a)
{
	float amount;
	r3:
	cout<<"Enter amount to be transfered : ";
	cin>>amount;
	if(amount>currentBalance)
	{
		cout<<"\nInsufficient Balance!\n";
		goto r3;
	}
	else if(amount<=0)
	{
		cout<<"\nInvalid transaction!\n";
		goto r3;
	}
	currentBalance-=amount;
	a.currentBalance+=amount;
	cout<<"\nAmount - "<<amount<<" units is transfered from "<<name<<"\'s account to "<<a.name<<"\'s account."<<endl;
}

void Account::display() const
{
	cout<<"\nAccount Summary : \nAccount No. : "<<accountNo<<"\nName : "<<name<<"\nCurrent Balance : "<<currentBalance<<endl;
}

int Account::valueX()
{
	return x;
}

void Account::totAccounts()
{
	cout<<"\nTotal Accounts : "<<x<<endl;
}
