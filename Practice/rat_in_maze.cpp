#include <iostream>
using namespace std;

/*
Aim: Find a possible solution for the maze, if exists
*/

// arr is the given square matrix of safe and blcked positions
// soln is the answer matrix specifiying the path traversed with 1's
// x,y are the current coordinates
// n is the dimension of matrix

bool isSafe(int arr[5][5], int x, int y, int n)
{
    if ((x < n && y < n) && arr[x][y] != 0)
    {
        return true;
    }
    return false;
}

bool rat_in_maze(int arr[5][5], int x, int y, int soln[5][5], int n)
{

    if(x==n-1 && y==n-1){
        soln[x][y]=1;
        return true;
    }

    if (isSafe(arr, x, y, n))
    {
        soln[x][y] = 1;

        if (rat_in_maze(arr, x + 1, y, soln, n))
        {
            return true;
        }

        if (rat_in_maze(arr, x, y + 1, soln, n))
        {
            return true;
        }

        soln[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{

    int arr[5][5] = {{1, 0, 1, 0, 1},
                     {1, 0, 1, 1, 1},
                     {1, 1, 0, 1, 0},
                     {1, 0, 1, 1, 1},
                     {1, 1, 1, 1, 1}};

    int soln[5][5] = {0};
    if (rat_in_maze(arr, 0, 0, soln, 5))
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No possible path" << endl;
    }
    return 0;
}
