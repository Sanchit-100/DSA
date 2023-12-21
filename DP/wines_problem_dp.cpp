//Top-down approach
//Recurrence relation
//f(i,j,arr,y)=max((arr[i]*y)+f(i+1,j,arr,y+1),
//                  (arr[j]*y)+f(i,j-1,arr,y+1))


//NOTE: Here the dp is actually a 2d array, ie. we are storing
//values in a matrix format.



#include<iostream>
using namespace std;


int max_profit(int y,int i, int j, int arr[], int dp[][100]){
    //base case
    if(i>j) return 0;

    //lookup case
    if(dp[i][j]!=0) return dp[i][j];

    //Recursive case
    int left_bottle=(arr[i]*y)+max_profit(y+1,i+1,j,arr,dp);
    int right_bottle=(arr[j]*y)+max_profit(y+1,i,j-1,arr,dp);


    return dp[i][j]=max(left_bottle,right_bottle);
}
int main(){
    int n;
    cin>>n;

    int dp[100][100]={0};
    int y=1;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<max_profit(y,0, n-1,arr,dp)<<endl;


    return 0;
}


//Bottom-Up Approach

// #include<iostream>

// using namespace std;

// int max_profit(int n, int arr[], int dp[][100]){
//     for(int i=1;i<n;i++){
//         for(int j=0;j<=i;j++){
//             arr[i][j]=0;
//         }
//     }
// }
// int main(){
//     int n;
//     cin>>n;

//     int dp[100][100];
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout<<max_profit(n,arr,dp)<<endl;

//     return 0;
// }


//Bottom up was not fully implemented as it was a little difficult.