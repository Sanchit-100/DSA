//BINARY SEARCH USING RECURSION
#include<bits/stdc++.h>
using namespace std;


int bin_search(int start,int stop, int arr[],int key){
    if (key==arr[(start+stop)/2]){
        // cout<<stop/2<<" 1"<<endl;
        return ((start+stop)/2);
    }
    else if (start==stop){
        // cout<<stop/2<<" 2"<<endl;
        return -1;
    }
    else if (arr[(start+stop)/2]>key){
        // cout<<stop/2<<" 3"<<endl;
        return bin_search(0,((stop/2)-1),arr,key);
    }
    else if(arr[(start+stop)/2]<key){
        // cout<<stop/2<<" 4"<<endl;
        return bin_search(((start+stop)/2)+1,stop,arr,key);
    }
    }
    
int main(){
    int n,key;
    cin>>n>>key;
    int arr[n]={0};

    
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<bin_search(0,n-1,arr,key);
    
    return 0;
}