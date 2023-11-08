#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
#include<iomanip>
#include "task.h"
using namespace std;
int main()
{
    int choice,up=0;
    while (1)
    {
        cout <<"\n-----------------------MENU----------------------------" << endl;
        cout << "[1] Enter placement Details " << endl;
        cout << "[2] Edit Number of student placed " << endl;
        cout << "[3] Append salary(avg package) " << endl;
        cout << "[4] Display placement info"<<endl;
        cout << "[5] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            getDetails();
            break;

        case 2: 
            updateDetails();
            break;

        case 3:
            appendSalary();
            break;

        case 4:
            displayDetails();
            break;
            
        case 5:
        cout<<"\n............exiting..........\n";
        exit(1);
            return 0;

        default:
            cout << "Invalid choice. Please try again."<< endl;
            break;
        }
    }
    return 0;
}
