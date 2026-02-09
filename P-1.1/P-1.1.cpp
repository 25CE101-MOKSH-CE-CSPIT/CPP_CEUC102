#include<iostream>
using namespace std;
class Wallet
{
	long int walletID;
	char userName[20];
	float currentBalance;

	public:
	void addUser(int);
	void loadMoney();
	void transferMoney(Wallet &);
	void viewBalance();
	char searchUser(long int);
};
int main()
{
	int c,x=0,ID,i,j;
	Wallet u[50];
	r1:
	cout<<"\n1-Add User\n2-Load Money\n3-Transfer Money\n4-Current Balance\n0-Exit\nEnter Choice:";
	cin>>c;
	switch(c)
	{
		case 1:
			u[x].addUser(x);
			x++;
			goto r1;
		case 2:
			cout<<"Enter UID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(u[i].searchUser(ID)=='y')
				{
					u[i].loadMoney();
					break;
				}

			}
			if(i==x)
			{
				cout<<"\nAccount not found!\n";
			}
			goto r1;
		case 3:
			cout<<"Enter Sender ID : ";
			cin>>ID;

			for(i=0;i<x;i++)
			{
				if(u[i].searchUser(ID)=='y')
				{
					cout<<"Enter Reciever ID : ";
					cin>>ID;
					for(j=0;j<x;j++)
					{
						if(u[j].searchUser(ID)=='y')
						{
							u[i].transferMoney(u[j]);
							break;
						}
					}
					if(j==x)
					{
						cout<<"\nReciever Account not found!\n";
					}
					break;
				}
			}
			if(i==x)
			{
				cout<<"\nSender Account not found!\n";
			}
			goto r1;
		case 4:
			cout<<"Enter ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(u[i].searchUser(ID)=='y')
				{
					u[i].viewBalance();
					break;
				}

			}
			if(i==x)
			{
				cout<<"\nAccount not found\n";
			}
			goto r1;
		case 0:
			cout<<endl<<"......Exiting......";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<endl<<"Invalid Entry!"<<endl;
			break;
	}
	return 0;
}

void Wallet::addUser(int x)
{
	int i;
	r2:
	cout<<"\nEnter Wallet ID : ";
	cin>>walletID;
	for(i=0;i<x;i++)
	{
		if(searchUser(walletID)=='y')
		{
			cout<<"\nDuplicate ID Found!\n";
			goto r2;
		}

	}
	getchar();
	cout<<"Enter User Name : ";
	cin.getline(userName,20);
	cout<<"Enter Current Balance : ";
	cin>>currentBalance;
}

void Wallet::loadMoney()
{
	int amt;
	cout<<"Enter the amount to Load : ";
	cin>>amt;
	currentBalance+=amt;
}

void Wallet::transferMoney(Wallet &u)
{
	int amt;
	cout<<"Enter the amount to be Transfered : ";
	cin>>amt;
	if(amt<=currentBalance)
	{
		currentBalance-=amt;
		u.currentBalance+=amt;
		cout<<"\nAmount successfully transfered.\n";
	}
	else
	{
		cout<<"\nNo Sufficient Balance in Account : "<<walletID<<endl;
	}
}

void Wallet::viewBalance()
{
	cout<<"\nBalance : "<<currentBalance<<endl;
}

char Wallet::searchUser(long int ID)
{
	if(ID==walletID)
		return 'y';
	return 'n';
}
