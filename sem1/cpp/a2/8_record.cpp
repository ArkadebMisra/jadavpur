#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstdio>
using namespace std;

void add(fstream &);
void display(fstream &);
void search(fstream &);
void del(fstream &, const string &);
void update(fstream &, const string &);

int main()
{
    const string fname = "8_data.txt"; bool flag = true; int choice;
    fstream fptr(fname, ios::in | ios::out);
    if (!fptr)
    {
        cerr << "Cannot open file!" << endl;
        return 1;
    }
    string menu[] = {"1. Add new record", "2. View all records", "3. Delete particular record", "4. Search record", "5. Update record", "6. Exit"};
    const int size = sizeof(menu) / sizeof(menu[0]);
    while (flag)
    {
        cout << "========== MENU ==========" << endl;
        for (int i = 0; i < size; i++)
            cout << menu[i] << endl;
        cout << "Enter choice: ";
        fflush(stdin);
        cin >> choice;
        switch (choice)
        {
            case 1:
                add(fptr);
                break;
            case 2:
                display(fptr);
                break;
            case 3:
                del(fptr, fname);
                break;
            case 4:
                search(fptr);
                break;
            case 5:
                update(fptr, fname);
                break;
            case 6:
                flag = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    fptr.close();
    return 0;
}

void add(fstream &fptr)
{
    long roll; string name; int marks;
    cout << "Enter roll number: ";
    cin >> roll;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter marks: ";
    cin >> marks;
    fptr.clear();
    fptr.seekp(0, ios::end);
    fptr << roll << ',' << name << ',' << marks << endl;
}

void display(fstream &fptr)
{
    string line;
    cout << "Roll" << "\t\t\t" << "Name" << "\t\t\t" << "Marks" << endl;
    fptr.clear();
    fptr.seekg(0, ios::beg);
    while (getline(fptr, line))
    {
        istringstream iss(line); string field;
        while (getline(iss, field, ','))
            cout << field << "\t\t";
        cout << endl;
    }
}

void search(fstream &fptr)
{
    fptr.clear();
    fptr.seekg(0, ios::beg);
    string line; long sroll; bool flag = false;
    cout << "Enter roll number: ";
    cin >> sroll;
    cout << "Roll" << "\t\t\t" << "Name" << "\t\t\t" << "Marks" << endl;
    while (getline(fptr, line))
    {
        istringstream iss(line); char comma = ','; long roll; string field;
        iss >> roll >> comma;
        if (roll == sroll)
        {
            cout << roll << "\t\t";
            while (getline(iss, field, comma))
                cout << field << "\t\t";
            cout << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "\t\t\t" << "- No Records -" << endl;
}

void del(fstream &fptr, const string &fname)
{
    long sroll; string line; const string tempfile = "8_temp.txt"; bool flag = false;
    cout << "Enter roll number: ";
    cin >> sroll;
    fstream tptr(tempfile, ios::in | ios::out | ios::trunc);
    fptr.clear();
    fptr.seekg(0, ios::beg);
    while (getline(fptr, line))
    {
        istringstream iss(line); char comma = ','; long roll;
        iss >> roll >> comma;
        if (roll != sroll)
            tptr << line << '\n';
        else
            flag = true;
    }
    fptr.close();
    fptr.open(fname, ios::in | ios::out | ios::trunc);
    tptr.clear();
    tptr.seekg(0, ios::beg);
    while (getline(tptr, line))
        fptr << line << '\n';
    tptr.close();
    remove(tempfile.c_str());
    if (!flag)
        cout << "Record for " << sroll << " not present" << endl;
    else
        cout << "Record for " << sroll << " deleted" << endl;
}

void update(fstream &fptr, const string &fname)
{
    long sroll; string line; const string tempfile = "8_temp.txt"; bool flag = false;
    cout << "Enter roll number: ";
    cin >> sroll;
    fstream tptr(tempfile, ios::in | ios::out | ios::trunc);
    fptr.clear();
    fptr.seekg(0, ios::beg);
    while (getline(fptr, line))
    {
        istringstream iss(line); char comma = ','; long roll; string name; int marks;
        iss >> roll >> comma;
        if (roll == sroll)
        {
            flag = true;
            cout << "Record for " << sroll << " present" << endl;
            cout << "Enter name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            cout << "Enter marks: ";
            cin >> marks;
            tptr << roll << ',' << name << ',' << marks << '\n';
        }
        else
            tptr << line << '\n';
    }
    fptr.close();
    fptr.open(fname, ios::in | ios::out | ios::trunc);
    tptr.clear();
    tptr.seekg(0, ios::beg);
    while (getline(tptr, line))
        fptr << line << '\n';
    tptr.close();
    remove(tempfile.c_str());
    if (!flag)
        cout << "Record for " << sroll << " not present" << endl;
    else
        cout << "Record for " << sroll << " updated" << endl;
}