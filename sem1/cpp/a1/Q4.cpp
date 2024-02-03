#include<iostream>
using namespace std;
class Pattern
{
    private:
    int n;

    public:
    void setn(int no)
    {
        n=no;
    }

    void printPat()
    {
        for(int i = 1; i <=2*n-1; i++)
        {
            for(int k = 1; k<i; k++)
            {
                cout<<" ";
            }
            for(int j = i; j<=2*n-1-(i-1); j++)
            {
                cout<<"*";
            }
            cout<< endl;
        }
        
    }
};
int main()
{
    Pattern p;
    p.setn(10);
    p.printPat();
}