/*
Note here that

push()-O(N)
pop()-O(1)
top()-O(1)
empty()-O(1)

*/


#include<iostream>
#include<queue>
using namespace std;

class stack{
    private:
        queue<int> q1;
        queue<int> q2;
    
    public:
        void push(int n){
            if(q2.empty()){
                q2.push(n);
                while(!q1.empty()){
                    q2.push(q1.front());
                    q1.pop();
                }
            }

            else {
                q1.push(n);
                while(!q2.empty()){
                    q1.push(q2.front());
                    q2.pop();
                }
            }

        }

        void pop(){
            if(!q1.empty()) q1.pop();
            else if(!q2.empty()) q2.pop();
        }

        int top(){
            if(q1.empty()) return q2.front();
            else if(q2.empty()) return q1.front();
        }

        bool empty(){
            if(q1.empty() and q2.empty()) return 1;
            else return 0;
        }
};
int main(){
    stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout<<stk.top()<<endl;
    stk.pop();
    cout<<stk.top()<<endl;

    if(stk.empty()) cout<<"Stack is empty"<<endl;
    else cout<<"Stack is not empty"<<endl;

    stk.pop();
    cout<<stk.top()<<endl;
    stk.pop();

    if(stk.empty()) cout<<"Stack is empty"<<endl;
    else cout<<"Stack is not empty"<<endl;

    return 0;
}