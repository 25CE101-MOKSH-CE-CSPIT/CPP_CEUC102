#include<iostream>
using namespace std;

void addBook();
void issueBook(int);
void returnBook(int);
void displayBook();

int x=0;

struct library
{
	int bookID,copies;
	char author[30],title[30];
}b[30];
int main()
{
	int c,ID;
	r1:
	cout<<endl<<"1-Add Book"<<endl<<"2-Issue Book"<<endl<<"3-Return Book"<<endl<<"4-Display Total Book"<<endl<<"0-Exit"<<endl<<"Enter Choice:";
	cin>>c;
	switch(c)
	{
		case 1:
			addBook();
			goto r1;
		case 2:
			cout<<"Enter ID : ";
			cin>>ID;
			issueBook(ID);
			goto r1;
		case 3:
			cout<<"Enter ID : ";
			cin>>ID;
			returnBook(ID);
			goto r1;
		case 4:
			displayBook();
			goto r1;
		case 0:
			cout<<endl<<"......Exiting......";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;
		default:
			cout<<endl<<"Invlaid Entry!"<<endl;
			goto r1;

	}
	return 0;
}

void addBook()
{
	cout<<"Enter Book ID : ";
	cin>>b[x].bookID;
	getchar();
	cout<<"Enter Book Title : ";
	cin.getline(b[x].title,30);
	cout<<"Enter Author Name : ";
	cin.getline(b[x].author,30);
	cout<<"Enter No. of copies : ";
	cin>>b[x].copies;
	x++;
}

void issueBook(int ID)
{
	int i;
	for(i=0;i<x;i++)
	{
		if(b[i].bookID==ID)
		{
			b[i].copies--;
			cout<<endl<<"Book Issued!"<<endl;
			return;
		}
	}
	cout<<endl<<"Book not found!"<<endl;
	return;
}

void returnBook(int ID)
{
	int i;
	for(i=0;i<x;i++)
	{
		if(b[i].bookID==ID)
		{
			b[i].copies++;
			cout<<endl<<"Book returned!"<<endl;
			return;
		}
	}
	cout<<endl<<"Book Not Found!"<<endl;
	return;
}

void displayBook()
{
	int i,c=0;
	cout<<endl<<"Book List : "<<endl;
	for(i=0;i<x;i++)
	{
		cout<<endl<<"Book ID : "<<b[i].bookID<<endl<<"Title : "<<b[i].title<<endl<<"Author : "<<b[i].author<<endl<<"No. of Copies : "<<b[i].copies<<endl;
		c+=b[i].copies;
	}
	cout<<endl<<"Total Book : "<<c<<endl;
	return;
}
