#include<iostream>
#include<stack>
using namespace std;


class queue{
    private:
        stack<int> s1;
        stack<int> s2;

    public:
        void push(int n){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }

            s2.push(n);
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        void pop(){
            if(s2.empty()){
                cout<<"Underflow"<<endl;
            }
            else s2.pop();
        }

        int front(){
            if(s2.empty()) cout<<"Nothing in queue"<<endl;
            else return s2.top();
        }

        bool empty(){
            if(s1.empty() and s2.empty()) return 1;
            else return 0;
        }
};


int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    cout<<"Empty? "<<q.empty()<<endl;
    q.pop();
    q.pop();

    cout<<"Empty? "<<q.empty()<<endl;

    q.pop();
    q.front();

}