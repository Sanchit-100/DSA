//Prime factorization using Sieve

#include<iostream>

using namespace std;

//creating sieve as in previous program
void sieve_maker(int *arr,int n){
    arr[0]=arr[1]=0;
    arr[2]=1;
    
    for(int i=3;i<n;i+=2){
        arr[i]=1;//assume that all odds are prime
    }
    
    for(int i=3;i<n;i+=2){
        //traversing through all odds
        if(arr[i]==1){
            for(int j=i*i;j<n;j+=i){
                arr[j]=0;//mark all multiples after square as not prime
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    sieve_maker(arr,n);
    
    int i=0;
    while(i<=n){
        if(arr[i]==1){
            if(n%i==0){
                cout<<i<<" ";
            }
        }
        i++;
    }
    
    return 0;
}
