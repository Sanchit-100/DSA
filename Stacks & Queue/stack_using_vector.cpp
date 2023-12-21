//Stack implementation using vector

#include<iostream>
#include<vector>

using namespace std;

class Stack{
  private:
    vector<int> v;
    
  public:
    void push(int data){
        v.push_back(data);
    }
    
    bool isEmpty(){
        return v.size()==0;
    }
    
    void pop(){
        if(!isEmpty()){
            v.pop_back();
        }
        
        else{
            cout<<"Underflow"<<endl;
        }
            
    }
    
    int top(){
        return v[v.size()-1];
    }

};
int main(){
    
    Stack s;
    for (int i=1;i<7;i++){
        s.push(i*i);
    }
    
    //printing the elements of the stack using pop
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    
    s.pop();
    
    return 0;
}

