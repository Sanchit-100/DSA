#include<iostream>
using namespace std;

//O(N^2) time complexity
//Wherever you get "pi", in the input str,
//you have to replace 3.14

void replacePi(int i, char a[]){
    //here i is the current idx on which we are in the array
    int j=i;
    if((a[i]=='\0') || (a[i+1]=='\0')){
        return;
    }

    else if(a[i]=='p' && a[i+1]=='i'){
        while(a[j]!='\0'){
            j++;
        }
        //moving j to the end of the array

        while(j>=i+2){
            a[j+2]=a[j];
            j--;
        }
        //moving all the characters two indices ahead

        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';

        replacePi(i+4,a);
    }

    else replacePi(i+1,a);


}
int main(){

    char a[1000];

    cin>>a;
    //Taking input of string as a character array

    replacePi(0,a);
    cout<<a<<endl;

    return 0;
}