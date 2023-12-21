#include<iostream>
#include<stack>
using namespace std;

void pushAtBottom(stack<int> &y, int data){
    if(y.empty()){
        y.push(data);
        return;
    }

    int temp=y.top();
    y.pop();
    pushAtBottom(y,data);
    y.push(temp);

}
void revStack(stack<int> &x){
    if(x.empty()) return;
    int temp=x.top();
    x.pop();
    revStack(x);
    pushAtBottom(x,temp);

}
int main(){
    stack<int> s;
    stack<int>check;

    for(int i=0;i<7;i++){
        s.push(i);
    }
    check=s;
    
//Printing the original stack
    while(!check.empty()){
        cout<<check.top()<<endl;
        check.pop();
    }

    cout<<"________________"<<endl;
    revStack(s);
//Printing the reverse stack
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }


    return 0;
}
