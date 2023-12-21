// Print the minimum no. of steps required to make the given number
// equal to one.
// By choosing to do one of the following steps;-
// n/3 if n%3==0
// n/2 if n%2==0
// n-1

// for example-- for 9, 2 steps is the minimum
// for 10, 3 steps is the minimum

#include <iostream>

using namespace std;

int minimum(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int min_steps(int n)
{
    int dp[20];

    dp[0] = 1e6;
    dp[1] = 0;
    for (int i = 2; i < 20; i++)
    {
        if (i % 3 == 0 and i % 2 == 0)
        {
            dp[i] = minimum(minimum(dp[i / 3], dp[i / 2]), dp[i - 1]) + 1;
        }

        else if (i % 3 == 0)
        {
            dp[i] = minimum(dp[i / 3], dp[i - 1]) + 1;
        }

        else if (i % 2 == 0)
        {
            dp[i] = minimum(dp[i / 2], dp[i - 1]) + 1;
        }

        else
            dp[i] = dp[i - 1] + 1;
    }

    return dp[n];
}
int main()
{
    int n;
    cin >> n;

    cout << min_steps(n) << endl;
    ;

    return 0;
}