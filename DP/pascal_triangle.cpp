#include<iostream>
#include<vector>
using namespace std;

int sumOfPrev(vector<vector<int>> v,int i, int j){
    //base case
    if(j==0) return 1;
    if(i==0) return 1;
    if(i==j) return 1;


    //lookup case
    return v[i-1][j-1]+v[i-1][j];

}

vector<vector<int>> generate(int n){
    vector<vector<int>> v;

    for(int i=0;i<n;i++){
        vector<int> v1={0};
        v.push_back(v1);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            v[i].push_back(0);
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            v[i][j]=sumOfPrev(v,i, j);
        }
    }

    return v;

}


int main(){
    int numRows;
    cin>>numRows;

    vector<vector<int>> v = generate(numRows);

    for(int i=0;i<numRows;i++){
        for(int j=0;j<i+1;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}