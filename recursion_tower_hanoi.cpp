#include<iostream>
using namespace std;

//There are 3 stacks A,B,C
//Rings to move from A->C

void move(int n, int source, int interim, int dest){
    //base case
    if(n==0){
        return;
    }

    move(n-1,source,dest,interim);
    cout<<"Move disk from "<<source<<" to "<<dest<<endl;
    move(n-1,interim,source,dest);
}

int main(){

    int n;
    cin>>n;

    move(n,1,2,3);


    return 0;
}