#include<iostream>
#include<cstring>
using namespace std;
class employee
{
	static int x;
    char name[30];
    float basicSalary,bonusSalary,totalSalary;
    void totSalary(float b, float B)
    {
        totalSalary = b+B;
    }
public:
    static int valueX();
   // static void valueX(int);
    void addEmployee(employee *);
    void display() const;
    char searchEmployee(char *) const;
    employee(){ }
    employee(float b,float B): basicSalary{b},bonusSalary{B} { }
};
int employee::x;
int main()
{
	int x,i,y;
	cout<<"Enter No. of Employee Entries : ";
	cin>>x;
    employee *e=new employee[x];
    char c,n[30];
    r1:
	cout<<"\n1-Add Employee\n2-Display Employee Data\n0-Exit\nEnter your choice : ";
    cin>>c;
    getchar();
    switch(c)
    {
		case '1':
			r2:
			if(x!=employee::valueX())
			e[employee::valueX()].addEmployee(e);
			else
			{
				employee *dummy=new employee[x];
				for(i=0;i<x;i++)
				{
					dummy[i]=e[i];
				}
				delete[]e;
				y=x;
				x+=10;
				employee *e=new employee[x];
				for(i=0;i<y;i++)
				{
					e[i]=dummy[i];
				}
				goto r2;
			}
            goto r1;

        case '2':
        	if(!employee::valueX())
			{
				cout<<"\nNo employee entry is added! Add entries and try again\n";
				goto r1;
			}
        	cout<<"Enter name : ";
            cin.getline(n,30);
            for(i=0;i<x;i++)
            {
                if(e[i].searchEmployee(n))
                {
                    e[i].display();
                    goto r1;
                }
            }
            cout<<"\nName not found!\n";
            goto r1;

        case '0':
        	cout<<"\n......Exiting......\n";
			cout<<endl<<"............................................................."<<endl;
			cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
			cout<<endl<<"............................................................."<<endl;
			return 0;

        default :
            cout<<"\nInvalid Choice !\n";
            goto r1;
    }

    return 0;
}

void employee::addEmployee(employee *e)
{
	r3:
    cout<<"\nEnter your name : ";
    cin.getline(name,30);
    for(int i=0;i<employee::valueX();i++)
	{
		if(!strcmp(e[i].name,name))
		{
			cout<<"\nDuplicate Name Found !\n";
			goto r3;
		}
	}
    cout<<"Enter basic salary :";
    cin>>basicSalary;
    cout<<"Enter bonus salary :";
    cin>>bonusSalary;
    totSalary(basicSalary , bonusSalary);
    x++;
}
void employee::display() const
{
    cout<<"\nEmployee Name : "<<name<<"\nBasic Salary : "<<basicSalary<<"\nBonus Salary : "<<bonusSalary<<"\nTotal Salary : "<<totalSalary<<endl;
}
char employee::searchEmployee(char *n) const
{
    if(!strcmp(n,name))
        return '1';
    return '\0';
}
int employee::valueX()
{
    return x;
}
