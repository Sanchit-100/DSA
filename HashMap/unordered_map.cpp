#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> mark_list;

    mark_list.insert(make_pair("John",100));
    mark_list.insert(make_pair("Claire",90));
    
    pair<string,int> p;
    p.first="Jim";
    p.second=50;
    mark_list.insert(p);


    //it can be noted that the system stores elements not in any sorted order
    //Unlike in <map>, where it sorts the keys acc to lexicographical order

    //for-each loop
    //for(i in arr)-- counterpart of python
    for(auto it:mark_list){
        cout<<it.first<<"-> "<<it.second<<endl;
    }

    //using the direct access operator []
    mark_list["Sanchit"]=200;
    mark_list["John"]-=20;
    mark_list.erase("Jim");

    cout<<endl;
    for(auto it:mark_list){
        cout<<it.first<<"-> "<<it.second<<endl;
    }
    return 0;
}