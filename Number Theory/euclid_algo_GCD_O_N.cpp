//EUCLID"S ALGORITHM FOR GCD IN O(N)

int GCD(int a, int b){
    if(a>b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    
    while(a!=0){
        int temp;
        temp=a;
        a=b%a;
        b=temp;
    }
    
    return b;
}

#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b)<<endl;
    
    return 0;
}
