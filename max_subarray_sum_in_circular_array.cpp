// Given a circular integer array nums of length n, 
// return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to 
// the beginning of the array.

// #include<iostream>
// #include<climits>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     for(int i=0;i<t;i++){
//         int max_sum=INT_MIN;
//         int n;
//         cin>>n;
//         int arr[2*n]={0};
//         for(int j=0;j<n;j++){
//             int a;
//             cin>>a;
//             arr[j]=a;
//             arr[n+j]=a;
//         }
//         for(int k=0;k<n;k++){
//             int max_curr=0;
//             for(int h=k;h<(n+k);h++){
//                 max_curr+=arr[h];
//                 if(max_curr>max_sum) max_sum=max_curr;
                
//             }
            
//         }
//         cout<<max_sum<<endl;
//     }
//     return 0;
// }

