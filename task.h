#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
class company{
    string name="";
    string address="";
    int number_of_students=0;
    public:
    company(string n, string a, int nos){
        name = n;
        address = a;
        number_of_students = nos;
    }
    void filewrite(){
        string f=name+".txt";
        fstream fp;
        fp.open(f, ios::out);
        fp<<"Company Name: "<<name<<endl;
        fp<<"Address: "<<address<<endl;
        fp<<"Number of Students: "<<number_of_students<<endl;
        fp.close();
    }
};
void getDetails(){
    cout << "\033[H\033[2J"; 
    string cname;
    string address;
    int nos;
    cout<<"Company Name: ";cin>>cname;
    cout<<"Address: ";cin>>address;
    cout<<"Number of Students placed: ";cin>>nos;
    company c(cname, address, nos);
    c.filewrite();
}
void displayDetails(string f=""){
    cout << "\033[H\033[2J"; 
    string line;
    if(f==""){
        cout<<"Enter the Company Name: ";
        cin>>f;
    }
    fstream fp;
    fp.open(f+".txt", ios::in);
    while (getline(fp, line)) {
        cout << line <<endl;
    }
    fp.close();
}
void updateDetails() {
    string companyName, numberOfStudents;
    cout << "Enter the Company Name: ";
    cin >> companyName;
    cout << "Enter the number of Students: ";
    cin >> numberOfStudents;
    fstream fp;
    fp.open(companyName + ".txt", ios::in | ios::out);
    if (!fp.is_open()) {
        cerr << "Company Details not found" << endl;
        return;
    }
    string line;
    stringstream u;
    while (getline(fp, line)) {
        if (line.find("Number of Students:") != string::npos) {
            u << "Number of Students: " << numberOfStudents << endl;
        } else {
            u << line << endl;
        }
    }
    fp.close();
    fp.open(companyName + ".txt", ios::out | ios::trunc);
    fp << u.str();
    fp.close();
    cout << "\033[H\033[2J";
    cout << "Updated Details: " << endl;
    displayDetails(companyName);
}
void appendSalary(){
    string f,s;
    cout<<"Enter the Company Name: ";
    cin>>f;
    cout<<"Enter the Salary(avg package): ";
    cin>>s;
    fstream fp;
    fp.open(f+".txt",ios::app);
    fp<<"Salary: "+s+" Rupees"<<endl;
    fp.close();
    cout << "\033[H\033[2J"; 
    cout<<"Updated Details: "<<endl;
    displayDetails(f);
}
