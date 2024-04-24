#include<iostream>
#include<fstream>
#include <sstream>
#include <cstdio>
#include<ios>
using namespace std;
class FileOp
{
    private:
    string fname;

    public:
    FileOp(string f){ fname = f;}
    void display()
    {
        string line;
        ifstream ptr(fname);
        if(!ptr)
        cout << "Cannot display file"<< endl;

        else
        {
            while(getline(ptr,line))
            {
                cout << line ;
            }
            
        }
        ptr.close();
    }

    FileOp operator+(FileOp const &obj)
    {
        string line;
        FileOp ob3("merge");
        ifstream inptr1(fname);
        ifstream inptr2(obj.fname);
        ofstream out(ob3.fname);
        
        if(!inptr1 || !inptr2)
        {
            cout << "Cannot open file";
        }

        while(getline(inptr1,line))
        {
            out << line << "\n";
        }

        while(getline(inptr2,line))
        {
            out << line << "\n" ;
        }
        inptr1.close();
        inptr2.close();
        out.close();
        return ob3;

    }

};


int main()
{
    const string fname1 = "file1.txt", fname2 = "file2.txt"; bool flag = true; int choice;
    FileOp ob1(fname1);
    FileOp ob2(fname2);

    ob1.display();
    ob2.display();

    FileOp ob3 = ob1+ob2;

    ob3.display();


}
    
    
