//BRUTE FORCE PRIME_CHECK

#include<iostream>
using namespace std;

int prime_check(int no){
    
    if(no==1){
        return 0;
    }
    if (no==2){
        return 1;
    }
    for(int i=2;i<((no/2)+1);i++){
        if(no%i==0){
            //cout<<i<<endl;
            return 0;
        }
    }
    
    return 1;
}
int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int counter=0;
        int a,b;
        cin>>a>>b;
        for(int j=a;j<=b;j++){
            if (prime_check(j)){
                counter++;
                }
            }
            cout<<counter<<endl;
            
        }
    return 0;
}
