//Reverse a Stack by using one more Stack

#include<iostream>
#include<stack>

using namespace std;


void viewStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

void revStack(stack<int> &s){
    
    stack<int> s2;
    s2=s;
    //finding the number of elements 
    
    int counter=0;
    while(!s2.empty()){
        counter++;
        s2.pop();
    }
    
    
    for(int i=0;i<counter-1;i++){
        int temp=s.top();
        s.pop();
        
        for(int j=0;j<counter-i-1;j++){
            int x=s.top();
            s2.push(x);
            s.pop();
        }
        
        s.push(temp);
        
        
        // cout<<"**********"<<endl;
        // viewStack(s);
        
        for(int y=0;y<counter-i-1;y++){
            int x=s2.top();
            s.push(x);
            s2.pop();
        }
        
    }
    
}

int main(){
    stack<int> s;
    
    for(int i=0;i<6;i++){
        s.push(i);
    }
    
    revStack(s);
    viewStack(s);

    return 0;
}