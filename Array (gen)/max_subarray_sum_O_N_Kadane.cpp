//MAXIMUM SUBARRAY SUM O(n) approach-- KADANE'S algorithm

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int max_sum=INT_MIN;
        int sum_curr=0;
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin>>arr[j];
        }
        
        for(int j=0;j<n;j++){
            sum_curr+=arr[j];
            if (sum_curr>max_sum) max_sum=sum_curr;
            if (sum_curr<0){
                sum_curr=0;
            }
            
            
        }
        cout<<max_sum<<endl;
    }
    return 0;
}
