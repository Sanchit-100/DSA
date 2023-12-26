#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<vector<int>> v;
    for(int i=0;i<3;i++){
        vector<int> v1={0};
        v.push_back(v1);
    }

    cout<<v[2][0]<<endl;

}



