#include <iostream>
using namespace std;

/*

Std problem: rat in maze
Problem: A maze ie. 2-d matrix is given. We need to find all the possible
paths through which the rat can reach the last cell, ie. m-1,n-1.

There are various parts of this problem.
1. Tell if there exists any possible path or not. (Yes/No)
2. Give any one possible path.
3. Count the number of possible paths.
4. (Most elaborate) Give all possible paths

We will do 4th. Rest all are included by default.

There are some entries marked as "X" in the maze and are blocked.

The rat can  move only forward (horizontal right) and down (vertical down).
No back moves are allowed.

Approach: With each choice in movement of right or down, we reduce the experiment
space, until only one cell is left.



*/

// Finding if a path is suitable or not through the bool fxn
// i and j denote the current coordinate of the rat

bool rat_in_maze(int m, int n, char maze[10][10], int i, int j, int soln[10][10])
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        soln[i][j] = 1;
        // Successfull
        // Print the path
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << soln[i][j];
            }
            cout << endl;
        }

        cout << endl;

        return true;
    }

    if (i >= m || j >= n)
    {
        // out of grid
        return false;
    }

    if (maze[i][j] == 'X')
    {
        // encountered blocked area
        return false;
    }

    // if all of the above cases pass, we can move forward
    soln[i][j] = 1;
    // 1 means we have crossed that block

    bool rightSuccess = rat_in_maze(m, n, maze, i + 1, j, soln);
    bool downSuccess = rat_in_maze(m, n, maze, i, j + 1, soln);

    // BACKTRACKING
    soln[i][j] = 0;

    if (rightSuccess || downSuccess)
    {
        return true;
    }

    return false;
}

int main()
{

    char maze[10][10] = {"0000",
                         "00X0",
                         "000X",
                         "0X00"};

    int soln[10][10] = {0};

    int m = 4;
    int n = 4;
    // rows and columns are 4 each

    rat_in_maze(m, n, maze, 0, 0, soln);

    return 0;
}
