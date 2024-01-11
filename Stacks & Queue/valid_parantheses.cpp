#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool valid_Para(string s){

    int flag=0;
    int len=s.length();
    stack<char> stk;

    for(int i=0;i<len;i++){
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') stk.push(s[i]);

        else if(!stk.empty()){
            if(stk.top()=='(' && s[i]==')') stk.pop();
            else if(stk.top()=='[' && s[i]==']') stk.pop();
            else if(stk.top()=='{' && s[i]=='}') stk.pop();
            
            else{
                flag=1;
                break;
            }
        }

        else{
            flag=1;
            break;
        }
    }

    if(stk.empty() && flag==0){
        return true;
    }
    else return false;

}
int main(){

    string str;
    cin>>str;
    cout<<valid_Para(str)<<endl;

    return 0;
}