// FIBONACCI PROGRAM

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if (n==1){
        return 0;
    }
    else if (n==2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
    
}


int main(){
    int a;
    cin>>a;
    cout<<fib(a);
    
    return 0;
}
