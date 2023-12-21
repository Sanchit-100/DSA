#include <iostream>
using namespace std;

//This is actually of time complexity O(N.T)
//can be reduced to O(N.logT) if uses binary search for the coins array
//or use the upper bound function of STL of logN complexity

int coinChange(int coins[], int n, int t) //t is the no. of elements in the array
{   
    int number=0;
    while (n != 0)
    {
        for (int i = t - 1; i >= 0; i--)
        {
            if (coins[i] <= n)
            {
                n = n - coins[i];
                number++;
                break;
            }
        }
    }

    return number;
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

    int t=sizeof(coins)/sizeof(int);
    //t is the length of the array

    int n;
    cin >> n;

    cout << "Min number of coins is " << coinChange(coins, n, t) << endl;

    return 0;
}