//You are given n teams in a cmpetition and you 
//have their preferred standings

//eg-
//noobz-1
//winnerz-1
//hello-3

//You need to find out the minimum badness possible
//badness=|preferred-current|

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


int main(){
    int n;
    cin>>n;

    //here we are defining teams as numbers(indices)
    //the array stores the preffered rank
    //the value at 2nd index denotes the preferred rank of the 2nd team
    int rank_no;
    string name;
    int* rank=new int[n];


    for(int i=0;i<n;i++){
        cin>>name>>rank_no;
        rank[i]=rank_no;
    }

    //This takes NlogN time
    //Most optimised approach for this problem is O(N)
    //using counting sort

    
    sort(rank,rank+n);
    int badness=0;

    for(int i=0;i<n;i++){
        badness+=abs(rank[i]-(i+1));        
    }

    cout<<"Badness: "<<badness<<endl;


    return 0;
}