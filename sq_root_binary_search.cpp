// SQUARE ROOT USING BINARY SEARCH

#include<iostream>
#include<cmath>

using namespace std;

int sqr_root(int n){
    int arr[n]={0};
    
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    
    int s=0;
    int e=n-1;
    int ans=0;
    
    while(s<=e){
        int mid=(s+e)/2;
        if (pow((arr[mid]),2)==n){
            return arr[mid];
        }
        else if (pow((arr[mid]),2)<n){
            ans=arr[mid];
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<sqr_root(n)<<endl;
    return 0;
}
