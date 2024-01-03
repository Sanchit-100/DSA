/*
Given an array, find if there is a subarray whose sum is zero or not
You have to give the answer in Yes/No

Note: We will use unordered_set
We could also use unordered_map

We will do it in average case O(N)
1. Brute force would be to find the sum of all subarrays in O(N^3)
2. Creating a prefix array of cumulative sum and then finding sum in O(N^2)
3. Using unordered_set along with prefix sum array will give almost O(N)

*/

#include <iostream>
#include <unordered_set>
using namespace std;

bool subarray_zero(int arr[], int n)
{
    unordered_set<int> s;
    int pre = 0;

    //To save space, we are not actually creating a prefix_sum array
    //instead, we are calculating each of the prefix array's element,
    //and inserting it in the unordered set

    //unordered set.find()  returns an iterator of the found element
    //returns s.end(), if it doesn't find it

    //So, if an element of the prefix sum is 0, it means that the sum from the 
    //very starting to that element is actually zero
    //so, return true

    //Otherwise, if it finds one of the same element already present in the prefix array(set)
    //that means return true (take example and understand)

    
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (pre == 0 || s.find(pre) != s.end())
        {
            return true;
        }
        s.insert(pre);
    }

    return false;
}
int main()
{
    int n;

    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << subarray_zero(arr, n) << endl;

    return 0;
}