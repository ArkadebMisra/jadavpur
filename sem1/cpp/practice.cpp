#include <iostream>
#include <fstream>

using namespace std;
fstream operator+(fstream &f1, fstream &f2)
{
    fstream fout;
    fout.open("file.txt", ios::out);
    string ch;
    while (getline(f2, ch))
        fout << ch << endl;
    while (getline(f1, ch))
        fout << ch << endl;
    fout.close();
    return fout;
}
int main()
{
    fstream fin1, fin2, fout;
    fin1.open("file1.txt", ios::in);
    fin2.open("file2.txt", ios::in);
    fout.open("file.txt", ios::out);
    if (!(fin1 || fin2))
        cout << "ERROR file not found";
    else
        fout = fin1 + fin2;
    int a = 0;
    int b=1;
    cout << a+b;
    fout.close();
    fin1.close();
    fin2.close();
    return 0;
}