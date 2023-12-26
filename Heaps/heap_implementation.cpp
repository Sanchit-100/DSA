#include <iostream>
#include <vector>
using namespace std;

//The below class has been made to implement both max and min heaps
//During initialisation, just set the minHeap parameter to false,
//if you want to create maxHeap

//Note. It is minHeap by default

class Heap
{
    vector<int> v;
    bool minHeap;

    //we didn't use the >,< directly in the code,
    //bcoz we wanted to implement both min,max heaps

    //so we are comparing differently acc to the value of "minHeap"
    
    bool compare(int a, int b)
    {
        if (minHeap == true)
            return a < b;
        else
            return a > b;
    }

    //sets the specified idx element to its correct position in the heap
    void heapify(int n)
    {
        int left=2*n;
        int right=(2*n)+1;
        int min_idx=n;

        if(left<v.size() && compare(v[left],v[n])){
            min_idx=left;
        }

        if(right<v.size() && compare(v[right],v[min_idx])){
            min_idx=right;
        }

        //base case
        if(min_idx!=n){
            swap(v[min_idx],v[n]);
            heapify(min_idx);
        }


    }

public:
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        // blocking the 0th index

        minHeap = type;
    }

    // O(logN) function
    void insert(int data)
    {
        v.push_back(data);
        // added at the end of the array

        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    // O(1) function
    int top()
    {
        return v[1];
    }

    // O(logN) function
    void pop()
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }

    //O(1) function

    bool empty(){
        return v.size()==1;
    }
};

int main()
{   
    Heap h(10,false);
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        h.insert(temp);
    }

    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}