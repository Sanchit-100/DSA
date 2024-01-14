#include<iostream>
using namespace std;

int main(){
    int* arr=new int[256];
    arr ['a']=13;
    arr['b']=12;
    for(int i=0;i<256;i++){
        arr[i]=0;
    }

    cout<<arr['a']<<endl;
    cout<<arr[97]<<endl;
    cout<<arr[98]<<endl;
    // cout<<arr[16]<<endl;


    return 0;
}