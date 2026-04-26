#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main()
{
    string itemName, line;
    int quantity;
    fstream file("inventory.txt", ios::in | ios::out | ios::app);
    if (!file)
    {
        cerr << "File could not be opened!" << endl;
        return 1;
    }
    int choice;
    while (true)
    {
        cout << "1. Add Item to Inventory" << endl;
        cout << "2. View All Items" << endl;
        cout << "3. Search Item" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            cout << "Enter item name: ";
            getline(cin, itemName);
            cout << "Enter quantity: ";
            cin >> quantity;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            file.clear();
            file.seekp(0, ios::end);
            file << itemName << " " << quantity << endl;
            file.flush();
            break;
        case 2:
            file.clear();
            file.seekg(0, ios::beg);
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.clear();
            break;
        case 3:
            cout << "Enter item name to search: ";
            getline(cin, itemName);
            file.clear();
            file.seekg(0, ios::beg);
            while (getline(file, line))
            {
                if (line.find(itemName) != string::npos)
                {
                    cout << "Item found: " << line << endl;
                    break;
                }
            }
            file.clear();
            break;
        case 4:
            file.close();
            cout<<endl<<"......Exiting......";
            cout<<endl<<"............................................................."<<endl;
            cout<<"ID\t:\t25CE101"<<endl<<"Name\t:\tMokshkumar Dipalkumar Raval";
            cout<<endl<<"............................................................."<<endl;
            return 0;
        default:
            cerr << "Invalid choice!" << endl;
        }
    }
}