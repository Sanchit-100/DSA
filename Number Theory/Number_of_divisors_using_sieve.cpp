//FINDING NUMBER OF DIVISORS (including 1,n) USING SIEVE

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

int divisors(int* arr,int n){
    
    int cnt=0;
    int ans=1;
    int i=2;
    while(n!=1 and i*i<=n){
        if(arr[i]==1){
            if(n%i==0){
                cnt=0;
                while(n%i==0){
                    n=n/i;
                    cnt++;
                }
            }
        }
        i++;
        ans=ans*(cnt+1);
    }
    if(n!=1) ans=ans*2;
    return ans;
    
}
    
int main(){
    int n;
    cin>>n;
    int arr[n];
    sieve_maker(arr,n);
    cout<<divisors(arr,n)<<endl;
    

    return 0;
}
