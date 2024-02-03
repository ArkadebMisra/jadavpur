#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){

    ifstream in("7_data.txt");

    if(!in.is_open()){
        cout << "something went wrong, coudnt open file"<< endl;
        return 0;
    }

    string line;
    int ch=0;
    int wrd=0;
    int ln=0;
    while(getline(in, line)){
        ln++;
        ch += line.length();
        int w=0;
        for(int i=0;i<line.length();i++){
            if(line[i]==' '){
                w++;
            }
        }
        wrd += w;
    }

    in.close();

    cout << "Number of characters: " << ch << endl;
    cout << "Number of words: " << wrd << endl;
    cout << "Number of lines: " << ln << endl;
    return 0;
}