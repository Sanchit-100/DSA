#include <iostream>
using namespace std;

//You have to tile a 4*N wall with bricks of dimension 4*1
//you can place brick vertically or horizontally
//find the no. of ways to do so


// Recurrence relation
// f(N)=f(N-1)+f(N-4)

//This code takes O(2^N) time complexity
//It can be optimised using DP to O(N^2)
 
int count_bricks(int n)
{
    // base case
    if (n <= 3)
    {
        return 1;
    }

    // rec case
    int vertical = count_bricks(n - 1);
    int horizontal = count_bricks(n - 4);
    return vertical + horizontal;
}

int main()
{
    int n;
    cin >> n;
    cout<<count_bricks(n)<<endl;
    return 0;
}