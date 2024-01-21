#include<iostream>
#include<string.h>
using namespace std;



string makeGood(string s) {
    string prev=s;
    string new_str="";
    
    int i=0;
    for(;i<prev.length()-1;){

        char curr=s[i];
        char next=s[i+1];
        if(abs(int(curr)-int(next))==32){
            i+=2;
            
        }
        else{
            new_str+=curr;
            i++;
        }

    }
    if(i<prev.length()){
        new_str+=prev[prev.length()-1];
    }
    

    if(prev==new_str){
        return new_str;
    }
    else return makeGood(new_str);
}

int main(){
    string s="abBAcC";
    cout<<makeGood(s)<<endl;


    return 0;
}
