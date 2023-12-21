#include<iostream>
#include<algorithm>
using namespace std;


int main(){

    int n;
    cin>>n;

    int* black = new int[n];
    int* white = new int[n];

    cout<<"Enter black positions: "<<endl;
    for(int i=0;i<n;i++){
        cin>>black[i];
    }

    cout<<"Enter white positions: "<<endl;
    for(int i=0;i<n;i++){
        cin>>white[i];
    }

    sort(black,black+n);
    sort(white,white+n);

    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(black[i]-white[i]);
    }

    cout<<"Min length of wire is: "<<ans<<endl;



    return 0;
}