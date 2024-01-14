/*
Given the length of some ropes, find the min cost required to join all the ropes
Cost to join ropes of lengths a , b = (a+b).


Time complexity: O(NlogN)
Note that the loop runs n times with each loop consisting of pop and push
operations involving logN time in a heap

Approach: Essentially, this is a greedy approach, wherein we try to minimise the
cost at each step and ukltimately get the minimum globally

We find the shortest ropes and add them and continue till only one rope is left.

*/

#include<iostream>
#include<queue>

using namespace std;


int main(){

    //creating min_heap
    priority_queue<int,vector<int>,greater<int>> pq;

    int min_cost=0;

    //Adding the ropes length to the min_heap
    int n;
    cout<<"Enter the number of ropes: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        pq.push(a);
    }

    while(pq.size()>1){
        int a=pq.top();
        pq.pop();

        int b=pq.top();
        pq.pop();

        min_cost+=(a+b);
        pq.push(a+b);

    }
    
    cout<<"Min cost req to join all the ropes is "<<min_cost<<endl;


    return 0;
}