#include<iostream>
#include<string>
using namespace std;
class person
{
protected:
	string name;
	int age;
public:
	person(){}
	person(string n, int a):name{n},age{a}{}
	void display();
};

class employee : public person
{
protected:
	int empID;
public:
	employee(){}
	employee(int ID,string n,int a):empID{ID},person(n,a){}
	void display();
};

class manager : public employee
{
	string dept;
public:
	manager() {}
	manager( string d , int ID , string n , int a ):dept{d},employee(ID,n,a){}
	void display();
};

int main()
{
	string n,d;
	int ID,a;
	cout<<"Enter Name : ";
	getline(cin,n);
	cout<<"Enter Dept : ";
	getline(cin,d);
	cout<<"Enter Emp ID : ";
	cin>>ID;
	cout<<"Enter Age : ";
	cin>>a;
	manager m(d,ID,n,a);

	m.display();
	m.employee::display();
	m.person::display();

	cout<<"\n......Exiting......\n";
	cout<<endl<<"............................................................."<<endl;
	cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
	cout<<endl<<"............................................................."<<endl;
	return 0;
}

void person::display()
{
	cout<<"\nName : "<<name<<"\nAge : "<<age<<endl;
}

void employee::display()
{
	cout<<"\nEmplyee ID : "<<empID<<endl;
}
void manager::display()
{
	cout<<"\nDepartment : "<<dept<<endl;
}
