#include<iostream>

using namespace std;

//Note that this can easily be improved by DP
// Since its so easy. I am not doing it.

//Recurrence relation
//f(n)=f(n-1)+f(n-2)

//For explanation, see coding blocks vid

int count_valid(int n){
    //base case
    if(n==1) return 2;
    if(n==2) return 3;

    return count_valid(n-1)+count_valid(n-2);
}
int main(){

    int n;
    cin>>n;

    cout<<count_valid(n)<<endl;


    return 0;
}