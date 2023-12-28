#include<iostream>
#include<queue>

using namespace std;



int main(){
    priority_queue<int> pq;
    //by default, it is max_heap

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int no;
        cin>>no;
        pq.push(no);
    }

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }


    return 0;
}