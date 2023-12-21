// Take as input N, the size of array. Take N more inputs and store that in an array.
// Take as input M, a number. Write a recursive function which returns an array containing 
// indices of all items in the array which have value equal to M. 
// Print all the values in the returned array.  

#include<iostream>
using namespace std;

void solution(int arr[],int m, int i,int n){
    //base case
    if(i>=n) return;

    if(arr[i]==m) cout<<i<<" ";
    i++;
    solution(arr,m,i,n);
}
int main(){
    int n,m;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cin>>m;

    solution(arr,m,0,n);


    return 0;
}