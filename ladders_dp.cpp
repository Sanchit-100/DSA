// Top-Down DP
// Find the number of ways to climb up n stairs, given that
// he can climb atmost k stairs at a time.

// #include<iostream>
// using namespace std;

// int ways_of_steps(int n, int k, int dp[]){

//     //base  case
//     if(n==0) return 1;

//     //lookup case
//     if(dp[n]!=0) return dp[n];

//     int sum=0;
//     for(int i=1;i<=k;i++){
//         if(n-i>=0){
//             sum+=ways_of_steps(n-i,k,dp);
//         }

//     }

//     return dp[n]=sum;
// }

// int main(){
//     int n;
//     int k;

//     cin>>n>>k;
//     int dp[n+1]={0};

//     cout<<ways_of_steps(n,k,dp)<<endl;

//     return 0;
// }

// Bottom-UP
//  Time complexity: O(N.K) almost O(N^2)

// #include <iostream>
// using namespace std;

// int ways(int n, int k, int dp[])
// {

//     dp[0] = 1;
//     for (int i = 1; i <= n; i++)
//     {

//         int temp_sum = 0;

//         for (int j = 1; j <= k; j++)
//         {
//             if (i - j < 0)
//                 break;
//             temp_sum += dp[i - j];
//         }

//         dp[i] = temp_sum;
//     }

//     return dp[n];
// }
// int main()
// {

//     int n, k;
//     cin >> n >> k;

//     int dp[n + 1] = {0};

//     cout << ways(n, k, dp) << endl;

//     return 0;
// }

// Optimised Bottom up
//  Time complexity: O(N)
// Uaing the following formula noticed to fill up the dp array
//  dp[i] = (2*dp[i-1])-dp[i-k-1]

#include <iostream>
using namespace std;

int ways(int n, int k, int dp[])
{

    dp[0] = 1;
    // We need to first fill up the k terms of array to use the
    //above formula

    int temp=1;
    for(int i=1;i<=k;i++){
        dp[i]=temp;
        temp+=dp[i];
    }
    for (int i = k+1; i <= n; i++)
    {
        dp[i]=(2*dp[i-1])-dp[i-k-1]; 

    }

    //Technically, time complexity is O(N+K)

    return dp[n];
}
int main()
{

    int n, k;
    cin >> n >> k;

    int dp[n + 1] = {0};

    cout << ways(n, k, dp) << endl;

    return 0;
}
