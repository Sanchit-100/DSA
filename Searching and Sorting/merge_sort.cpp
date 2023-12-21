//MERGE SORT IMPLEMENTATION

#include<iostream>
using namespace std;

void merge(int* arr,int s,int e){
    int temp[100]={0};
    int i=s;
    int k=s;
    int mid=(s+e)/2;
    int j=mid+1;
    
    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    
    while(j<=e){
        temp[k]=arr[j];
        j++;
        k++;
    }
    
    for(int i=s;i<=e;i++){
        arr[i]=temp[i];
    }
    
}
void mergeSort(int* arr,int s,int e){
    //Base Case
    if(s>=e) return;
    
    int mid=(s+e)/2;
    
    //Sorting the smaller arrays
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    
    //Merge the sorted arrays
    merge(arr,s,e);
}


int main(){
    int n;
    cin>>n;
    
    int arr[n]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    mergeSort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}


