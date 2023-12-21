// Fibonacci using Top Down DP
// Recursion + Memoisation

//Space complexity = O(N) same as before
//since depth of call stack is N

//Time Complexity = O(N) significantly better than the exponential 2^N
//we have computed N nodes
//5..4..3..2..1

#include <iostream>
using namespace std;

int fib(int n, int arr[])
{

    // base case
    if (arr[n] != -1)
        return arr[n];

    int temp = fib(n - 1, arr);
    if (arr[n - 1] == -1)
        arr[n - 1] = temp;

    temp = fib(n - 2, arr);
    if (arr[n - 2] == -1)
        arr[n - 2] = temp;

    return arr[n - 1] + arr[n - 2];
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    arr[0] = 0;
    arr[1] = 1;

    cout << fib(n - 1, arr) << endl;

    return 0;
}