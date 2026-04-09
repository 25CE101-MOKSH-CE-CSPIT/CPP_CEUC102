#include<iostream>
using namespace std;

int main()
{
    int n,c,i,x,dummy;
    r2:
    cout<<"Enter length of array to be created : ";
    cin>>n;
    if(n<=0)
    {
        goto r2;
    }
    int *a=new int[n];
    if(!a)
    {
        cout<<"\nArray allocation failed!\n";
        goto r2;
    }
    r1:
    cout<<"\n1-Enter Data in elements\n2-Add one element at end\n3-Remove a particular element\n4-Display All Elements\n0-Exit\nEnter choice : ";
    cin>>c;
    switch(c)
    {
        case 1:
            cout<<"Enter Element No. : ";
            cin>>x;
            x--;
            if(x<n&&x>=0)
            {
                cout<<"Enter the Data : ";
                cin>>a[x];
            }
            else
            {
                cout<<"\nInvalid Element No. entered !\n";
            }
            goto r1;
            case 2:
            {

                int *d = new int[n];
                if(!d)
                {
                    cout<<"\nArray allocation failed!\n";
                    goto r1;
                }
                for(i=0;i<n;i++)
                {
                    d[i]=a[i];
                }
                delete[] a;
                x=n;
                int *a = new int[++n];
                if(!a)
                {
                    cout<<"\nArray allocation failed!\n";
                    goto r1;
                }
                for(i=0;i<x;i++)
                {
                    a[i]=d[i];
                }
                delete[] d;
                goto r1;
            }

        case 3:
            {
                r3:
                cout<<"Enter Element No. : ";
                cin>>x;
                x--;
                if(!(x>=0&&x<n))
                {
                    cout<<"\nInvalid Element No. entered\n";
                    goto r3;
                }
                int *d = new int[n];
                if(!d)
                {
                    cout<<"\nArray allocation failed!\n";
                    goto r1;
                }
                dummy=0;
                for(i=0;i<n;i++)
                {
                    if(i==x)
                        continue;
                    d[dummy++]=a[i];
                }
                delete[] a;
                int *a = new int[--n];
                if(!a)
                {
                    cout<<"\nArray allocation failed!\n";
                    goto r1;
                }
                for(i=0;i<n;i++)
                {
                    a[i]=d[i];
                }
                delete[] d;
                goto r1;
            }

        case 4:
            cout<<"\nArray Elements : \n";
            for(i=0;i<n;i++)
            {
                cout<<"Element-"<<i+1<<" : "<<a[i]<<endl;
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

}
