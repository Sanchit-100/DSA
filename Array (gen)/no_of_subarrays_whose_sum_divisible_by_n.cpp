//DIVISIBLE SUBARRAYS- Find the number of Subarrays 
//whose sum of elements is divisible by n

#include<iostream>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int cummulative_sum[n+1]={0};
        int sum=0;
        
        int frequency_arr[n+1]={0};
        
        int final[n]={0};
        for(int i=0;i<n;i++){
            sum+=arr[i];
            cummulative_sum[i+1]=sum;
        }
        
        // for(int i=0;i<n+1;i++){
        //     cout<<cummulative_sum[i]<<" ";
        // }
        // cout<<endl;
        
        for(int i=0;i<n+1;i++){
            frequency_arr[i]=(cummulative_sum[i]%n);
        }
        
        // for(int i=0;i<n+1;i++){
        //     cout<<frequency_arr[i]<<" ";
        // }
        // cout<<endl;
        
        for(int i=0;i<n+1;i++){
            final[frequency_arr[i]]++;
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<final[i]<<" ";
        // }
        
        // cout<<endl;
        
        int answer=0;
        for(int i=0;i<n;i++){
            int temp=final[i];
            answer+=(temp*(temp-1))/2;
        }
        
        cout<<answer<<endl;
        
    }
    return 0;
}
