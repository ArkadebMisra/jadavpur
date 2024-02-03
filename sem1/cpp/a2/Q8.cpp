#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cstdio>


using namespace std;

void add(fstream &);
void display(fstream &);
void search(fstream &);
void update(fstream &);

struct data{
    int id;
    char name[80];
    double marks;
};

int main(){
    const string fname = "8_data"; 
    string ignore;
    bool flag = true; 
    int choice;
    
    fstream fptr(fname, ios::in | ios::out | ios::binary);
    
    if (!fptr){
        cerr << "Cannot open file!" << endl;
        return 1;
    }

    string menu[] = {"1. Add new record", 
                    "2. View all records", 
                    "3. Delete particular record", 
                    "4. Search record", 
                    "5. Update record", 
                    "6. Exit"};

    const int size = sizeof(menu) / sizeof(menu[0]);

while (flag){
        cout << "========== MENU ==========" << endl;
        for (int i = 0; i < size; i++)
            cout << menu[i] << endl;
        cout << "Enter choice: ";
        
        cin >> choice;
        getline(cin, ignore);   
        switch (choice){
            case 1:
                add(fptr);
                break;
            case 2:
                display(fptr);
                break;
            case 3:
                // del(fptr, fname);
                break;
            case 4:
                search(fptr);
                break;
            case 5:
                update(fptr);
                break;
            case 6:
                flag = false;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    fptr.close();
    return 0;
}

void add(fstream &fptr){
    string ignore;
    char name[80];
    fptr.seekp(0, ios::end);
    struct data d;

    cout << "Enter id: ";
    cin >> d.id;
    getline(cin, ignore);

    cout << "Enter name: ";
    scanf("%[^\n]*c", name);
    // cout << name;
    strcpy(d.name, name);
    // getline(cin, name);
    
    // getline(cin, ignore);

    cout << "Enter marks: ";
    cin >> d.marks;

    fptr.clear();
    getline(cin, ignore);
    fptr.seekp(0, ios::end);
    fptr.write((char *) &d, sizeof(struct data));
    cout << "data written";

    fptr.clear();
    // fptr << roll << ',' << name << ',' << marks << endl;
}

void display(fstream &fptr){
    string ignore;
    fptr.seekp(0, ios::beg);
    struct data d;

    cout << "content of the file" <<endl;

    while (1){
        fptr.read((char *) &d, sizeof(struct data));
        
        if(!fptr.gcount()){
            break;
        }
        cout << "id: " <<d.id << "\n" <<"name: "<< d.name <<"\n" <<"marks: "<< d.marks <<endl;
    }
    fptr.clear();
}

void search(fstream &fptr){
    string ignore;
    fptr.seekp(0, ios::beg);
    struct data d;
    int id;
    cout << "enter id to search" <<endl;
    cin >> id;
    getline(cin, ignore);
    while (1){
        fptr.read((char *) &d, sizeof(struct data));
        
        if(!fptr.gcount()){
            cout << "record not found <<endl";
            break;
        }
        if(d.id==id){
            cout << "record found"<<endl;
            cout << "id: " <<d.id << "\n" <<"name: "<< d.name <<"\n" <<"marks: "<< d.marks <<endl;
            break;
        }
    }
    fptr.clear();
}


void update(fstream &fptr){
    string ignore;
    char name[80];
    fptr.seekp(0, ios::beg);
    struct data d, d1;
    int id;
    cout << "enter id to update the record" <<endl;
    cin >> id;
    getline(cin, ignore);
    while (1){
        fptr.read((char *) &d, sizeof(struct data));
        
        if(!fptr.gcount()){
            cout << "record not found <<endl";
            break;
        }
        if(d.id==id){
            cout << "record found"<<endl;
            fptr.seekp(-sizeof(struct data), ios::cur);
            cout << "updating" << endl << "enter updated record"<<endl;

            cout << "Enter id: ";
            cin >> d1.id;
            getline(cin, ignore);

            cout << "Enter name: ";
            scanf("%[^\n]*c", name);
            // cout << name;
            strcpy(d1.name, name);
            // getline(cin, name);
            
            // getline(cin, ignore);

            cout << "Enter marks: ";
            cin >> d1.marks;

            fptr.write((char *) &d1, sizeof(struct data));
            cout << "data written" << endl;

            // cout << "id: " <<d.id << "\n" <<"name: "<< d.name <<"\n" <<"marks: "<< d.marks <<endl;
            break;
        }
    }
    fptr.clear();
}