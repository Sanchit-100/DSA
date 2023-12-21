// O(N)-- since each element gets pushed and popped only once.
// ie. 2*O(1)==O(1) for each element.

//NOTE: Dont look just at the no. of loops
// Think carefully that we are pushing one element just once.
//ie if we pop it out in the while loop, it will never be popped again.
// Therefore, although we use a while loop, on thinking, we can figure out that
// the no. of operations throughout the loop cycles will be only n.


// NOTE: Brute force without stack use would be O(N^2)

#include<iostream>
#include<stack>
#include<tuple>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"------"<<endl;
    tuple<int,int> temp;
    int ans[n];
    stack<tuple<int,int>> stk;

    for(int i=0;i<n;i++){
        temp=make_tuple(i+1,arr[i]);
        if(stk.empty()){
            ans[i]=i+1;
            stk.push(temp);
        }
        else{
            //cout<<"Element at top of stk is "<<get<1>(stk.top())<<" ";
            //cout<<endl;
            while((stk.empty()==0) and ((get<1>(stk.top()))<arr[i])){
                // cout<<"At iteration "<<i+1<<","<<get<1>(stk.top())<<" is getting popped ";
                stk.pop();
            }
            // cout<<"blablabla";

            int prev_idx;
            if(stk.empty()) prev_idx=0;
            else prev_idx=get<0>(stk.top());

            stk.push(temp);
            ans[i]=(i+1)-prev_idx;
            
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"END"<<endl;

    return 0;
}