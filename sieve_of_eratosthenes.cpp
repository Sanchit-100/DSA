//SIEVE OF ERATOSTHENES

#include<iostream>
#define LL long long
//LL is the alias for long long
//Note that no semicolon after define,include statements

using namespace std;

void prime_check(int *p, int n){
    //declaring 0 and 1 as not prime
    //declaring 2 as prime
    
    p[0]=p[1]=0;
    p[2]=1;
    
    //declaring all odd as prime
    for(LL i=3;i<n;i+=2){
        p[i]=1;
    }
    
    //checking only the odd numbers
    //all evens are already marked as not prime
    for(LL i=3;i<n;i+=2){
        //if the number if prime
        if (p[i]==1){
            //mark all its multiples after its square as not prime
            //P.S.- its multiples before its square would have already been marked as not prime
            //ex for 5- we will mark its multiples 25,30,35,etc.
            //10 would be marked with 2
            //15 with 3, 20 marked with 2.
            for(LL j=i*i;j<n;j=j+i){
                p[j]=0;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n]={0};
    prime_check(arr,n);
    //Printing all the primes until n
    for(int i=0;i<n;i++){
        if (arr[i]==1){
            cout<<i<<" ";
        }
    }
    
    return 0;
}
