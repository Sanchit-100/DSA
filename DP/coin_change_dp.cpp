//Top Down approach

// #include <iostream>
// #include<climits>
// using namespace std;

// int minimum(int a, int b){
//     if(a>b) return b;
//     else return a;
// }

// int min_change(int n, int currency[], int num_curr, int dp[], int min)
// {
//     //base case
//        if(n==0) return 0;

//     // Lookup case
//     if(dp[n]!=0) return dp[n];

//     //Recursive case
//     for(int i=0;i<num_curr;i++){
//         if(n-currency[i]>=0){
//             min=minimum(min,min_change(n-currency[i],currency,num_curr,dp,min)+1);
//         }
//     }

//     dp[n]=min;
//     return dp[n];

// }
// int main()
// {
//     int n;
//     cin >> n;

//     int dp[n+1] = {0};
//     int num_curr;
//     cin >> num_curr;
//     int currency[num_curr];
//     int min=1000;

//     for (int i = 0; i < num_curr; i++)
//     {
//         cin >> currency[i];
//     }

//     cout << min_change(n, currency, num_curr, dp,min) << endl;

//     return 0;
// }



//Bottom-Up approach

#include<iostream>
#include<climits>
using namespace std;


int coin_change(int n, int num_curr, int arr[]){
    int dp[n+1];
    
    //base case
    dp[0]=0;
    for(int i=1;i<n+1;i++){
        int temp_ans=INT_MAX;
        for(int j=0;j<num_curr;j++){
            if(i-arr[j]>=0){
                temp_ans=min(temp_ans,dp[i-arr[j]]);
            }
            else break;
            //assuming that the array of currency is in increasing order

    
        }

        dp[i]=temp_ans+1;

    }

    return dp[n];
}
int main(){
    int n;
    cin>>n;

    int num_curr;
    cin>>num_curr;

    int arr[num_curr];

    for(int i=0;i<num_curr;i++){
        cin>>arr[i];
    }

    cout<<coin_change(n,num_curr,arr)<<endl;

    return 0;
}