// Brute force-- O(N^2)
// Divide and Conquer-- O(NlogN)
// Stack -- O(N)



#include <iostream>
#include<stack>
using namespace std;

//Following is the Brute force approach for the same
// int largestArea(int arr[], int n)
// {
//     int area=0;
//     for (int i = 0; i < n; i++)
//     {
//         int j = i;
//         while (j < n - 1)
//         {
//             if(arr[i]>arr[j+1]) break;
//             j++;
//         }

//         int right_limit = j;

//         int k = i;
//         while (k > 0)
//         {
//             if(arr[i]>arr[k-1]) break;
//             k--;
//         }

//         int left_limit = k ;

//         int width = right_limit - left_limit + 1;
//         int temp_area = width * arr[i];

//         if (temp_area > area) area = temp_area;
//     }

//     return area;
// }

//Folowing is the Stack approach
int largestArea(int arr[], int n){
    int small_left[n];
    int small_right[n];

    // Stack of indices
    stack<int> stk;

    for(int i=0;i<n;i++){

        while(stk.empty()==0 and arr[stk.top()]>arr[i]) stk.pop();
        if(stk.empty()) small_left[i]=0;
        else{
                small_left[i]=stk.top()+1;
        }

        stk.push(i);
    }

    while(stk.empty()==0) stk.pop();
    //Emptying the stack

    for(int i=n-1;i>=0;i--){

        while(stk.empty()==0 and arr[stk.top()]>arr[i]) stk.pop();
        if(stk.empty()) small_right[i]=n-1;
        else{
                small_right[i]=stk.top()-1;
        }

        stk.push(i);
    }

    int area=0;
    for(int i=0;i<n;i++){
        int temp_area=(small_right[i]-small_left[i] + 1)*arr[i];
        if(temp_area>area) area=temp_area;
    }

    return area;

}
    int main()
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << largestArea(arr, n) << endl;
    }



