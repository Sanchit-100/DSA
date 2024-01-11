#include<iostream>
#include<string>
#include<stack>


using namespace std;

bool isBalanced(string str){
    stack<int> stk;

    int flag=0;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(') stk.push(i);

        else if(str[i]==')'){
            if(stk.empty()){
                flag=1;
                break;
            }
            else stk.pop();
        }
    }

    if(stk.empty() && flag==0) return 1;
    else return 0;


}

int main(){
    string str;
    cin>>str;
    cout<<isBalanced(str)<<endl;

    return 0;
}