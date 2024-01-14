#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main(){

    stack<int> stk1;
    stack<int> stk2;

    vector<int> v;
    
    v={8,4,6,2,3};
    for(int i=0;i<v.size()-1;i++){
        stk1.push(v[i]);
    }

    while(!stk1.empty()){
        stk2.push(stk1.top());
        stk1.pop();
    }

    for(int i=0;i<v.size();i++){
        if(v[i]>stk2.top()){
            v[i]=v[i]-stk2.top();
        }
        
    }


    return 0;
}