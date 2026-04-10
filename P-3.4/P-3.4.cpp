#include<iostream>
using namespace std;

template <class T>
void arr();

template <class T>
void maxN(T*,int);

template <class T>
void reverseA(T*,int);

template <class T>
void display(T*,int);

int main()
{
	int c;
	r1:
	cout<<"\nType of Array :\n1-Int\n2-Float\n3-Double\n4-Char\n0-Exit\nEnter Choice : ";
	cin>>c;
	switch(c)
	{
		case 1:
			arr<int>();
			goto r1;
		case 2:
			arr<float>();
			goto r1;
		case 3:
			arr<double>();
			goto r1;
		case 4:
			arr<char>();
			goto r1;
		case 0:
			cout<<"\n......Exiting......\n";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<"\nInvlaid Input!\n";

	}
	return 0;
}

template <class T>
void arr()
{
	int i,n,c;
	cout<<"Enter No. of Elements : ";
	cin>>n;
	T *a= new T[n];
	for(i=0;i<n;i++)
	{
		cout<<"Enter Element-"<<i+1<<" : ";
		cin>>a[i];
	}
	r2:
	cout<<"\nFunctionalities :\n1-Maximum\n2-Revese Array\n3-Display Array Elements\n0-Go Back\nEnter choice : ";
	cin>>c;
	switch(c)
	{
		case 1 :
			maxN(a,n);
			goto r2;
		case 2 :
			reverseA(a,n);
			goto r2;
		case 3 :
			display(a,n);
			goto r2;
		case 0 :
			return;
		default :
			cout<<"\nInvalid Input!\n";
			goto r2;

	}
}

template<class T>
void maxN(T*a,int n)
{
	int i=0;
	T maxn=a[0];
	while(i<n)
	{
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
		i++;
	}
	cout<<"\nMax : "<<maxn<<endl;
}


template <class T>
void reverseA(T*a,int n)
{
	int i;
	T temp;
	for(i=0;i<n/2;i++)
	{
		temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
	cout<<"\nArray is Reversed\n";
	display(a,n);
}

template <class T>
void display(T*a,int n)
{
	cout<<"\nArray Elements : ";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
