//FINDING PRIME FACTORS OF A NUMBER

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> prime_factors(int n){
    
    vector<int> v;
    int sqr_root=sqrt(n);
    for(int i=2;i<sqr_root;i++){
        if(i==1){
            break;
        }
        if(n%i==0){
            v.push_back(i);
            while(n%i==0){
                n=n/i;
            }
        }
    }
    if(n!=1) v.push_back(n);
    return v;
}
int main(){
    int n;
    cin>>n;
    vector<int> v=prime_factors(n);
    
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
    return 0;
}
