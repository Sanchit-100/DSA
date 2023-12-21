//STL SORT AND COMPARATORS
#include<iostream>
#include<algorithm>
using namespace std;


bool compare(int a,int b){
    return a>b;
}
int main(){
    int a[]={1,2,7,3,5};
    sort(a,a+5,compare);
    
    for(int i=0;i<5;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}