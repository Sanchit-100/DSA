#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int number_activity(vector<pair<int,int>> v){

    int s=0;
    int min_end=1000;
    int number=0;
    while(!v.empty()){
        int n=v.size();

        //finding the earliest end time of an activity
        for(int i=0;i<n;i++){
            if(v[i].second<min_end){
                min_end=v[i].second;
            }
        }

        number++;
        //we did that activity

        s=min_end;
        //s denotes the current time
        // after doing the current activity, the time now is min_end

        //array of indices which have to be erased
        int arr[6];
        for(int i=0;i<6;i++){
            arr[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(v[i].first<s){
                arr[i]=i;
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]!=-1){
                v.erase(v.begin()+i);
            }
        }

    }

    return number;
    
}

int main(){

    vector<pair<int,int>> activity;
    //the first part is start time
    // second id the end time

    //one element of vector denotes one activity

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        activity.push_back(make_pair(s,e));
    }

    cout<<number_activity(activity)<<endl;


    return 0;
}