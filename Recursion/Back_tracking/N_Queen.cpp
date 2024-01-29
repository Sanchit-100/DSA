#include <iostream>
using namespace std;

/*

Problem: We are given an N*N 2d matrix and we have to fix n queens on the
board in such a way that no 2 queens attack each other.

Function isSafe-- For checking if our current position of x,y is sage or not.
ie. it should not be under attack by any other queen.

Note here that we don't need to check rows below it because if we are in that row, 
it denotes that obviously, we have not fille dthe below ones.

Also, Note here that we don't need to check columns in the same row, coz we will
obviously be filling only one queen in one row.

So, ultimately the isSafe function checks only the rows above it in the same column
and diagonally up left and diagonally up-right.

Function nQueen--


*/

// x,y denote the current coordinates

bool isSafe(int arr[10][10], int x, int y, int n)
{

    // checking rows above it
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
        {
            // Already one queen present in the same column
            return false;
        }
    }
    int row=x;
    int col=y;

    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        col--;
        row--;
    }

    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        col++;
        row--;
    }

    return true;
}



bool nQueen(int arr[10][10], int n, int x)
{
    //base case
    //when all queens are settled
    if(x>=n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;
            //assuming that it is a correct position
        
            if(nQueen(arr,n,x+1)){
                return true;
            }

            arr[x][col]=0;
            //backtracking
            
        }

    }

    return false;

}

int main()
{
    int n;
    cin >> n;

    int arr[10][10] = {0};

    if (nQueen(arr, n, 0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }

    else{
        cout<<"No possible arrangement"<<endl;
    }

    return 0;
}