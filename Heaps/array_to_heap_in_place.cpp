//NlogN complexity

// #include<iostream>
// using namespace std;



// int main(){
//     int n;
//     cin>>n;

//     int* arr=new int[n+1];

//     for(int i=1;i<n+1;i++){
//         cin>>arr[i];
//     }

//     //N iterations
//     for(int i=2;i<n+1;i++){
//         int idx=i;
//         int parent=idx/2;

//         //for a maxHeap
//         //logN iterations
//         while(idx>1 && arr[idx]>arr[parent]){
//             swap(arr[idx],arr[parent]);
//             idx=parent;
//             parent=parent/2;
//         }
//     }

//     //printing the ans array
//     for(int i=1;i<n+1;i++){
//         cout<<arr[i]<<" ";
//     }


//     return 0;
// }



//O(N)complexity
//Difficult to understand the complexity just by looking at the no. of loops etc.
//Mathematically, in the video, it is O(N)


//Essentially this is a bottom up traversal (n/2 to 0)
//which helps to reduce the time complexity
//as compared to the top-down (0-n) done earlier

#include<iostream>
using namespace std;

void heapify(int arr[], int i, int n){
    int max_idx=i;

    int left=2*i;
    int right=left+1;

    if(left<n+1 && arr[left]>arr[max_idx]){
        max_idx=left;
    }

    if(right<n+1 && arr[right]>arr[max_idx]){
        max_idx=right;
    }

    if(max_idx!=i){
        swap(arr[max_idx],arr[i]);
        heapify(arr, max_idx, n);
    }
}


int main(){
    int n;
    cin>>n;

    int* arr=new int[n+1];

    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }

    //N iterations
    for(int i=n/2;i>0;i--){
        heapify(arr, i,n);
    }

    //printing the ans array
    for(int i=1;i<n+1;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}