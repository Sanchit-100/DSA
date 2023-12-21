#include <iostream>
using namespace std;

class library
{

public:
    int num_books;
    int* borrow;
    library(int num = 3)
    {
        num_books = num;
        borrow=new int[num_books];
    }

    library(library &L){
        num_books=L.num_books;
        borrow=new int[num_books];
        for(int i=0;i<num_books+1;i++){
            borrow[i]=L.borrow[i];
        }
    }


    void print()
    {
        cout << num_books << " is the number of books present";
        cout<<endl;
        for (int i = 0; i < (sizeof(borrow)/sizeof(borrow[0])+1); i++)
        {
            cout << borrow[i] << " copies requested.";
            cout<<endl;
        }
    }
};
int main()
{
    library L1;
    L1.borrow[0] = 15;
    L1.borrow[1] = 20;

    library L2(L1);

    L2.num_books=9;
    L2.borrow[0]=8;

    cout<<"L2"<<endl;
    L2.print();
    cout<<"L1"<<endl;
    L1.print();
    return 0;
}