#include <iostream>

using namespace std;

void selection_sort(int a[],int n){
    for (int i=0;i<n-1;i++){
    int min_index=i;
    for(int j=i;j<n;j++){
        if (a[j]<a[min_index]){
            min_index=j;
        }
    }
    swap(a[i],a[min_index]);
}
    
}

void bubble_sort(int a[], int n){
    for (int i=1; i<n;i++){
        for (int j=0;j<n-i;j++){
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}

void insertion_sort(int arr[],int n){
    for (int i=1;i<n;i++){
        int e=arr[i];
        //e is the current element whom we are trying
        //trying to put in the right place
        int j=i-1;
        //j takes the values of numbers ijn sorted 
        //array to check which numbers are smaller than e
        
        while(j>=0 and arr[j]>e){
            arr[j+1]=arr[j];
            //shifting the larger element to right
            j--;
        }
        //when no further larger elemenmts found, put 
        //our current element in the RIGHT place
        arr[j+1]=e;
    }
    
}

        

int main(){
    int n;
    
    cin>>n;
    int arr[n]={0};
    
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    insertion_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    
    
    
    return 0;
}