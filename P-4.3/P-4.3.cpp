#include<iostream>
using namespace std;
int main()
{
	int m,n,i,j,temp,x,*p,*q;
	r1:
	cout<<"Enter limit of Array 1 : ";
	cin>>m;
	int *a=new int[m];
	if(!a)
	{
		goto r1;
	}
	for(i=0;i<m;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>a[i];
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	r2:
	cout<<"Ente limit of Array 2 : ";
	cin>>n;
	int *b=new int[n];
	if(!b)
	{
		goto r2;
	}
	for(i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>b[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i]>b[j])
			{
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
		}
	}
	x=m+n;
	p=a;
	q=b;
	r3:
	int *fa=new int[x];
	if(!fa)
	{
		goto r3;
	}
	for(i=0;i<x;i++)
	{
		if(q==&b[n])
		{
			fa[i]=*p;
			p++;
		}
		else if(p==&a[m])
		{
			fa[i]=*q;
			q++;
		}
		else if(*p>*q)
		{
			fa[i]=*q;
			q++;
		}
		else if(*q>*p)
		{
			fa[i]=*p;
			p++;
		}
		else
		{
			fa[i]=*p;
			p++;
			fa[++i]=*q;
			q++;
		}
	}

	cout<<endl<<"Merged sorted array elements : "<<endl;
	for(i=0;i<x;i++)
	{
		cout<<fa[i]<<" ";
	}
	cout<<"\n......Exiting......\n";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
	return 0;
}
