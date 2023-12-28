#include <iostream>
using namespace std;

void heapify(int arr[], int i, int size)
{
    int left = 2 * i;
    int right = left + 1;

    int max_idx = i;
    if (left < size && arr[i] < arr[left])
    {
        max_idx = left;
    }

    if (right < size && arr[max_idx] < arr[right])
    {
        max_idx = right;
    }

    if (max_idx != i)
    {
        swap(arr[max_idx], arr[i]);
        heapify(arr, max_idx, size);
    }
}

void buildHeap(int arr[], int n)
{

    // bottom up approach
    int temp = n - 1;
    for (int i = temp / 2; i >= 1; i--)
    {
        heapify(arr, i, n);
    }
}

// It is O(NlogN) complexity
void heapsort(int arr[], int n)
{
    // first time we need to CREATE a heap from the arr
    // after that, since we are changing just one element,
    // we can simply call the heapify function to make it a heap again

    // Heapify - LogN complexity
    // buildHeap - N complexity

    buildHeap(arr, n);
    while (n > 2)
    {
        swap(arr[1], arr[n - 1]);
        n--;
        heapify(arr, 1, n);
    }
}
int main()
{
    int arr[] = {-1, 10, 5, 8, 3, 6, 2};
    int n = 7;

    heapsort(arr, n);

    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}