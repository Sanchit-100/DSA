#include <iostream>
using namespace std;

// Quicksort algorithm
//Is a divide and conquer algo
// O(NlogN) in avg case
// O(N^2) in worst case

// Main feature is that it does sorting "in place"
//Without crearing extra array
//Although uses space for recursive call stack

int partition(int arr[], int s, int e)
{

    // creating two pointers i,j
    int i = s - 1;
    int j = s;

    // part before index i denotes the numbers smaller than p
    // part between i and j denote the numbers larger than p
    // p is taken as the last element of the portion(ie. e)
    int pivot = arr[e];

    for (; j <= e - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[e]);

    return i + 1;
    // returns the idx of the pivot element
}
void quicksort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    // rec case
    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);

    quicksort(arr, p + 1, e);
}
int main()
{
    int arr[] = {2, 5, 3, 4, 7, 1};
    int n = sizeof(arr) / sizeof(int);

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}