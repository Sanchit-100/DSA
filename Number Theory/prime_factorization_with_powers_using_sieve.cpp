//WRITING THE PRIME FACTORS AND THEIR POWERS USING SIEVE

#include<iostream>
#include<vector>

using namespace std;

//creating sieve as in previous program
void sieve_maker(int *arr,int n,vector<int> &primes){
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
    
    for(int i=0;i<n;i++){
        if(arr[i]==1) primes.push_back(i);
    }
    return;
}


vector<pair<int,int>> divisors(vector<int>& primes,int n){
    
    int cnt=0;
    int i=0;
    vector<pair<int,int>> fac_pow;
    while(n!=1 and primes[i]*primes[i]<=n){
            if(n%primes[i]==0){
                cnt=0;
                while(n%primes[i]==0){
                    n=n/primes[i];
                    cnt++;
                }
                fac_pow.push_back(make_pair(primes[i],cnt));
            }
        i++;
    }
    if(n!=1) fac_pow.push_back(make_pair(n,1));
    return fac_pow;
    
}
    
int main(){
    int n;
    cin>>n;
    int arr[n];
    vector<int> primes;
    sieve_maker(arr,n,primes);
    vector<pair<int,int>> fac_pow=divisors(primes,n);
    
    // for(int i=0;i<primes.size();i++){
    //     cout<<primes[i]<<" ";
    // }
    
    for(int i=0;i<fac_pow.size();i++){
        cout<<fac_pow[i].first<<"^"<<fac_pow[i].second<<endl;
    }
    

    return 0;
}
