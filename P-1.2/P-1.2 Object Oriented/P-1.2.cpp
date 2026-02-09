#include<iostream>
#include<string.h>
using namespace std;
class library
{
	int bookID,copies;
	string title,author;

	public:
	void addBook();
	void issueBook();
	void returnBook();
	void displayBook(int &);
	char searchBook(int );

};
int main()
{
	int i,c,ID,x=0,y;
	library b[30];
	r1:
	cout<<endl<<"1-Add Book"<<endl<<"2-Issue a Book"<<endl<<"3-Return a Book"<<endl<<"4-Display Total Books"<<endl<<"0-Exit"<<endl<<"Enter Choice : ";
	cin>>c;
	switch(c)
	{
		case 1:
			b[x].addBook();
			x++;
			break;
		case 2:
			cout<<"Enter Book Id : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(b[i].searchBook(ID)=='y')
				{
					b[i].issueBook();
					goto r1;
				}
			}
			if(i==x)
			{
				cout<<endl<<"Book not Found!"<<endl;
			}
			break;
		case 3:
			cout<<"Enter Book ID : ";
			cin>>ID;
			for(i=0;i<x;i++)
			{
				if(b[i].searchBook(ID)=='y')
				{
					b[i].returnBook();
					goto r1;
				}
			}
			if(i==x)
			{
				cout<<endl<<"Book not Found!"<<endl;
			}
			break;
		case 4:
			y=0;

			cout<<endl<<"Book List :"<<endl;
			for(i=0;i<x;i++)
			{
				b[i].displayBook(y);
			}
			cout<<endl<<"Total No. of Books : "<<y<<endl;
			break;
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
}

void library::addBook()
{
	getchar();
	cout<<"Enter Book Title : ";
	getline(cin,title);
	cout<<"Enter Author\'s Name : ";
	getline(cin,author);
	cout<<"Enter Book ID : ";
	cin>>bookID;
	cout<<"Enter No. of copies : ";
	cin>>copies;
}
void library::issueBook()
{
	if(copies>0)
	{
		copies--;
		cout<<endl<<"Book issued."<<endl;
	}
	else
	{
		cout<<endl<<"No copies available!"<<endl;
	}
}

inline void library::returnBook()
{
	copies++;
	cout<<endl<<"Book Returned."<<endl;
}
inline void library::displayBook(int &u)
{
	cout<<endl<<"Book ID : "<<bookID<<endl<<"Title : "<<title<<endl<<"Author : "<<author<<endl<<"No. of Copies : "<<copies<<endl;
	u+=copies;
}

inline char library::searchBook( int ID )
{
	if( ID == bookID )
		return 'y';
	return 'n';
}
