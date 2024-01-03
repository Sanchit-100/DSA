/*
We need to find the length of the longest subarray that sums to zero.
We will do this in O(N), hoping that unordered_map finds an elemnet in O(1),
which it does in average case

We will again create a prefix_sum array and we will insert elements in the map
where key will be the cum_sum till that pt. and value will be the index in the hypothetical array

NOTE: This is an amazing way to use indexing in an unordered_map as it gives us 
the best of both worlds (array and map)

So, subarray sum can be 0 in two ways:-
1. when cum_sum becomes 0
2. when the cum_sum becomes equal to a previouslly achieved cum_sum

1. The length in the 1st way is just the idx + 1.
2. The length in the 2nd way is the idx2 - idx1 (where cum_sum occured)

*/


#include <iostream>
#include <unordered_map>
using namespace std;


int length_longest_sub(int arr[], int n){
    unordered_map<int, int> m;
    int pre=0;
    int max_len=0;

    for(int i=0;i<n;i++){
        pre+=arr[i];

        //cum_sum becomes 0

        if(pre==0){
            max_len=max(max_len,i+1);

            //i+1 is the length of that subarray
        }

        //element found in the map

        if(m.find(pre)!=m.end()){
            max_len=max(max_len, i-m[pre]);

            //i-m[pre] is the length
        }
        
        //Otherwise,insert in the map
        
        else{
            m[pre]=i;
        }
    }

    return max_len;
}
int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << length_longest_sub(arr, n) << endl;

    return 0;
}